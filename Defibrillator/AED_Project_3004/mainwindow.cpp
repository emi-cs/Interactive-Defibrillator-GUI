#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), aed(new AED()), fAider(new FirstAider())
{
    ui->setupUi(this);
    ui->Picture->setStyleSheet("background-color: white");
    ui->label_8->setStyleSheet("background-color: #a2f5bf; border: 2px solid #70db70; border-radius: 15px;");
    ui->powerButton->setStyleSheet("background-color: #ffcc00; border: 2px solid #e5e5e5; border-radius: 5px; padding: 5px;");
    ui->label->setStyleSheet("background-color: yellow");


    // Initialize your HeartRhythmWidget
    heartRhythmWidget = new HeartRhythmWidget(this);
    ui->Display->addWidget(heartRhythmWidget);
    heartRhythmWidget->setRhythm(4);

    batteryLevelImages.append(":/Images/Images/battery_100.png");
    batteryLevelImages.append(":/Images/battery_80.png");
    batteryLevelImages.append(":/Images/battery_50.png");
    batteryLevelImages.append(":/Images/battery_30.png");
    batteryLevelImages.append(":/Images/battery_5.png");
    batteryLevelImages.append(":/Images/battery_0.png");

    QPixmap img1(":/Images/Images/1.png");
    ui->label_2->setPixmap(img1.scaled(ui->label_2->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    QPixmap img2(":/Images/Images/2.png");
    ui->label_3->setPixmap(img2.scaled(ui->label_3->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    QPixmap img3(":/Images/Images/3.png");
    ui->label_4->setPixmap(img3.scaled(ui->label_4->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    QPixmap img4(":/Images/Images/4.png");
    ui->label_5->setPixmap(img4.scaled(ui->label_5->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    QPixmap img5(":/Images/Images/5.png");
    ui->label_6->setPixmap(img5.scaled(ui->label_6->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    QPixmap img6(":/Images/Images/6.png");
    ui->label_7->setPixmap(img6.scaled(ui->label_7->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    QPixmap img7(":/Images/Images/7.png");
    ui->label_9->setPixmap(img7.scaled(ui->label_9->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    QPixmap img8(":/Images/Images/8.png");
    ui->label_19->setPixmap(img8.scaled(ui->label_19->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));



    batteryTimer = new QTimer(this);
    batteryTimer->setInterval(2000);
    connect(batteryTimer, SIGNAL(timeout()), this, SLOT(decreaseBattery()));
    batteryTimer->start();


}

MainWindow::~MainWindow()
{
    delete ui;
    delete aed;
    delete fAider;
}

void MainWindow::displayConsoleLogs(QString message) { ui->ConsoleLogs->append(message); }
void MainWindow::clearConsoleLogs() { ui->ConsoleLogs->clear(); }

void MainWindow::on_ConsButton_clicked()
{
    displayConsoleLogs(fAider->checkConscious());
}

void MainWindow::on_EmergencyButton_clicked()
{
    displayConsoleLogs(fAider->Emergency());
}

void MainWindow::on_AirButton_clicked()
{
    displayConsoleLogs(fAider->Airway());
}

void MainWindow::on_BreathButton_clicked()
{
    displayConsoleLogs(fAider->CheckBreath());
}

void MainWindow::on_ShockButton_clicked()
{
    if(aed->getShockable() == false){
        return ;
    }
    if (fAider->PadPlacement() == 1 || fAider->PadPlacement() == 2) {
        displayConsoleLogs("Lost connection. Place pads again correctly");
        ui->ShockButton->setStyleSheet("");
        aed->setShockable(false);
        return;
    }
    if (fAider->StandClear() == true)
    {
        displayConsoleLogs(aed->ShockProceed(true));
        ui->ShockButton->setStyleSheet("");
        aed->setShockable(false);
        ui->cprLabel->setStyleSheet("background-color:rgb(51, 209, 122)");

    }
    else
    {
        displayConsoleLogs(aed->ShockProceed(false));
        return;
    }

    if (fAider->getConscious() == true) {
        ui->cprLabel->setStyleSheet("");
        displayConsoleLogs("Cannot shock if patient is conscious!");
    }
    int CPRJustRightCount = 0;
    int CPRCount = 0;
    delay(5);
    while(fAider->getConscious() ==false && aed->getPower() == true && aed->getPadPlaced() == true){
        displayConsoleLogs(aed->CompressionCorrection(fAider->ChestCompression()));
        CPRCount++;
        if(fAider->ChestCompression() == 0){
            CPRJustRightCount++;
        }
        if(CPRJustRightCount >= 3){
            fAider->setConscious(true);
            CPR();
            break;
        } if(CPRCount >= 5){
            CPR();
            break;
        }
        delay(5);
    }

}

void MainWindow::CPR()
{
    if (fAider->getConscious() == true)
    {
        displayConsoleLogs(fAider->success());
        ui->ConsCheck->setCheckState(Qt::Checked);
        ui->BreathCheck->setCheckState(Qt::Checked);
        ui->HeartRhythm->setCurrentIndex(3);
        aed->setRhythm(3);
        ui->cprLabel->setStyleSheet("");
        if (aed->getPower() == true && aed->getPadPlaced() == true){
            heartRhythmWidget->setRhythm(aed->getRhythm());
        }
        displayConsoleLogs("Please remove pads");
        if (aed->getPadPlaced() == true){
            aed->setPadPlaced(false);
        }
    }else{
        aed->setShockable(true);
        ui->cprLabel->setStyleSheet("");
        ui->ShockButton->setStyleSheet("background-color:rgb(51, 209, 122)");
        displayConsoleLogs("FirstAider: The patient is still unconscious!");
    }


}

void MainWindow::on_CompressionCheck_activated(int index)
{
    fAider->setCompression(index);
}



void MainWindow::on_ConsCheck_clicked(bool checked)
{
    fAider->setConscious(checked);
}

void MainWindow::on_BreathCheck_clicked(bool checked)
{
    fAider->setBreath(checked);
}

void MainWindow::on_HeartRhythm_activated(int index)
{
    aed->setRhythm(index);
    if(index == 2){
        ui->ConsCheck->setCheckState(Qt::Unchecked);
        ui->BreathCheck->setCheckState(Qt::Unchecked);
        displayConsoleLogs("If Flatlined - Patience should be unconscious and breathing abnormally");
    }
    else if(index == 0 || index == 1){
        ui->ConsCheck->setCheckState(Qt::Unchecked);
        displayConsoleLogs("If Heart Rhythm is abnormal - Patience should be unconscious");
    }

}

void MainWindow::on_PadBox_activated(int index)
{
    fAider->setPadPlacement(index);
}

void MainWindow::on_ContactCheck_clicked(bool checked)
{
    fAider->setStandClear(checked);
}



void MainWindow::on_powerButton_clicked()
{
    displayConsoleLogs(aed->powerOn());

    if(aed->getPower() == true){
        ui->powerButton->setStyleSheet("background-color:green");
        batteryLevel = aed->getBatteryLevel();
        displayBattery(batteryLevel);

        if(aed->getPadPlaced() == false){

            if(aed->getPower() == true){
                displayConsoleLogs("\nAudio: Check Consciousness");
                displayConsoleLogs(aed->checkConsciousness());
                ui->consciousLabel->setStyleSheet("background-color:rgb(51, 209, 122)");
                delay(5);
                ui->consciousLabel->setStyleSheet("");
            }

            if(aed->getPower() == true){
                displayConsoleLogs("\nAudio: Call for help");
                displayConsoleLogs(aed->CallEmergency());
                ui->emergencyLabel->setStyleSheet("background-color:rgb(51, 209, 122)");
                delay(5);
                ui->emergencyLabel->setStyleSheet("");
            }

            if(aed->getPower() == true){
                displayConsoleLogs("\nAudio: Open Airway");
                displayConsoleLogs(aed->OpenAirway());
                ui->airwayLabel->setStyleSheet("background-color:rgb(51, 209, 122)");
                delay(5);
                ui->airwayLabel->setStyleSheet("");
            }

            if(aed->getPower() == true){
                displayConsoleLogs("\nAudio: Check Breathing");
                displayConsoleLogs(aed->checkBreathing());
                ui->breathLabel->setStyleSheet("background-color:rgb(51, 209, 122)");
                delay(5);
                ui->breathLabel->setStyleSheet("");
            }

            if(aed->getPower() == true){
                displayConsoleLogs("\nPlace Electropad on Patient's chest");
                displayConsoleLogs("\nAudio: Place Electropad on Patient's chest\n");
                ui->padLabel->setStyleSheet("background-color:rgb(51, 209, 122)");
            }
        }
        else{
            on_Place_Pad_clicked();
        }
    }

    else{
        ui->cprLabel->setStyleSheet("");
        ui->powerButton->setStyleSheet("");
        ui->batteryLevel->setText("");
        QPixmap noBatteryImg("");
        ui->batteryIcon->setPixmap(noBatteryImg);
        heartRhythmWidget->setRhythm(4);
        ui->powerButton->setStyleSheet("background-color: #ffcc00; border: 2px solid #e5e5e5; border-radius: 5px; padding: 5px;");
        ui->consciousLabel->setStyleSheet("");
        ui->emergencyLabel->setStyleSheet("");
        ui->airwayLabel->setStyleSheet("");
        ui->breathLabel->setStyleSheet("");
        ui->padLabel->setStyleSheet("");
        ui->heartAnalysisLabel->setStyleSheet("");
        ui->ShockButton->setStyleSheet("");

    }
}


void MainWindow::decreaseBattery(){
    if(aed->getPower()==true){
        batteryLevel = aed->getBatteryLevel();
        displayBattery(batteryLevel);
        aed->depleteBattery();
    }
}

void MainWindow::displayBattery(int batteryLevel){
    ui->batteryLevel->setText(QString::fromStdString(std::to_string(batteryLevel) + " %"));
    if(100 >= batteryLevel && batteryLevel >= 90){
        QPixmap battery100img(":/Images/Images/battery_100.png");
        ui->batteryIcon->setPixmap(battery100img.scaled(ui->batteryIcon->size(),Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    else if(99>= batteryLevel && batteryLevel >= 65){
        QPixmap battery80img(":/Images/Images/battery_80.png");
        ui->batteryIcon->setPixmap(battery80img.scaled(ui->batteryIcon->size(),Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    else if(65>= batteryLevel && batteryLevel >= 30){
        QPixmap battery50img(":/Images/Images/battery_50.png");
        ui->batteryIcon->setPixmap(battery50img.scaled(ui->batteryIcon->size(),Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    else if(30>=batteryLevel && batteryLevel >= 5){
        QPixmap battery30img(":/Images/Images/battery_30.png");
        ui->batteryIcon->setPixmap(battery30img.scaled(ui->batteryIcon->size(),Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    else if(5>= batteryLevel && batteryLevel >= 1){
        QPixmap battery5img(":/Images/Images/battery_5.png");
        ui->batteryIcon->setPixmap(battery5img.scaled(ui->batteryIcon->size(),Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }

    if(batteryLevel == 30){
        displayConsoleLogs("\nWarning: AED Battery Level Dropped Below 30%!\n");
    }
    if(batteryLevel == 5){
        displayConsoleLogs("\nWarning: AED Battery Level Dropped Below 5%!\n");
    }

    if(batteryLevel == 0 && aed->getPower() == true){
        displayConsoleLogs("\nWarning: AED Battery Level 0%. Turning off...\n");
        ui->powerButton->setStyleSheet("");
        ui->batteryLevel->setText("");
        QPixmap noBatteryImg("");
        ui->batteryIcon->setPixmap(noBatteryImg);
        heartRhythmWidget->setRhythm(4);
        ui->powerButton->setStyleSheet("background-color: #ffcc00; border: 2px solid #e5e5e5; border-radius: 5px; padding: 5px;");
    }

    if(batteryLevel == 0 && aed->getPower() == false){
        ui->powerButton->setStyleSheet("");
        ui->batteryLevel->setText("");
        QPixmap noBatteryImg("");
        ui->batteryIcon->setPixmap(noBatteryImg);
        heartRhythmWidget->setRhythm(4);
        ui->powerButton->setStyleSheet("background-color: #ffcc00; border: 2px solid #e5e5e5; border-radius: 5px; padding: 5px;");
    }

}


void MainWindow::on_changeBattery_clicked()
{
    clearConsoleLogs();
    aed->changeBattery();
    displayConsoleLogs("Battery Changed Successfully");
    if(aed->getPower() == true){
        on_powerButton_clicked();
        heartRhythmWidget->setRhythm(4);
    }
//    on_powerButton_clicked();
}

void MainWindow::delay(int t){
    QTime dieTime = QTime::currentTime().addSecs(t);
        while (QTime::currentTime() < dieTime){
            QCoreApplication::processEvents(QEventLoop::AllEvents,100);
        }
}

void MainWindow::on_Remove_Pad_clicked()
{
    displayConsoleLogs("\nPads removed");
    aed->setPadPlaced(false);
    ui->cprLabel->setStyleSheet("");
    heartRhythmWidget->setRhythm(4);
    ui->ShockButton->setStyleSheet("");
}


void MainWindow::on_Place_Pad_clicked()
{
    if(aed->getPadPlaced() == false){
        displayConsoleLogs("\nPad Placed");
    }
    aed->setPadPlaced(true);

   if(aed->getPower()== false){
       return;
   }


   if(fAider->PadPlacement() == 0){
       displayConsoleLogs(aed->DetectRhythm(aed->getRhythm()));
       ui->padLabel->setStyleSheet("");
       ui->heartAnalysisLabel->setStyleSheet("background-color:rgb(51, 209, 122)");
       delay(5);
   }else{
       if(aed->getPower() == 1){
            heartRhythmWidget->setRhythm(4);
            aed->setShockable(false);
            ui->ShockButton->setStyleSheet("");
           displayConsoleLogs("\nWarning: Cannot analyze as Pads are misplaced!");
           displayConsoleLogs("\nWarning: To continue set Pad Placement to Just Right!\n");
       }else{
           displayConsoleLogs(aed->DetectRhythm(aed->getRhythm()));
       }
   }
   ui->heartAnalysisLabel->setStyleSheet("");
   if(aed->getPower() == 1 && fAider->PadPlacement() == 0){
       if(aed->getRhythm() == 0){
           ui->ShockButton->setStyleSheet("background-color:rgb(51, 209, 122)");
           aed->setShockable(true);
       }else if(aed->getRhythm() == 1){
           ui->ShockButton->setStyleSheet("background-color:rgb(51, 209, 122)");
           aed->setShockable(true);
       }else if(aed->getRhythm() == 2){
           if(fAider->getConscious() == true){
               displayConsoleLogs("Patience is conscious while flatline? Change to right status before proceeding!");
               return;
           }
           heartRhythmWidget->setRhythm(aed->getRhythm());
           displayConsoleLogs(aed->ShockProceed(true));
           int Count = 0;
           int CPRJustRightCount = 0;
           delay(5);
           while(fAider->getConscious()==false && aed->getPower() == true && aed->getPadPlaced() == true){
               displayConsoleLogs(aed->CompressionCorrection(fAider->ChestCompression()));
               Count++;
               if(fAider->ChestCompression() == 0){
                   CPRJustRightCount++;
               }
               if(CPRJustRightCount >= 3){
                   fAider->setConscious(true);
                   CPR();
                   break;
               }if(Count >= 5){
                   Count = 0;
                   CPRJustRightCount = 0;
                   displayConsoleLogs("FirstAider: The patient is still unconscious!");
                   displayConsoleLogs("CPR Starts again!");
               }
               delay(5);
            }
       }
       heartRhythmWidget->setRhythm(aed->getRhythm());
   }
}

