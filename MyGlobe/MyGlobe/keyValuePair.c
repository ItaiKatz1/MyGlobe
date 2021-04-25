//
// Created by itai and tomer.
//

#include "keyValuePair.h"
#include <stdio.h>
#include <stdlib.h>

struct s_keyValuePair{
    //fields
    Element Value;
    Element Key;

    //for data
    copyFunction copyFuncData;
    freeFunction freeFuncData;
    printFunction printFuncData;

    //for key
    copyFunction copyFuncKey;
    freeFunction freeFuncKey;
    printFunction printFuncKey;
    transformIntoNumberFunction transferFuncKey;
    equalFunction equalFuncKey;

};
/**
 * creates a new key-value-pair
 * @param copyFuncData
 * @param copyFuncKey
 * @param freeFuncData
 * @param freeFuncKey
 * @param printFuncData
 * @param printFuncKey
 * @param equalFuncKey
 * @param key
 * @param value
 * @return pointer to the new key-value-pair
 */
keyValuePair createKeyValuePair(copyFunction copyFuncData, copyFunction copyFuncKey, freeFunction freeFuncData,
                                freeFunction freeFuncKey, printFunction printFuncData, printFunction printFuncKey,
                                equalFunction equalFuncKey, Element key, Element value){

    if(copyFuncData==NULL||copyFuncKey==NULL||freeFuncData==NULL||freeFuncKey==NULL||
       printFuncData==NULL||printFuncKey==NULL||equalFuncKey==NULL||key==NULL){
        return NULL;
    }
    keyValuePair Pair = (keyValuePair) malloc(sizeof(struct s_keyValuePair));
    if (Pair==NULL){
        return NULL;
    }
    Pair->copyFuncData=copyFuncData;
    Pair->copyFuncKey=copyFuncKey;
    Pair->freeFuncData=freeFuncData;
    Pair->freeFuncKey=freeFuncKey;
    Pair->printFuncData=printFuncData;
    Pair->printFuncKey=printFuncKey;
    Pair->equalFuncKey=equalFuncKey;

    Element pKey = Pair->copyFuncKey(key);
    Element pValue = NULL;
    if(value!=NULL){
        pValue = Pair->copyFuncData(value);
    }
    Pair->Key=pKey;
    Pair->Value=pValue;
    return Pair;
}

/**
 * destroys a key-value-pair
 * @param Pair
 * @return failure/success
 */
status destroyKeyValuePair(Element Pair){
    if(Pair==NULL){
        return failure;
    }
    keyValuePair pair = (keyValuePair)Pair;
    pair->freeFuncKey(pair->Key);
    pair->freeFuncData(pair->Value);
    free(Pair);
    return success;
}

/**
 * sends pointer to the value of the key-value-pair
 * @param Pair
 * @return value of Pair
 */
Element getValue (Element Pair){
    if(Pair==NULL){
        return NULL;
    }
    keyValuePair pair = (keyValuePair)Pair;
    return (Element)pair->Value;
}

/**
 * sends pointer to the key of the key-value-pair
 * @param Per
 * @return key of Pair
 */
Element getKey (keyValuePair Per){
    if(Per==NULL){
        return NULL;
    }
    return Per->Key;
}

/**
 * prints the value of the key-value-pair
 * @param Pair
 * @return failure/success
 */
status displayValue (Element Pair){
    if(Pair==NULL){
        return failure;
    }
    keyValuePair pair = (keyValuePair)Pair;
    pair->printFuncData(pair->Value);
    return success;
}

/**
 * prints the key of the key-value-pair
 * @param Pair
 * @return failure/success
 */
status displayKey (keyValuePair Pair){
    if(Pair==NULL){
        return failure;
    }
    Pair->printFuncKey(Pair->Key);
    return success;
}

/**
 * returns if the keys of both key-value-pairs are equal
 * @param Pair1
 * @param Pair2
 * @return true/false
 */
bool isEqualKey(Element Pair1, Element Pair2){
    if(Pair1==NULL||Pair2==NULL){
        return false;
    }
    keyValuePair firstPair = (keyValuePair)Pair1;
    keyValuePair secondPair = (keyValuePair)Pair2;
    if(firstPair->equalFuncKey(firstPair->Key,secondPair->Key)){
        return true;
    }
    return false;
}

/**
 * returns a copy of the key-value-pair
 * @param Pair
 * @return key-value-pair tempPair
 */
Element copyPer (Element other){
    if(other==NULL){
        return NULL;
    }
    keyValuePair Pair = (keyValuePair)other;
    keyValuePair tempPair = createKeyValuePair(Pair->copyFuncData,Pair->copyFuncKey,Pair->freeFuncData,Pair->freeFuncKey,
                                               Pair->printFuncData,Pair->printFuncKey,Pair->equalFuncKey,Pair->Key,Pair->Value);
    if(tempPair==NULL){
        return NULL;
    }
    return (Element)tempPair;
}
