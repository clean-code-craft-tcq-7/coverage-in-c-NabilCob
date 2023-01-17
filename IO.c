#include <stdio.h>
#include "IO.h"
#include "alert.h"
#include "LanguageString.h"

int AlertviaController = 0;
int AlertviaEmail = 0;

IOTarget Targettype[] ={
     {Controller,  sendToController},
     {email, sendToEmail}
};

void sendToIO(PrintParmsType printParms){
    Targettype[printParms.target].printIO(printParms);
}

void sendToController(PrintParmsType printParms) {

  const unsigned short header = 0xfeed;
  AlertviaController ++;   
  printf("\n%x : %x", header, printParms.breachLvl);
}

void sendToEmail(PrintParmsType printParms) {
  const char* recepient = "a.b@c.com";
  AlertviaEmail ++;  
  printf("\nTo: %s\nsensor value - %lf,%s,%s", recepient,
                  printParms.value,
                  stringsArray[printParms.errorMsg].LangArray[Langaugedefined],
                  stringsArray[printParms.breachLvl].LangArray[Langaugedefined]);
}
