#include "holoidea.h"
#include "ui_holoidea.h"
#include "opencvmethods.h"

#include <QtWidgets>
#include<QFileDialog>
#include<QtCore>
#include<QtGui>
#include<QGraphicsItem>
#include<QMenu>

#include <iostream>

// Default zoom factors
#define         keyboardZoomFactor   1.25
#define         zoomFactor           1.15
#define         zoomCtrlFactor       1.01



HoloIdea::HoloIdea(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HoloIdea)
{
    ui->setupUi(this);

    initMenuBar();
    initTabs();

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    const QString message = tr("Info: Ready");
    statusBar()->showMessage(message);
    imageFile = new QFile();
}

HoloIdea::~HoloIdea()
{
    if(imageFile->isOpen())
        imageFile->close();
    delete imageFile;
    delete saveAct;
    delete saveAsAct;
    delete zoomInAct;
    delete zoomOutAct;
    delete ui;
}



static void initializeImageFileDialog(QFileDialog &dialog, QFileDialog::AcceptMode acceptMode)
{
    static bool firstDialog = true;

    if (firstDialog) {
        firstDialog = false;
        const QStringList picturesLocations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
        dialog.setDirectory(picturesLocations.isEmpty() ? QDir::currentPath() : picturesLocations.last());
    }

    QStringList mimeTypeFilters;
    const QByteArrayList supportedMimeTypes = acceptMode == QFileDialog::AcceptOpen
        ? QImageReader::supportedMimeTypes() : QImageWriter::supportedMimeTypes();
    foreach (const QByteArray &mimeTypeName, supportedMimeTypes)
        mimeTypeFilters.append(mimeTypeName);
    mimeTypeFilters.sort();
    dialog.setMimeTypeFilters(mimeTypeFilters);
    dialog.selectMimeTypeFilter("image/bmp");
    if (acceptMode == QFileDialog::AcceptSave)
        dialog.setDefaultSuffix("bmp");
}



void HoloIdea::open() {
    QFileDialog dialog(this, tr("Open File"));
    initializeImageFileDialog(dialog, QFileDialog::AcceptOpen);

    while (dialog.exec() == QDialog::Accepted && !loadFile(dialog.selectedFiles().first())) {}
}

void HoloIdea::saveAs() {
    QFileDialog dialog(this, tr("Save File As"));
    initializeImageFileDialog(dialog, QFileDialog::AcceptSave);

    while (dialog.exec() == QDialog::Accepted && !saveFile(dialog.selectedFiles().first())) {}
}

void HoloIdea::save() {
    if (!saveFile(filePath)) {
        const QString message_error = tr("Error: Saving a file failed!");
        statusBar()->showMessage(message_error);
    }
}

void HoloIdea::zoomIn()
{
    ui->graphicsView->scale(keyboardZoomFactor, keyboardZoomFactor);
}

void HoloIdea::zoomOut()
{
    ui->graphicsView->scale(1.0 / keyboardZoomFactor, 1.0 / keyboardZoomFactor);
}

void HoloIdea::setImage(const QImage &newImage)
{
    image = newImage;

    scene->clear();
    QGraphicsItem *pixMapItem = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(pixMapItem);

    updateActions();
    updateHistogram(tmpMat);

}

