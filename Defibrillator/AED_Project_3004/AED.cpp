#include "AED.h"
#include "iostream"

AED::AED(): power(false), test(false), rhythm(0) {batteryLevel = 100;}

AED::AED(bool power): power(power), test(false), rhythm(2) {}

AED::~AED(){}

QString AED::powerOn(){
    if (power == true){
        power = false;
        return "\nAED turning off\n";
    }
    else{ 
        if(batteryLevel != 0){
            power = true;
            QString str = "";
            str += "\nAED powered on. Doing self-test...";
            str += "\nAudio: AED powered on. Doing self-test...\n";
            if (selfTest(true) == true){
                str += "\nSelf test passed. Ready for operation";
                str += "\nAudio: Self test passed. Ready for operation\n";
            }
            return str;
        }
        else{
            QString str = "";
            str += "\nPlease change the battery.\n";
            return str;
        }
    }
}

bool AED::selfTest(bool test){
    this->test = true;

    return test;
}


QString AED::checkConsciousness(){
    return "Check consciousness of patient.\n";
}



QString AED::DetectRhythm(int heart){

    if (power == false){
        return "\nFirstAider: The AED is off. Let me turn it on\n";
    }
    QString str = "";
    str += "\nAnalyzing rhythm with pads..Don't touch patient.";
    str += "\nAudio: Analyzing rhythm with pads..Don't touch patient.\n";
    rhythm = heart;
    if (heart == 0){
        str += "\nShock advised: Ventricular fibrillation";
        str += "\nAudio: Shock advised: Ventricular fibrillation\n";
    }
    else if (heart == 1){
        str += "\nShock advised: Ventricular tachycardia";
        str += "\nAudio: Shock advised: Ventricular tachycardia\n";
    }
    else if (heart == 2){
        str += "\nFlatline...";
        str += "\nAudio: Flatline...\n";
    }
    else if (heart == 3){
        str += "\nNormal heart rate";
        str += "\nAudio: Normal heart rate\n";
    }
    return str;
}

void AED::setShockable(bool shock){
    shockable = shock;
}

bool AED::getShockable(){
    return shockable;
}

void AED::setPadPlaced(bool pad){
    padPlaced = pad;
}

bool AED::getPadPlaced(){
    return padPlaced;
}


QString AED::ShockProceed(bool proceed){

    if (power == false){
        return "\nFirstAider: The AED is off. Let me turn it on\n";
    }

    QString str = "";
    if(proceed == false){
        str += "\nFirstAider: Cannot proceed since not clear of patient\n";
        return str;
    }else{
        if (rhythm == 3){
            str += "\nNormal heart rate. No shock needed.";
            str += "\nAudio: Normal heart rate. No shock needed.\n";
        }
        else if (rhythm == 2){
            str += "\nFlatline. No shock needed. Go to CPR";
            str += "\nAudio: Flatline. No shock needed. Go to CPR\n";
        }

        if (rhythm == 0){
            str += "\nApplying Shock on ventricular fibrillation";
            str += "\nAudio: Applying Shock on ventricular fibrillation\n";
        }
        else if (rhythm == 1){
            str += "\nApplying Shock on ventricular tachycardia";
            str += "\nAudio: Applying Shock on ventricular tachycardia\n";
        }
    }
    str += "\n";
    str += "\nProceed to CPR";
    str += "\nAudio: Proceed to CPR\n";
    str += "\nContinously give sets of 30 chest compressions and 2 breaths";
    str += "\nAudio: Continously give sets of 30 chest compressions and 2 breaths\n";
    return str;
}

void AED::setRhythm(int rhythm){
    this->rhythm = rhythm;
}

QString AED::CallEmergency(){

    return "Call for help!\n";
}

QString AED::OpenAirway(){
    return "Open Airway\n";
}

QString AED::checkBreathing(){
    return "Check breathing\n";
}

QString AED::PadCorrection(int padPlacement){

    if(padPlacement == 0){
        return "\nPad Placed Just Right\n";
    }else if(padPlacement == 1){
        return "\nPad Placed Too Low\n";
    }else if(padPlacement == 2){
        return "\nPad Placed Too High\n";
    }
    return "\nError";
}

QString AED::CompressionCorrection(int chestCompression){

    if(chestCompression == 0){
        return "\nKeep pushing the chest of the patient at this rate!\n";
    }else if(chestCompression == 1){
        return "\nYou're doing it too slow. Try faster\n";
    }else if(chestCompression == 2){
        return "\nYou're doing it too fast. Try slower\n";
    }
    return "\nError";
}

int AED::getRhythm(){
    return rhythm;
}

bool AED::getPower(){
    return power;
}

void AED::depleteBattery(){
    if(batteryLevel > 0){
        batteryLevel -= 1;
    }
    else{
        batteryLevel = 0;
        power = false;
    }
}

int AED::getBatteryLevel(){
    return batteryLevel;
}


void AED::changeBattery(){
    batteryLevel = 100;
}

void AED::setPower(bool reset){
    power = reset;
}
