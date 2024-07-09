#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QString>
#include <QTimer>
#include <QTime>
#include <QComboBox>


#include "AED.h"
#include "FirstAider.h"
#include "heartrhythmwidget.h" // Include the header file for HeartRhythmWidget


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    
    AED* aed;
    FirstAider* fAider;
    
    QVector<QString> batteryLevelImages;
    QTimer *batteryTimer;
    int batteryLevel;
    HeartRhythmWidget *heartRhythmWidget; // Instance of HeartRhythmWidget

    void displayConsoleLogs(QString);
    void clearConsoleLogs();
    void delay(int t);
    void CPR();



private slots:

    void on_ConsButton_clicked();

    void on_EmergencyButton_clicked();

    void on_AirButton_clicked();

    void on_BreathButton_clicked();

    void on_ShockButton_clicked();

    void on_ConsCheck_clicked(bool checked);

    void on_BreathCheck_clicked(bool checked);

    void on_HeartRhythm_activated(int index);

    void on_PadBox_activated(int index);

    void on_ContactCheck_clicked(bool checked);

    void on_CompressionCheck_activated(int index);

    void on_powerButton_clicked();

    void decreaseBattery();

    void displayBattery(int batteryLevel);

    void on_changeBattery_clicked();

    void on_Remove_Pad_clicked();

    void on_Place_Pad_clicked();
};
#endif // MAINWINDOW_H
