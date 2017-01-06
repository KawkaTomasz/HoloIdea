#ifndef HOLOIDEA_H
#define HOLOIDEA_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QWheelEvent>
#include <QtCore>
#include <QtGui>


#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

namespace Ui {
class HoloIdea;
}

class HoloIdea : public QMainWindow {
    Q_OBJECT

public:
    explicit HoloIdea(QWidget *parent = 0);
    ~HoloIdea();
    bool loadFile(const QString &);

protected:
    virtual void wheelEvent(QWheelEvent *event);

private slots:

    void open();

    void saveAs();

    void save();

    void zoomIn();

    void zoomOut();

    void about();

    void on_actionOpen_triggered();

    void on_contrastSlider_valueChanged(int value);

    void on_contrastSpinner_valueChanged(double arg1);

    void on_brightnessSlider_valueChanged(int value);

    void on_brightnessSpinner_valueChanged(int arg1);

    void on_gammaSlider_valueChanged(int value);

    void on_gammaSpinner_valueChanged(double arg1);

    void on_equlizeHistrogramButton_clicked();

    void on_generateScriptCheckBox_clicked(bool checked);

    void on_saveScriptDataButton_clicked();

private:
    bool saveFile(const QString &fileName);
    void saveScript(const QString &fileName);
    void setImage(const QImage &newImage);
    void initTabs();
    void initMenuBar();
    void updateActions();
    void updateImage(double tmpgamma, int tmpbrightness, double tmpcontrast);
    void updateHistogram(cv::Mat &mat);
    void resetProperties();
    void fillWithBlack(int size);

    Ui::HoloIdea *ui;
    QGraphicsScene *scene;
    cv::Mat cvImage;
    cv::Mat tmpMat;
    cv::Mat histImage;

    QImage HoloIdea::convertOpenCVMatToQtQImage(cv::Mat &mat);           // convert OpenCVMat to QtImage function

    QImage image;
    QAction *saveAct;
    QAction *saveAsAct;
    QAction *zoomInAct;
    QAction *zoomOutAct;

    QString filePath;
    QFile *imageFile;

    int brightness;
    double contrast;
    double gamma;

    // script inputs
    QString scrpitMatrixSize;
    QString lambda;
    QString sampling;
    QString propFrom;
    QString propTo;
    QString propStep;
    QString scriptOutput;
};

#endif // HOLOIDEA_H