bool HoloIdea::loadFile(const QString &fileName)
{
    if(imageFile->isOpen())
        imageFile->close();
    imageFile = new QFile(fileName);
    if ( imageFile->open(QIODevice::ReadWrite) ) {
        filePath = fileName;
        cvImage = cv::imread(fileName.toStdString());        // open image
        cv::Mat imgGrayScale;           // grayscale image
        cv::cvtColor(cvImage, imgGrayScale, CV_BGR2GRAY);               // convert to grayscale
        cvImage = imgGrayScale;

        tmpMat = Mat::zeros(cvImage.size(), cvImage.type());
        cvImage.copyTo(tmpMat);


        QImage newImage = convertOpenCVMatToQtQImage(cvImage);

        resetProperties();

        if (newImage.isNull()) {
            const QString message = tr("Error: No such file or directory!");
            statusBar()->showMessage(message);
           return false;
        }


        setImage(newImage);

    const QString message = tr("Opened \"%1\", %2x%3")
        .arg(QDir::toNativeSeparators(fileName)).arg(image.width()).arg(image.height());
    statusBar()->showMessage(message);

    QFileInfo new_file_info(fileName);
    const QString info = tr("Info:\nFile path: \"%1\"\nSize: %2x%3\nDepth: %4 \nFormat: %5")
                             .arg(QDir::toNativeSeparators(fileName)).arg(image.width()).arg(image.height())
                             .arg(image.depth()).arg(new_file_info.completeSuffix().toUpper());

    ui->infoLabel->setText(info);
    return true;
    }
    else {
        const QString error_message = tr("Error: Could not open file to script!");
        statusBar()->showMessage(error_message);
        return false;
    }
}

void HoloIdea::saveScript(const QString &fileName) {
    QString scriptFileName = fileName;
    int last_dot = scriptFileName.lastIndexOf('.');
    int left_length = scriptFileName.length() - last_dot;
    scriptFileName.remove(last_dot,left_length);
    QFile file(scriptFileName + ".SCRIPT");
    if ( file.open(QIODevice::ReadWrite) ) {
        QTextStream stream( &file );
        stream << "// Create matrix " << scrpitMatrixSize << "\n";
        stream << "(1) SetLambda(" << lambda << ")" << "\n";
        stream << "(1) SetSampling(" << sampling << ")" << "\n";
        stream << "(1) propagation_start=" << propFrom << "\n";
        stream << "(1) propagation_end=" << propTo << "\n";
        stream << "(1) propagation_step=" << propStep << "\n";
        stream << "(1) output_name=" << scriptOutput << "\n";
        stream << "(1) CreatePlaneWave(1;0;0;0)" << "\n";
        stream << "(1) Import(0;0;0;0;0;0;2;0;0;" << fileName << ";0)" << "\n";
        stream << "(1) PropagationOnAxis(0;0;a;0;0;0;0;1;0)" << "\n";
        stream << "(1) SaveAs(" << "nazwa_pliku_wyjsciowego" << "_+propagation_start" << "\n";
        stream << "(1) Export(1," << "size" << ";" << "size" << ";output_name" << "_+propagation_start"<< ";0;0;0;0;0;255;1)" << "\n";
        stream << "(1) tmp_propagation=propagation_start"<< "\n";
        stream << "(1) Label: Loop" << "\n";
        stream << "(1) PropagationOnAxis(0;0;propagation_step;0;0;0;0;1;0)" << "\n";
        stream << "(1) tmp_propagation=tmp_propagation+propagation_step"<< "\n";
        stream << "(1) SaveAs(nazwa_pliku_wyjsciowego" << "_+tmp_propagation)" <<"\n";
        stream << "(1) Export(1," << "size" << ";" << "size" << "output_name_AMP" << "_+tmp_propagation" << ";0;0;0;0;0;255;1)" << "\n";
        stream << "(1) tmp_propagation>propagation_end"<< " ? GotoLabel: Loop" << "\n";
        file.flush();
        file.close();
    } else {
        const QString error_message = tr("Error: Could not open file to script!");
        statusBar()->showMessage(error_message);
    }
}

