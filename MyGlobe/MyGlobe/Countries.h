//
// Created by itai and tomer.
//
#ifndef EX2ADVANCEDCODING_COUNTRIES_H
#define EX2ADVANCEDCODING_COUNTRIES_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Defs.h"
//---------------------------- Predeclarations -------------------------//


//Declarations of the structures
typedef struct st_Country* Country;
typedef struct st_City* City;
typedef struct st_GeographicArea* GeographicArea;

//Declarations of AddCountry
Country AddCountry (char* name, int x1, int y1, int x2, int y2);
//Declaration of AddCityToCountry
bool AddCityToCountry (Country country, City city);
//Declaration of DeleteCityFromCountry
status DeleteCityFromCountry (Country country, char* name);
//Declaration of isInArea
bool IsInArea (Country county, int x, int y);
//declaration of freeCountryMem
status FreeCountryMem(Element other);
//declaration of DeepCopyCountry
Element DeepCopyCountry(Element other);
//declaration of PrintCountry(Country*)
status PrintCountry(Element other);

//declaration of (not in the instructions) DoesCityExist
bool DoesCityExist(Country country, char* name);
//declaration of (not in the instructions) getCountryName)
Element CopyCountryName(Element name);
//declaration of (not in the instructions) createCity
City CreateCity(char* name, char* food, int residentsNum);
//declaration of (not in the instructions) deleteCountryName
status DeleteCountryName(Element countryName);
//declaration of (not in the instructions) printCountryName
status PrintCountryName(Element countryName);
//declaration of (not in the instructions) AreCountryNamesEqual
bool AreCountryNamesEqual(Element firstName, Element secondName);
//declaration of (not in the instructions) ChangeCountryNameToInteger
int ChangeCountryNameToInteger(Element name);
//declaration of (not in the instructions) GetCountryName
char* GetCountryName(Country country);
#endif //EX2ADVANCEDCODING_COUNTRIES_H
