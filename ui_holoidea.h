/********************************************************************************
** Form generated from reading UI file 'holoidea.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOLOIDEA_H
#define UI_HOLOIDEA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HoloIdea
{
public:
    QAction *actionOpen;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QTabWidget *tabWidget;
    QWidget *General_Tab;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_11;
    QLabel *histogramLabel;
    QPushButton *equlizeHistrogramButton;
    QLabel *infoLabel;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_9;
    QComboBox *outputSizeComboBox;
    QLabel *brightnessLabel;
    QHBoxLayout *horizontalLayout_2;
    QSlider *brightnessSlider;
    QSpinBox *brightnessSpinner;
    QLabel *contrastLabel;
    QHBoxLayout *horizontalLayout_3;
    QSlider *contrastSlider;
    QDoubleSpinBox *contrastSpinner;
    QLabel *gammaLabel;
    QHBoxLayout *horizontalLayout_4;
    QSlider *gammaSlider;
    QDoubleSpinBox *gammaSpinner;
    QWidget *Script_Tab;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *generateScriptCheckBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QComboBox *matrixSizeComboBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QLineEdit *wavelengthInput;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    QLineEdit *samplingInput;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_4;
    QLineEdit *propFromInput;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_6;
    QLineEdit *propToInput;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_5;
    QLineEdit *propStepInput;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_8;
    QLineEdit *scriptOutputName;
    QPushButton *saveScriptDataButton;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *HoloIdea)
    {
        if (HoloIdea->objectName().isEmpty())
            HoloIdea->setObjectName(QStringLiteral("HoloIdea"));
        HoloIdea->resize(1109, 762);
        actionOpen = new QAction(HoloIdea);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        centralWidget = new QWidget(HoloIdea);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setMouseTracking(true);
        graphicsView->setAutoFillBackground(false);

        verticalLayout->addWidget(graphicsView);


        horizontalLayout->addLayout(verticalLayout);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setAutoFillBackground(true);
        General_Tab = new QWidget();
        General_Tab->setObjectName(QStringLiteral("General_Tab"));
        General_Tab->setAutoFillBackground(true);
        verticalLayout_2 = new QVBoxLayout(General_Tab);
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(20, 20, 20, 20);
        label_11 = new QLabel(General_Tab);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_11);

        histogramLabel = new QLabel(General_Tab);
        histogramLabel->setObjectName(QStringLiteral("histogramLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(histogramLabel->sizePolicy().hasHeightForWidth());
        histogramLabel->setSizePolicy(sizePolicy1);
        histogramLabel->setAutoFillBackground(false);
        histogramLabel->setFrameShape(QFrame::Box);
        histogramLabel->setScaledContents(true);
        histogramLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(histogramLabel);

        equlizeHistrogramButton = new QPushButton(General_Tab);
        equlizeHistrogramButton->setObjectName(QStringLiteral("equlizeHistrogramButton"));
        equlizeHistrogramButton->setEnabled(false);

        verticalLayout_2->addWidget(equlizeHistrogramButton);

        infoLabel = new QLabel(General_Tab);
        infoLabel->setObjectName(QStringLiteral("infoLabel"));
        QFont font;
        font.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font.setPointSize(8);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        infoLabel->setFont(font);
        infoLabel->setAutoFillBackground(true);
        infoLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        infoLabel->setWordWrap(true);

        verticalLayout_2->addWidget(infoLabel);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_9 = new QLabel(General_Tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        horizontalLayout_12->addWidget(label_9);

        outputSizeComboBox = new QComboBox(General_Tab);
        outputSizeComboBox->setObjectName(QStringLiteral("outputSizeComboBox"));

        horizontalLayout_12->addWidget(outputSizeComboBox);


        verticalLayout_2->addLayout(horizontalLayout_12);

        brightnessLabel = new QLabel(General_Tab);
        brightnessLabel->setObjectName(QStringLiteral("brightnessLabel"));
        brightnessLabel->setEnabled(true);
        QFont font1;
        font1.setItalic(false);
        brightnessLabel->setFont(font1);
        brightnessLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(brightnessLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        brightnessSlider = new QSlider(General_Tab);
        brightnessSlider->setObjectName(QStringLiteral("brightnessSlider"));
        brightnessSlider->setEnabled(false);
        brightnessSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(brightnessSlider);

        brightnessSpinner = new QSpinBox(General_Tab);
        brightnessSpinner->setObjectName(QStringLiteral("brightnessSpinner"));
        brightnessSpinner->setEnabled(false);

        horizontalLayout_2->addWidget(brightnessSpinner);


        verticalLayout_2->addLayout(horizontalLayout_2);

        contrastLabel = new QLabel(General_Tab);
        contrastLabel->setObjectName(QStringLiteral("contrastLabel"));
        contrastLabel->setFont(font1);
        contrastLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(contrastLabel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        contrastSlider = new QSlider(General_Tab);
        contrastSlider->setObjectName(QStringLiteral("contrastSlider"));
        contrastSlider->setEnabled(false);
        contrastSlider->setMinimum(10);
        contrastSlider->setMaximum(200);
        contrastSlider->setSingleStep(1);
        contrastSlider->setPageStep(10);
        contrastSlider->setValue(100);
        contrastSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(contrastSlider);

        contrastSpinner = new QDoubleSpinBox(General_Tab);
        contrastSpinner->setObjectName(QStringLiteral("contrastSpinner"));
        contrastSpinner->setEnabled(false);
        contrastSpinner->setMinimum(0.1);
        contrastSpinner->setMaximum(2);
        contrastSpinner->setSingleStep(0.01);
        contrastSpinner->setValue(1);

        horizontalLayout_3->addWidget(contrastSpinner);


        verticalLayout_2->addLayout(horizontalLayout_3);

        gammaLabel = new QLabel(General_Tab);
        gammaLabel->setObjectName(QStringLiteral("gammaLabel"));
        gammaLabel->setFont(font1);
        gammaLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(gammaLabel);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        gammaSlider = new QSlider(General_Tab);
        gammaSlider->setObjectName(QStringLiteral("gammaSlider"));
        gammaSlider->setEnabled(false);
        gammaSlider->setMinimum(10);
        gammaSlider->setMaximum(300);
        gammaSlider->setPageStep(1);
        gammaSlider->setValue(100);
        gammaSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(gammaSlider);

        gammaSpinner = new QDoubleSpinBox(General_Tab);
        gammaSpinner->setObjectName(QStringLiteral("gammaSpinner"));
        gammaSpinner->setEnabled(false);
        gammaSpinner->setMinimum(0.1);
        gammaSpinner->setMaximum(3);
        gammaSpinner->setSingleStep(0.01);
        gammaSpinner->setValue(1);

        horizontalLayout_4->addWidget(gammaSpinner);


        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalLayout_2->setStretch(1, 5);
        verticalLayout_2->setStretch(2, 1);
        verticalLayout_2->setStretch(3, 3);
        verticalLayout_2->setStretch(4, 1);
        tabWidget->addTab(General_Tab, QString());
        Script_Tab = new QWidget();
        Script_Tab->setObjectName(QStringLiteral("Script_Tab"));
        verticalLayout_3 = new QVBoxLayout(Script_Tab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        generateScriptCheckBox = new QCheckBox(Script_Tab);
        generateScriptCheckBox->setObjectName(QStringLiteral("generateScriptCheckBox"));

        verticalLayout_3->addWidget(generateScriptCheckBox);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_7 = new QLabel(Script_Tab);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_5->addWidget(label_7);

        matrixSizeComboBox = new QComboBox(Script_Tab);
        matrixSizeComboBox->setObjectName(QStringLiteral("matrixSizeComboBox"));

        horizontalLayout_5->addWidget(matrixSizeComboBox);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 1);

        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label = new QLabel(Script_Tab);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_6->addWidget(label);

        wavelengthInput = new QLineEdit(Script_Tab);
        wavelengthInput->setObjectName(QStringLiteral("wavelengthInput"));

        horizontalLayout_6->addWidget(wavelengthInput);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 1);

        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_2 = new QLabel(Script_Tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_7->addWidget(label_2);

        samplingInput = new QLineEdit(Script_Tab);
        samplingInput->setObjectName(QStringLiteral("samplingInput"));

        horizontalLayout_7->addWidget(samplingInput);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 1);

        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);

        label_4 = new QLabel(Script_Tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setWordWrap(true);

        horizontalLayout_8->addWidget(label_4);

        propFromInput = new QLineEdit(Script_Tab);
        propFromInput->setObjectName(QStringLiteral("propFromInput"));

        horizontalLayout_8->addWidget(propFromInput);

        horizontalLayout_8->setStretch(0, 1);
        horizontalLayout_8->setStretch(1, 3);
        horizontalLayout_8->setStretch(2, 6);

        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_2);

        label_6 = new QLabel(Script_Tab);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_10->addWidget(label_6);

        propToInput = new QLineEdit(Script_Tab);
        propToInput->setObjectName(QStringLiteral("propToInput"));

        horizontalLayout_10->addWidget(propToInput);

        horizontalLayout_10->setStretch(0, 3);
        horizontalLayout_10->setStretch(1, 1);
        horizontalLayout_10->setStretch(2, 6);

        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        label_5 = new QLabel(Script_Tab);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_9->addWidget(label_5);

        propStepInput = new QLineEdit(Script_Tab);
        propStepInput->setObjectName(QStringLiteral("propStepInput"));

        horizontalLayout_9->addWidget(propStepInput);

        horizontalLayout_9->setStretch(0, 3);
        horizontalLayout_9->setStretch(1, 1);
        horizontalLayout_9->setStretch(2, 6);

        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_8 = new QLabel(Script_Tab);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_11->addWidget(label_8);

        scriptOutputName = new QLineEdit(Script_Tab);
        scriptOutputName->setObjectName(QStringLiteral("scriptOutputName"));

        horizontalLayout_11->addWidget(scriptOutputName);

        horizontalLayout_11->setStretch(0, 1);
        horizontalLayout_11->setStretch(1, 1);

        verticalLayout_3->addLayout(horizontalLayout_11);

        saveScriptDataButton = new QPushButton(Script_Tab);
        saveScriptDataButton->setObjectName(QStringLiteral("saveScriptDataButton"));

        verticalLayout_3->addWidget(saveScriptDataButton);

        tabWidget->addTab(Script_Tab, QString());
        generateScriptCheckBox->raise();
        saveScriptDataButton->raise();
        propFromInput->raise();
        label_4->raise();

        horizontalLayout->addWidget(tabWidget);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 1);
        HoloIdea->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(HoloIdea);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1109, 21));
        HoloIdea->setMenuBar(menuBar);
        statusBar = new QStatusBar(HoloIdea);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        HoloIdea->setStatusBar(statusBar);

        retranslateUi(HoloIdea);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(HoloIdea);
    } // setupUi

    void retranslateUi(QMainWindow *HoloIdea)
    {
        HoloIdea->setWindowTitle(QApplication::translate("HoloIdea", "HoloIdea", 0));
        actionOpen->setText(QApplication::translate("HoloIdea", "Open", 0));
        label_11->setText(QApplication::translate("HoloIdea", "Histogram", 0));
        histogramLabel->setText(QString());
        equlizeHistrogramButton->setText(QApplication::translate("HoloIdea", "Equalize Histogram", 0));
        infoLabel->setText(QString());
        label_9->setText(QApplication::translate("HoloIdea", "Output size (0-filled around):", 0));
        brightnessLabel->setText(QApplication::translate("HoloIdea", "Brightness", 0));
        contrastLabel->setText(QApplication::translate("HoloIdea", "Contrast", 0));
        gammaLabel->setText(QApplication::translate("HoloIdea", "Gamma", 0));
        tabWidget->setTabText(tabWidget->indexOf(General_Tab), QApplication::translate("HoloIdea", "General", 0));
        generateScriptCheckBox->setText(QApplication::translate("HoloIdea", "Generate Script to LightSword", 0));
        label_7->setText(QApplication::translate("HoloIdea", "Matrix size:", 0));
        label->setText(QApplication::translate("HoloIdea", "Wavelength [\302\265m]:", 0));
        wavelengthInput->setText(QApplication::translate("HoloIdea", "0", 0));
        label_2->setText(QApplication::translate("HoloIdea", "Sampling [\302\265m]:", 0));
        samplingInput->setText(QApplication::translate("HoloIdea", "0", 0));
        label_4->setText(QApplication::translate("HoloIdea", "Propagation from:", 0));
        propFromInput->setText(QApplication::translate("HoloIdea", "0", 0));
        label_6->setText(QApplication::translate("HoloIdea", "to:", 0));
        propToInput->setText(QApplication::translate("HoloIdea", "0", 0));
        label_5->setText(QApplication::translate("HoloIdea", "step:", 0));
        propStepInput->setText(QApplication::translate("HoloIdea", "0", 0));
        label_8->setText(QApplication::translate("HoloIdea", "Name of the LS result:", 0));
        scriptOutputName->setText(QApplication::translate("HoloIdea", "output", 0));
        saveScriptDataButton->setText(QApplication::translate("HoloIdea", "Save", 0));
        tabWidget->setTabText(tabWidget->indexOf(Script_Tab), QApplication::translate("HoloIdea", "Script Creator", 0));
    } // retranslateUi

};

namespace Ui {
    class HoloIdea: public Ui_HoloIdea {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOLOIDEA_H