bool HoloIdea::saveFile(const QString &fileName)
{
    /*vector<int> compression_params;
    compression_params.push_back(CV_IMWRITE_PXM_BINARY);
    compression_params.push_back(1);*/

    /*cvImage = changeContrast(cvImage, contrast);
    cvImage = changeBrightness(cvImage, brightness);
    cvImage = gammaCorrection(cvImage, gamma);*/

    tmpMat.copyTo(cvImage);

    const QString message = tr("Processing ... Please wait");
    statusBar()->showMessage(message);

    if (pow(2,(ui->outputSizeComboBox->currentIndex()))*1024 > image.width() && pow(2,(ui->outputSizeComboBox->currentIndex()))*1024 > image.height())
        fillWithBlack(pow(2,(ui->outputSizeComboBox->currentIndex()))*1024);
    else {
        const QString message_error = tr("Error! Choosen output size is smaller than original size (%1x%1 < %2x%3)").arg(pow(2,(ui->outputSizeComboBox->currentIndex()))*1024).arg(image.width()).arg(image.height());
        statusBar()->showMessage(message_error);
        return false;
    }
    cv::imwrite(fileName.toStdString(),cvImage);        // save image
    const QString message2 = tr("Wrote \"%1\"").arg(QDir::toNativeSeparators(fileName));
    statusBar()->showMessage(message2);
    if(ui->generateScriptCheckBox->checkState())
        saveScript(fileName);
    return true;
}

void HoloIdea::about()
{
    QMessageBox::about(this, tr("About Holo Idea"),
            tr("<p>The <b>Holo Idea</b> is application to edit images."
               " Main function of this application is to improve the contrast of the digital hologram images.</p>"
               "<p>Author: Tomasz Kawka</p> "
               "<p>mail: kawka_tomasz@wp.pl</p>"));
}

void HoloIdea::resetProperties() {
    brightness = 0;
    contrast = 1.0;
    gamma = 1.0;
    ui->brightnessSpinner->setValue(brightness);
    ui->contrastSpinner->setValue(contrast);
    ui->gammaSpinner->setValue(gamma);
}

void HoloIdea::initMenuBar() {

    QMenu *fileMenu = ui->menuBar->addMenu(tr("&File"));

    QAction *openAct = fileMenu->addAction(tr("&Open..."), this, &HoloIdea::open);
    openAct->setShortcut(QKeySequence::Open);

    saveAct = fileMenu->addAction(tr("&Save"), this, &HoloIdea::save);
    saveAct->setEnabled(false);
    saveAct->setShortcut(QKeySequence::Save);

    saveAsAct = fileMenu->addAction(tr("&Save As..."), this, &HoloIdea::saveAs);
    saveAsAct->setEnabled(false);
    saveAsAct->setShortcut(QKeySequence::SaveAs);

    fileMenu->addSeparator();

    QAction *exitAct = fileMenu->addAction(tr("E&xit"), this, &QWidget::close);
    exitAct->setShortcut(tr("Ctrl+Q"));

    QMenu *viewMenu = menuBar()->addMenu(tr("&View"));

    zoomInAct = viewMenu->addAction(tr("Zoom &In (25%)"), this, &HoloIdea::zoomIn);
    zoomInAct->setShortcut(QKeySequence::ZoomIn);
    zoomInAct->setEnabled(false);

    zoomOutAct = viewMenu->addAction(tr("Zoom &Out (25%)"), this, &HoloIdea::zoomOut);
    zoomOutAct->setShortcut(QKeySequence::ZoomOut);
    zoomOutAct->setEnabled(false);


    QMenu *helpMenu = ui->menuBar->addMenu(tr("&Help"));
    helpMenu->addAction(tr("&About"), this, &HoloIdea::about);
}

void HoloIdea::updateActions()
{
    saveAct->setEnabled(!image.isNull());
    saveAsAct->setEnabled(!image.isNull());
    ui->brightnessSlider->setEnabled(!image.isNull());
    ui->brightnessSpinner->setEnabled(!image.isNull());
    ui->contrastSlider->setEnabled(!image.isNull());
    ui->contrastSpinner->setEnabled(!image.isNull());
    ui->gammaSlider->setEnabled(!image.isNull());
    ui->gammaSpinner->setEnabled(!image.isNull());
    ui->equlizeHistrogramButton->setEnabled(!image.isNull());
    zoomInAct->setEnabled(!image.isNull());
    zoomOutAct->setEnabled(!image.isNull());
}

