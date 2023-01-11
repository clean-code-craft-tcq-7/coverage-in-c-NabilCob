
#include "IO.h"
#include "LanguageString.h"
#include "alert.h"

//Limits definition
const BatteryParms BatteryParmsValue[MaxBatteryParmsTypesSupported] =
{
   {PassiveCooling, { 0, 35}},
   {HighActiveCooling, {0, 45}},
   {MediumActiveCooling, { 0, 40}},
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









