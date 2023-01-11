#ifndef LANGUAGE_STRING_H_
#define LANGUAGE_STRING_H_

typedef enum{
    Temperature_out_of_range,
    Breachhigh,
    Breachlow,
    Max_error_messages,
}errorList;



typedef enum{
    English,
    MaxsupportedLanguages,
}LanguagesSupported;


typedef struct{
    char *LangArray[MaxsupportedLanguages];
}LangArray_t;

extern const LangArray_t stringsArray[Max_error_messages];
#endif