void HoloIdea::updateImage(double tmpgamma, int tmpbrightness, double tmpcontrast) {
    tmpMat = fastCompleteCorrection(cvImage, tmpgamma, tmpbrightness, tmpcontrast);
    QImage newImage = convertOpenCVMatToQtQImage(tmpMat);
    setImage(newImage);
}

void HoloIdea::updateHistogram(Mat &mat) {
    ui->histogramLabel->clear();
    histImage = calculateHistogram(mat);
    QImage qHistImage = convertOpenCVMatToQtQImage(histImage);
    ui->histogramLabel->setPixmap(QPixmap::fromImage(qHistImage));
}

QImage HoloIdea::convertOpenCVMatToQtQImage(cv::Mat &mat) {
    if(mat.channels() == 1) {                   // if grayscale image
        return QImage((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);     // declare and return a QImage
    } else if(mat.channels() == 3) {            // if 3 channel color image
        cv::cvtColor(mat, mat, CV_BGR2RGB);     // invert BGR to RGB
        return QImage((uchar*)mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);       // declare and return a QImage
    } else {
        qDebug() << "in convertOpenCVMatToQtQImage, image was not 1 channel or 3 channel, should never get here";
    }
    return QImage();        // return a blank QImage if the above did not work
}


#ifndef QT_NO_WHEELEVENT

// Call when there is a scroll event (zoom in or zoom out)
void HoloIdea::wheelEvent(QWheelEvent *event) {
    // When zooming, the view stay centered over the mouse
    ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

    double factor = (event->modifiers() & Qt::ControlModifier) ? zoomCtrlFactor : zoomFactor;
    if(event->delta() > 0)
        // Zoom in
        ui->graphicsView->scale(factor, factor);
    else
        // Zooming out
        ui->graphicsView->scale(1.0 / factor, 1.0 / factor);

    // The event is processed
    event->accept();
}

#endif

void HoloIdea::on_actionOpen_triggered()
{
    QString strFileName = QFileDialog::getOpenFileName();       // bring up open file dialog

    if(strFileName == "") {                                     // if file was not chosen
        const QString message = tr("Error: File was not chosen!");
        statusBar()->showMessage(message);
        return;                                                 // and exit function
    }

    cv::Mat imgOriginal;            // input image
    cv::Mat imgOutput;              // output image

    imgOriginal = cv::imread(strFileName.toStdString());        // open image

    if (imgOriginal.empty()) {									// if unable to open image
        const QString message = tr("Error: Image not read from file!");
        statusBar()->showMessage(message);
        return;                                                             // and exit function
    }

    cv::cvtColor(imgOriginal, imgOutput, CV_BGR2GRAY);               // convert to grayscale

    QImage qimgOutput = convertOpenCVMatToQtQImage(imgOutput);


    QGraphicsItem *pixMapItem = new QGraphicsPixmapItem(QPixmap::fromImage(qimgOutput));
    scene->addItem(pixMapItem);
    delete pixMapItem;
}

void HoloIdea::fillWithBlack(int size) {
    cvImage = drawAnImageOverAnother(cvImage, size);
}

void HoloIdea::initTabs() {
    ui->brightnessSlider->setEnabled(false);
    ui->brightnessSpinner->setEnabled(false);
    ui->brightnessSlider->setRange(-200,200);
    ui->brightnessSpinner->setRange(-200,200);

    ui->contrastSlider->setEnabled(false);
    ui->contrastSpinner->setEnabled(false);

    ui->gammaSlider->setEnabled(false);
    ui->gammaSpinner->setEnabled(false);

    ui->equlizeHistrogramButton->setEnabled(false);

    ui->matrixSizeComboBox->addItem("1024x1024");
    ui->matrixSizeComboBox->addItem("2048x2048");
    ui->matrixSizeComboBox->addItem("4096x4096");
    ui->matrixSizeComboBox->addItem("8192x8192");
    ui->matrixSizeComboBox->addItem("16384x16384");

    ui->outputSizeComboBox->addItem("1024x1024");
    ui->outputSizeComboBox->addItem("2048x2048");
    ui->outputSizeComboBox->addItem("4096x4096");
    ui->outputSizeComboBox->addItem("8192x8192");
    ui->outputSizeComboBox->addItem("16384x16384");

    ui->matrixSizeComboBox->setEnabled(false);
    ui->wavelengthInput->setEnabled(false);
    ui->samplingInput->setEnabled(false);
    ui->propFromInput->setEnabled(false);
    ui->propToInput->setEnabled(false);
    ui->propStepInput->setEnabled(false);
    ui->scriptOutputName->setEnabled(false);
    ui->saveScriptDataButton->setEnabled(false);
}


void HoloIdea::on_contrastSlider_valueChanged(int value) {
    contrast = static_cast<double>(value/100.0);
    ui->contrastSpinner->setValue(contrast);
    updateImage(gamma, brightness, contrast);
}

void HoloIdea::on_contrastSpinner_valueChanged(double value) {
    int slider_value = round(value * 100.0);
    ui->contrastSlider->setValue(slider_value);
}

void HoloIdea::on_brightnessSlider_valueChanged(int value) {
    brightness = value;
    ui->brightnessSpinner->setValue(value);
     updateImage(gamma, brightness, contrast);
}

void HoloIdea::on_brightnessSpinner_valueChanged(int value) {
     ui->brightnessSlider->setValue(value);
}

void HoloIdea::on_gammaSlider_valueChanged(int value) {
    gamma = static_cast<double>(value/100.0);
    ui->gammaSpinner->setValue(gamma);
    updateImage(gamma, brightness, contrast);
}

void HoloIdea::on_gammaSpinner_valueChanged(double value) {
    int slider_value = round(value * 100.0);
    ui->gammaSlider->setValue(slider_value);
}

void HoloIdea::on_equlizeHistrogramButton_clicked() {
    tmpMat = equalizeHistogram(tmpMat);
    QImage newImage = convertOpenCVMatToQtQImage(tmpMat);
    if(!newImage.isNull())
        setImage(newImage);
}

void HoloIdea::on_generateScriptCheckBox_clicked(bool checked)
{
    if (checked) {
        ui->matrixSizeComboBox->setEnabled(true);
        ui->wavelengthInput->setEnabled(true);
        ui->samplingInput->setEnabled(true);
        ui->propFromInput->setEnabled(true);
        ui->propToInput->setEnabled(true);
        ui->propStepInput->setEnabled(true);
        ui->scriptOutputName->setEnabled(true);
        ui->saveScriptDataButton->setEnabled(true);
    }
    else {
        ui->matrixSizeComboBox->setEnabled(false);
        ui->wavelengthInput->setEnabled(false);
        ui->samplingInput->setEnabled(false);
        ui->propFromInput->setEnabled(false);
        ui->propToInput->setEnabled(false);
        ui->propStepInput->setEnabled(false);
        ui->scriptOutputName->setEnabled(false);
        ui->saveScriptDataButton->setEnabled(false);
    }
}

void HoloIdea::on_saveScriptDataButton_clicked()
{
    scrpitMatrixSize = ui->matrixSizeComboBox->currentText();
    lambda = ui->wavelengthInput->text();
    sampling = ui->samplingInput->text();
    propFrom = ui->propFromInput->text();
    propTo = ui->propToInput->text();
    propStep = ui->propStepInput->text();
    scriptOutput = ui->scriptOutputName->text();
    const QString message = tr("Info: Script data has been saved");
    statusBar()->showMessage(message);
}
