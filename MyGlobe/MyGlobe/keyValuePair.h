//
// Created by itai and tomer.
//
#include "Defs.h"
#ifndef EX2ADVANCEDCODING_KEYVALUEPAIR_H
#define EX2ADVANCEDCODING_KEYVALUEPAIR_H


typedef struct s_keyValuePair * keyValuePair;


//declarations on functions
keyValuePair createKeyValuePair(copyFunction copyFuncData, copyFunction copyFuncKey, freeFunction freeFuncData,
                               freeFunction freeFuncKey, printFunction printFuncData, printFunction printFuncKey,
                               equalFunction equalFuncKey, Element key, Element value);
status destroyKeyValuePair(Element Pair);
Element getValue (Element Pair);
Element getKey (keyValuePair Per);
status displayValue (Element Pair);
status displayKey (keyValuePair Pair);
bool isEqualKey(Element Pair1, Element Pair2);
Element copyPer (Element other);


#endif //EX2ADVANCEDCODING_KEYVALUEPAIR_H
