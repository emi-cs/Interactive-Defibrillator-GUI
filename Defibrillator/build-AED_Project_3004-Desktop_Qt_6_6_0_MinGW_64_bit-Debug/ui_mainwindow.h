/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLabel *consciousLabel;
    QLabel *label_3;
    QLabel *emergencyLabel;
    QLabel *label_4;
    QLabel *airwayLabel;
    QLabel *label_5;
    QLabel *breathLabel;
    QLabel *label_6;
    QLabel *padLabel;
    QLabel *label_19;
    QLabel *heartAnalysisLabel;
    QLabel *label_7;
    QPushButton *ShockButton;
    QLabel *label_9;
    QLabel *cprLabel;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QVBoxLayout *verticalLayout;
    QCheckBox *ConsCheck;
    QCheckBox *BreathCheck;
    QComboBox *PadBox;
    QComboBox *HeartRhythm;
    QCheckBox *ContactCheck;
    QComboBox *CompressionCheck;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_12;
    QLabel *label_11;
    QLabel *label_13;
    QLabel *label_10;
    QLabel *label_15;
    QLabel *label_14;
    QLabel *label_17;
    QLabel *label;
    QTextBrowser *ConsoleLogs;
    QLabel *Picture;
    QLabel *label_20;
    QLabel *batteryIcon;
    QLabel *batteryLevel;
    QFrame *line;
    QLabel *label_21;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_16;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *ConsButton;
    QPushButton *EmergencyButton;
    QPushButton *AirButton;
    QPushButton *BreathButton;
    QPushButton *Place_Pad;
    QPushButton *Remove_Pad;
    QPushButton *changeBattery;
    QLabel *label_8;
    QPushButton *powerButton;
    QFrame *line_2;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *Display;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(876, 657);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(500, 130, 291, 281));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        consciousLabel = new QLabel(formLayoutWidget);
        consciousLabel->setObjectName("consciousLabel");

        formLayout->setWidget(1, QFormLayout::FieldRole, consciousLabel);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        emergencyLabel = new QLabel(formLayoutWidget);
        emergencyLabel->setObjectName("emergencyLabel");

        formLayout->setWidget(2, QFormLayout::FieldRole, emergencyLabel);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        airwayLabel = new QLabel(formLayoutWidget);
        airwayLabel->setObjectName("airwayLabel");

        formLayout->setWidget(3, QFormLayout::FieldRole, airwayLabel);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        breathLabel = new QLabel(formLayoutWidget);
        breathLabel->setObjectName("breathLabel");

        formLayout->setWidget(4, QFormLayout::FieldRole, breathLabel);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName("label_6");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        padLabel = new QLabel(formLayoutWidget);
        padLabel->setObjectName("padLabel");

        formLayout->setWidget(5, QFormLayout::FieldRole, padLabel);

        label_19 = new QLabel(formLayoutWidget);
        label_19->setObjectName("label_19");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_19);

        heartAnalysisLabel = new QLabel(formLayoutWidget);
        heartAnalysisLabel->setObjectName("heartAnalysisLabel");

        formLayout->setWidget(6, QFormLayout::FieldRole, heartAnalysisLabel);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName("label_7");

        formLayout->setWidget(7, QFormLayout::LabelRole, label_7);

        ShockButton = new QPushButton(formLayoutWidget);
        ShockButton->setObjectName("ShockButton");

        formLayout->setWidget(7, QFormLayout::FieldRole, ShockButton);

        label_9 = new QLabel(formLayoutWidget);
        label_9->setObjectName("label_9");

        formLayout->setWidget(8, QFormLayout::LabelRole, label_9);

        cprLabel = new QLabel(formLayoutWidget);
        cprLabel->setObjectName("cprLabel");

        formLayout->setWidget(8, QFormLayout::FieldRole, cprLabel);

        formLayoutWidget_2 = new QWidget(centralwidget);
        formLayoutWidget_2->setObjectName("formLayoutWidget_2");
        formLayoutWidget_2->setGeometry(QRect(20, 30, 376, 178));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        ConsCheck = new QCheckBox(formLayoutWidget_2);
        ConsCheck->setObjectName("ConsCheck");

        verticalLayout->addWidget(ConsCheck);

        BreathCheck = new QCheckBox(formLayoutWidget_2);
        BreathCheck->setObjectName("BreathCheck");

        verticalLayout->addWidget(BreathCheck);

        PadBox = new QComboBox(formLayoutWidget_2);
        PadBox->addItem(QString());
        PadBox->addItem(QString());
        PadBox->addItem(QString());
        PadBox->setObjectName("PadBox");

        verticalLayout->addWidget(PadBox);

        HeartRhythm = new QComboBox(formLayoutWidget_2);
        HeartRhythm->addItem(QString());
        HeartRhythm->addItem(QString());
        HeartRhythm->addItem(QString());
        HeartRhythm->addItem(QString());
        HeartRhythm->setObjectName("HeartRhythm");

        verticalLayout->addWidget(HeartRhythm);

        ContactCheck = new QCheckBox(formLayoutWidget_2);
        ContactCheck->setObjectName("ContactCheck");

        verticalLayout->addWidget(ContactCheck);

        CompressionCheck = new QComboBox(formLayoutWidget_2);
        CompressionCheck->addItem(QString());
        CompressionCheck->addItem(QString());
        CompressionCheck->addItem(QString());
        CompressionCheck->setObjectName("CompressionCheck");

        verticalLayout->addWidget(CompressionCheck);


        formLayout_2->setLayout(0, QFormLayout::FieldRole, verticalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_12 = new QLabel(formLayoutWidget_2);
        label_12->setObjectName("label_12");
        label_12->setLayoutDirection(Qt::LeftToRight);

        verticalLayout_4->addWidget(label_12);

        label_11 = new QLabel(formLayoutWidget_2);
        label_11->setObjectName("label_11");

        verticalLayout_4->addWidget(label_11);

        label_13 = new QLabel(formLayoutWidget_2);
        label_13->setObjectName("label_13");

        verticalLayout_4->addWidget(label_13);

        label_10 = new QLabel(formLayoutWidget_2);
        label_10->setObjectName("label_10");

        verticalLayout_4->addWidget(label_10);

        label_15 = new QLabel(formLayoutWidget_2);
        label_15->setObjectName("label_15");

        verticalLayout_4->addWidget(label_15);

        label_14 = new QLabel(formLayoutWidget_2);
        label_14->setObjectName("label_14");

        verticalLayout_4->addWidget(label_14);


        formLayout_2->setLayout(0, QFormLayout::LabelRole, verticalLayout_4);

        label_17 = new QLabel(centralwidget);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(20, 0, 361, 29));
        QFont font;
        font.setBold(true);
        font.setUnderline(true);
        label_17->setFont(font);
        label_17->setAlignment(Qt::AlignCenter);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 400, 371, 20));
        QFont font1;
        font1.setItalic(true);
        font1.setUnderline(true);
        label->setFont(font1);
        label->setFrameShape(QFrame::Box);
        label->setAlignment(Qt::AlignCenter);
        ConsoleLogs = new QTextBrowser(centralwidget);
        ConsoleLogs->setObjectName("ConsoleLogs");
        ConsoleLogs->setGeometry(QRect(20, 420, 371, 201));
        Picture = new QLabel(centralwidget);
        Picture->setObjectName("Picture");
        Picture->setGeometry(QRect(460, 420, 371, 121));
        Picture->setAutoFillBackground(false);
        Picture->setFrameShape(QFrame::Box);
        Picture->setAlignment(Qt::AlignCenter);
        label_20 = new QLabel(centralwidget);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(510, 70, 261, 29));
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setUnderline(true);
        label_20->setFont(font2);
        label_20->setAlignment(Qt::AlignCenter);
        batteryIcon = new QLabel(centralwidget);
        batteryIcon->setObjectName("batteryIcon");
        batteryIcon->setGeometry(QRect(740, 70, 81, 41));
        batteryIcon->setFrameShape(QFrame::NoFrame);
        batteryLevel = new QLabel(centralwidget);
        batteryLevel->setObjectName("batteryLevel");
        batteryLevel->setGeometry(QRect(770, 80, 41, 17));
        QFont font3;
        font3.setBold(true);
        batteryLevel->setFont(font3);
        batteryLevel->setFrameShape(QFrame::NoFrame);
        batteryLevel->setAlignment(Qt::AlignCenter);
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(470, 110, 341, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_21 = new QLabel(centralwidget);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(20, 210, 361, 20));
        label_21->setFont(font);
        label_21->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(20, 230, 161, 161));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_22 = new QLabel(verticalLayoutWidget);
        label_22->setObjectName("label_22");

        verticalLayout_2->addWidget(label_22);

        label_23 = new QLabel(verticalLayoutWidget);
        label_23->setObjectName("label_23");

        verticalLayout_2->addWidget(label_23);

        label_24 = new QLabel(verticalLayoutWidget);
        label_24->setObjectName("label_24");

        verticalLayout_2->addWidget(label_24);

        label_25 = new QLabel(verticalLayoutWidget);
        label_25->setObjectName("label_25");

        verticalLayout_2->addWidget(label_25);

        label_26 = new QLabel(verticalLayoutWidget);
        label_26->setObjectName("label_26");

        verticalLayout_2->addWidget(label_26);

        label_27 = new QLabel(verticalLayoutWidget);
        label_27->setObjectName("label_27");

        verticalLayout_2->addWidget(label_27);

        label_16 = new QLabel(verticalLayoutWidget);
        label_16->setObjectName("label_16");

        verticalLayout_2->addWidget(label_16);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(190, 230, 201, 161));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        ConsButton = new QPushButton(verticalLayoutWidget_2);
        ConsButton->setObjectName("ConsButton");

        verticalLayout_3->addWidget(ConsButton);

        EmergencyButton = new QPushButton(verticalLayoutWidget_2);
        EmergencyButton->setObjectName("EmergencyButton");

        verticalLayout_3->addWidget(EmergencyButton);

        AirButton = new QPushButton(verticalLayoutWidget_2);
        AirButton->setObjectName("AirButton");

        verticalLayout_3->addWidget(AirButton);

        BreathButton = new QPushButton(verticalLayoutWidget_2);
        BreathButton->setObjectName("BreathButton");

        verticalLayout_3->addWidget(BreathButton);

        Place_Pad = new QPushButton(verticalLayoutWidget_2);
        Place_Pad->setObjectName("Place_Pad");

        verticalLayout_3->addWidget(Place_Pad);

        Remove_Pad = new QPushButton(verticalLayoutWidget_2);
        Remove_Pad->setObjectName("Remove_Pad");

        verticalLayout_3->addWidget(Remove_Pad);

        changeBattery = new QPushButton(verticalLayoutWidget_2);
        changeBattery->setObjectName("changeBattery");

        verticalLayout_3->addWidget(changeBattery);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(430, 50, 421, 551));
        powerButton = new QPushButton(centralwidget);
        powerButton->setObjectName("powerButton");
        powerButton->setGeometry(QRect(720, 550, 101, 25));
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(400, 10, 20, 611));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(470, 440, 351, 81));
        Display = new QVBoxLayout(verticalLayoutWidget_3);
        Display->setObjectName("Display");
        Display->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralwidget);
        label_8->raise();
        formLayoutWidget->raise();
        formLayoutWidget_2->raise();
        label_17->raise();
        label->raise();
        ConsoleLogs->raise();
        Picture->raise();
        label_20->raise();
        batteryIcon->raise();
        batteryLevel->raise();
        line->raise();
        label_21->raise();
        verticalLayoutWidget->raise();
        verticalLayoutWidget_2->raise();
        powerButton->raise();
        line_2->raise();
        verticalLayoutWidget_3->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 876, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        consciousLabel->setText(QCoreApplication::translate("MainWindow", "Check Consciousness", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        emergencyLabel->setText(QCoreApplication::translate("MainWindow", "Call Emergency", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        airwayLabel->setText(QCoreApplication::translate("MainWindow", "Open Airway", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        breathLabel->setText(QCoreApplication::translate("MainWindow", "Check Breath", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        padLabel->setText(QCoreApplication::translate("MainWindow", "Pad Placement", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        heartAnalysisLabel->setText(QCoreApplication::translate("MainWindow", "Heart Analysis", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        ShockButton->setText(QCoreApplication::translate("MainWindow", "Shock", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        cprLabel->setText(QCoreApplication::translate("MainWindow", "CPR", nullptr));
        ConsCheck->setText(QCoreApplication::translate("MainWindow", "Conscious", nullptr));
        BreathCheck->setText(QCoreApplication::translate("MainWindow", "Normal Breath", nullptr));
        PadBox->setItemText(0, QCoreApplication::translate("MainWindow", "Just Right", nullptr));
        PadBox->setItemText(1, QCoreApplication::translate("MainWindow", "Too Low", nullptr));
        PadBox->setItemText(2, QCoreApplication::translate("MainWindow", "Too High", nullptr));

        HeartRhythm->setItemText(0, QCoreApplication::translate("MainWindow", "Ventricular Fibrillation ", nullptr));
        HeartRhythm->setItemText(1, QCoreApplication::translate("MainWindow", "Ventricular Tachycardia", nullptr));
        HeartRhythm->setItemText(2, QCoreApplication::translate("MainWindow", "Asystole (Flat-lined)", nullptr));
        HeartRhythm->setItemText(3, QCoreApplication::translate("MainWindow", "Pulseless Electrical Activity", nullptr));

        ContactCheck->setText(QCoreApplication::translate("MainWindow", "No", nullptr));
        CompressionCheck->setItemText(0, QCoreApplication::translate("MainWindow", "Just Right", nullptr));
        CompressionCheck->setItemText(1, QCoreApplication::translate("MainWindow", "Too Slow", nullptr));
        CompressionCheck->setItemText(2, QCoreApplication::translate("MainWindow", "Too Fast", nullptr));

        label_12->setText(QCoreApplication::translate("MainWindow", "Conscious Check", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Breath Check", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Pad Placement", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Heart Rhythm Detected", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "First-aider in contact", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Compression Correction", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "FIRST AIDER POINT OF VIEW", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Console Log", nullptr));
        Picture->setText(QString());
        label_20->setText(QCoreApplication::translate("MainWindow", "AED INTERFACE", nullptr));
        batteryIcon->setText(QString());
        batteryLevel->setText(QString());
        label_21->setText(QCoreApplication::translate("MainWindow", "FIRST AIDER ACTIONS", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Check Consciousness", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Call Emergency", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Open Airway", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Checking Breath", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "Place Pad", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "Remove Pad", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Change Battery", nullptr));
        ConsButton->setText(QCoreApplication::translate("MainWindow", "Conscious", nullptr));
        EmergencyButton->setText(QCoreApplication::translate("MainWindow", "Call Emergency", nullptr));
        AirButton->setText(QCoreApplication::translate("MainWindow", "Airway", nullptr));
        BreathButton->setText(QCoreApplication::translate("MainWindow", "Checking Breath", nullptr));
        Place_Pad->setText(QCoreApplication::translate("MainWindow", "Place Pad", nullptr));
        Remove_Pad->setText(QCoreApplication::translate("MainWindow", "Remove Pad", nullptr));
        changeBattery->setText(QCoreApplication::translate("MainWindow", "Change Battery", nullptr));
        label_8->setText(QString());
        powerButton->setText(QCoreApplication::translate("MainWindow", "Power Button", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
