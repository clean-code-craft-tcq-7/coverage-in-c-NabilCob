
#include "alert.h"
#include "IO.h"
#include "LanguageString.h"

//Limits definition
const BatteryParms BatteryParmsValue[MaxBatteryParmsTypesSupported] =
{
   {PassiveCooling, .limit.minValue = 0, .limit.maxValue = 35},
   {HighActiveCooling, .limit.minValue = 0, .limit.maxValue = 45},
   {MediumActiveCooling, .limit.minValue = 0, .limit.maxValue = 40},
};

const int Langaugedefined = English;

int checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC)
{
   BatteryParmType configParams;
   configParams.sensorValue = temperatureInC;
   configParams.errorMessage = Temperature_out_of_range;
   configParams.limit = BatteryParmsValue[batteryChar.coolingType].limit;
   configParams.alertTarget = alertTarget;
   configParams.printIO = sendToIO;
   return checkandAlertBreachStatus(configParams);
}

int checkandAlertBreachStatus(BatteryParmType batteryParmsValue){

    PrintParmsType PrintParms;
    PrintParms.value = batteryParmsValue.sensorValue;
    PrintParms.target = batteryParmsValue.alertTarget;
    PrintParms.errorMsg = batteryParmsValue.errorMessage;
    if(batteryParmsValue.sensorValue < batteryParmsValue.limit.minValue){
         PrintParms.breachLvl = Breachhigh;
        (*batteryParmsValue.printIO)(PrintParms);
        return TOO_LOW;
    }
    else if(batteryParmsValue.sensorValue > batteryParmsValue.limit.maxValue){
         PrintParms.breachLvl = Breachlow;
        (*batteryParmsValue.printIO)(PrintParms);
        return TOO_HIGH;
    }
    else{
        return NORMAL;
    }
}









