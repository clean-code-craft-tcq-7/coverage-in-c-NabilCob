
#ifndef ALERT_H_
#define ALERT_H_

//Enum declaration
typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING,
} CoolingType;

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

typedef enum{
   PassiveCooling,
   HighActiveCooling,
   MediumActiveCooling,
   MaxBatteryParmsTypesSupported,
} BatteryParmsType;

//Structure declaration
typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

typedef struct {
  int minValue;
  int maxValue;
}BatteryParmsLimit;

typedef struct{
    BatteryParmsType type;
    BatteryParmsLimit limit;
} BatteryParms;

typedef struct{
    double sensorValue;
    BatteryParmsLimit limit;
    void (*printIO)();
    int alertTarget;
    int errorMessage;
} BatteryParmType;

//Variable declaration
extern const int Langaugedefined;

//Function declaration
int checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);
int checkandAlertBreachStatus(BatteryParmType batteryParmsValue);

#endif
