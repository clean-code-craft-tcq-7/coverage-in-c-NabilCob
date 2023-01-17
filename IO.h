#ifndef IO_H_
#define IO_H_


typedef enum{
   Controller,
   email,
} IOTargetType;

typedef struct{
   int errorMessage;
   int breachLvl;
} messageParmsType;

typedef struct{
  int target;
  double value;
  int errorMsg;
  int breachLvl;
} PrintParmsType;

typedef struct{
  IOTargetType type;
  void (*printIO)(PrintParmsType);
} IOTarget;

extern int AlertviaController;
extern int AlertviaEmail;
void sendToIO(PrintParmsType printParms);
void sendToController(PrintParmsType printParms);
void sendToEmail(PrintParmsType printParms);

#endif







