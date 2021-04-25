//
// Created by itai and tomer.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Countries.h"
#include "HashTable.h"


//declaration of (not in the instructions) AddCountrytoCountries
bool AddCountryToCountries(Country* countries ,Country newCountry, int numOfCountries);
//int argc, char**argv
int main(int argc, char**argv) {
    //here we are reading the data from the file
    if (argv == NULL) {
        return 1;
    }
    char buffer[300];
    FILE *ptrFile;
    ptrFile = fopen(argv[3], "r");
    //if the opening failed
    if (!ptrFile) {
        return 1;
    }
    Country *allCountries = (Country*) malloc(sizeof(Country) *atoi(argv[2])); //check this line, and remember the assignment was handed with this line in a bad version
    int numOfCountries = 0;
    const char *delimiterComma = ",";
    const char *cityIndication = "\t";
    char *tempCountryName;
    char *tempCoordinate;
    char *tempCityName;
    char *tempKnownFood;
    char *tempResidents;
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    while (fgets(buffer, 300, ptrFile) != NULL) {
        int x1 = 0;
        int y1 = 0;
        int x2 = 0;
        int y2 = 0;
        int numOfResidents = 0;
        char *comma = strtok(buffer, delimiterComma);
        while (comma != NULL) {
            if (comma[0] != *cityIndication) { //if we didn't reach a string that represents a city
                for (int i = 0; i < 5; i++) {
                    if (i == 0) {
                        tempCountryName = (char *) malloc(sizeof(char) * strlen(comma) + 1);
                        if (tempCountryName == NULL) {
                            printf("no memory available\n");
                            for (int j = 0; j < numOfCountries; j++) {
                                FreeCountryMem(allCountries[j]);
                            }
                            free(allCountries);
                            return 1;
                        }
                        strcpy(tempCountryName, comma);
                    } else if (i == 1) {
                        tempCoordinate = (char *) malloc(sizeof(char) * strlen(comma) + 1);
                        if (tempCoordinate == NULL) {
                            printf("no memory available\n");
                            free(tempCountryName);
                            for (int j = 0; j < numOfCountries; j++) {
                                FreeCountryMem(allCountries[j]);
                            }
                            free(allCountries);
                            return 1;
                        }
                        strcpy(tempCoordinate, comma);
                        x1 = atoi(tempCoordinate);
                        free(tempCoordinate);
                        tempCoordinate = NULL;
                    } else if (i == 2) {
                        tempCoordinate = (char *) malloc(sizeof(char) * strlen(comma) + 1);
                        if (tempCoordinate == NULL) {
                            printf("no memory available\n");
                            free(tempCountryName);
                            for (int j = 0; j < numOfCountries; j++) {
                                FreeCountryMem(allCountries[j]);
                            }
                            free(allCountries);
                            return 1;
                        }
                        strcpy(tempCoordinate, comma);
                        y1 = atoi(tempCoordinate);
                        free(tempCoordinate);
                        tempCoordinate = NULL;
                    } else if (i == 3) {
                        tempCoordinate = (char *) malloc(sizeof(char) * strlen(comma) + 1);
                        if (tempCoordinate == NULL) {
                            printf("no memory available\n");
                            free(tempCountryName);
                            for (int j = 0; j < numOfCountries; j++) {
                                FreeCountryMem(allCountries[j]);
                            }
                            free(allCountries);
                            return 1;
                        }
                        strcpy(tempCoordinate, comma);
                        x2 = atoi(tempCoordinate);
                        free(tempCoordinate);
                        tempCoordinate = NULL;
                    } else if (i == 4) {
                        tempCoordinate = (char *) malloc(sizeof(char) * strlen(comma) + 1);
                        if (tempCoordinate == NULL) {
                            printf("no memory available\n");
                            free(tempCountryName);
                            for (int j = 0; j < numOfCountries; j++) {
                                FreeCountryMem(allCountries[j]);
                            }
                            free(allCountries);
                            return 1;
                        }
                        strcpy(tempCoordinate, comma);
                        y2 = atoi(tempCoordinate);
                        free(tempCoordinate);
                        tempCoordinate = NULL;
                    }
                    if (i == 4) { //if we i=4 we've finished going through the entire row, and we have all the variables of the country
                        Country newCountry = AddCountry(tempCountryName, x1, y1, x2, y2);
                        bool flag = AddCountryToCountries(allCountries, newCountry, numOfCountries);
                        if (!flag) {
                            printf("no memory available\n");
                            free(tempCountryName);
                            for (int j = 0; j < numOfCountries; j++) {
                                FreeCountryMem(allCountries[j]);
                            }
                            free(allCountries);
                            return 1;
                        }
                        numOfCountries++;
                        free(tempCountryName);
                        tempCountryName = NULL;
                    }
                    comma = strtok(NULL, delimiterComma);
                } // if counter equals 4 we've passed through all the tokens of the string, meaning we finished with this line of country
            } else { //means we've reached a city-line
                for (int i = 0; i < 3; i++) {
                    if (i == 0) {
                        tempCityName = (char *) malloc(sizeof(char) * strlen(comma) + 1);
                        if (tempCityName == NULL) {
                            printf("no memory available\n");
                            for (int j = 0; j < numOfCountries; j++) {
                                FreeCountryMem(allCountries[j]);
                            }
                            free(allCountries);
                            return 1;
                        }
                        strcpy(tempCityName, comma + 1);
                    } else if (i == 1) {
                        tempKnownFood = (char *) malloc(sizeof(char) * strlen(comma) + 1);
                        if (tempKnownFood == NULL) {
                            printf("no memory available\n");
                            free(tempCityName);
                            for (int j = 0; j < numOfCountries; j++) {
                                FreeCountryMem(allCountries[j]);
                            }
                            free(allCountries);
                            return 1;
                        }
                        strcpy(tempKnownFood, comma);
                    } else if (i == 2) {
                        tempResidents = (char *) malloc(sizeof(char) * strlen(comma) + 1);
                        if (tempResidents == NULL) {
                            printf("no memory available\n");
                            free(tempCityName);
                            free(tempKnownFood);
                            for (int j = 0; j < numOfCountries; j++) {
                                FreeCountryMem(allCountries[j]);
                            }
                            free(allCountries);
                            return 1;
                        }
                        strcpy(tempResidents, comma);
                        numOfResidents = atoi(tempResidents);
                        free(tempResidents);
                        tempResidents = NULL;
                    }
                    if (i == 2) {
                        City newCity = CreateCity(tempCityName, tempKnownFood, numOfResidents);
                        bool flag = AddCityToCountry(allCountries[numOfCountries - 1], newCity);
                        if (!flag) {
                            printf("no memory available\n");
                            for (int j = 0; j < numOfCountries; j++) {
                                FreeCountryMem(allCountries[j]);
                            }
                            free(tempCityName);
                            free(tempKnownFood);
                            free(allCountries);
                            return 1;
                        }
                        free(tempCityName);
                        free(tempKnownFood);
                        newCity = NULL; //we freed newCity in the function AddCityToCountry
                    }
                    comma = strtok(NULL, delimiterComma);
                }
            }
            comma = strtok(NULL, delimiterComma);
        }
        free(comma);
        comma = NULL;
    }
    fclose(ptrFile); //closing the file which was used to get the countries
    //now we will create a hashTable from the Allcountries array
    hashTable Atlas = createHashTable(CopyCountryName, DeleteCountryName, PrintCountryName, DeepCopyCountry, FreeCountryMem, PrintCountry, AreCountryNamesEqual, ChangeCountryNameToInteger, atoi(argv[1]));
    if(Atlas==NULL){
        printf("No memory available\n");
        for (int j = 0; j < numOfCountries; j++) {
            FreeCountryMem(allCountries[j]);
        }
        free(allCountries);
        return 1;
    }
    //the loop will copy every country from the array to the Atlas
    for(int i=0; i<numOfCountries; i++){
        char* key = GetCountryName(allCountries[i]);
        if(key==NULL){
            printf("No memory available\n");
            destroyHashTable(Atlas);
            for (int j = 0; j < numOfCountries; j++) {
                FreeCountryMem(allCountries[j]);
            }
            free(allCountries);
            return 1;
        }
        if(addToHashTable(Atlas, (Element)key, (Element)allCountries[i])==failure){
            printf("No memory available\n");
            free(key);
            destroyHashTable(Atlas);
            for (int j = 0; j < numOfCountries; j++) {
                FreeCountryMem(allCountries[j]);
            }
            free(allCountries);
            return 1;
        }
        free(key);
    }
    //destroying allCountries, since of all its countries are now inside Atlas
    for (int j = 0; j < numOfCountries; j++) {
        FreeCountryMem(allCountries[j]);
    }
    free(allCountries);


    printf("please choose one of the following numbers:\n");
    printf("1 : print Countries\n2 : add country\n3 : add city to country\n4 : delete city from country\n"
           "5 : print country by name\n6 : delete country\n7 : is country in area\n8 : exit\n");
    int number;
    bool finishProgram = false;
    while(!finishProgram){
        scanf("%d", &number);
        switch(number) {
            case 1:
                if(displayHashElements(Atlas)==failure){ //check what to do in case it doesn't manage to print all of the countries.
                    printf("Didn't manage to print all of the countries\n");
                    break;
                    }
                break;

            case 2:
                printf("please enter a new country name\n");
                scanf("%s", buffer);
                if(lookupInHashTable(Atlas, buffer)!=NULL){
                    printf("country with this name already exist\n");
                    break;
                }
                printf("please enter two x and y coordinates :x1,y1,x2,y2\n");
                scanf("%d, %d, %d, %d", &x1, &y1, &x2, &y2);
                Country newCountry = AddCountry(buffer, x1, y1, x2, y2);
                if(newCountry==NULL){
                	printf("no memory available\n");
                	destroyHashTable(Atlas);
                	return 1;
                }
                if(addToHashTable(Atlas, buffer, newCountry)==failure){
                    printf("no memory available\n");
                    FreeCountryMem(newCountry);
                    destroyHashTable(Atlas);
                    return 1;
                }
                FreeCountryMem(newCountry);
                break;

            case 3:
                printf("please enter a country name\n");
                scanf("%s", buffer);
                Country countryToAddTo = (Country)lookupInHashTable(Atlas, buffer);
                if(countryToAddTo==NULL){
                    printf("country not exist\n");
                    break;
                }
                printf("please enter a city name\n");
                scanf("%s", buffer);
                if(DoesCityExist(countryToAddTo, buffer)){
                    printf("this city already exist in this country\n");
                    break;
                } else {
                    char *cityName = (char *) malloc(sizeof(char) * strlen(buffer) + 1);
                    strcpy(cityName, buffer);
                    printf("please enter the city favorite food\n");
                    scanf("%s", buffer);
                    printf("please enter number of residents in city\n");
                    int numOfResidents;
                    scanf("%d", &numOfResidents);
                    City cityToAdd = CreateCity(cityName, buffer, numOfResidents);
                    free(cityName);
                    cityName = NULL;
                    if (!AddCityToCountry(countryToAddTo, cityToAdd)) {
                        printf("no memory available\n");
                        destroyHashTable(Atlas);
                        return 1;
                    }
                }
                break;

            case 4:
                printf("please enter a country name\n");
                scanf("%s", buffer);
                Country countryToDeleteFrom = (Country)lookupInHashTable(Atlas, buffer);
                if(countryToDeleteFrom==NULL){
                    printf("country name not exist.\n");
                    break;
                }
                printf("please enter a city name\n");
                scanf("%s", buffer);
                if(!DoesCityExist(countryToDeleteFrom, buffer)) {
                    printf("the city not exist in this country\n");
                    break;
                }
                if(DeleteCityFromCountry(countryToDeleteFrom, buffer)==failure){
                    printf("Could not delete the city from country\n");
                }
                break;

            case 5:
                printf("please enter a country name\n");
                scanf("%s", buffer);
                Country countryToPrint = (Country)lookupInHashTable(Atlas, buffer);
                if(countryToPrint==NULL){
                    printf("country name not exist\n");
                    break;
                }
                PrintCountry(countryToPrint);
                break;

            case 6:
                printf("please enter a country name\n");
                scanf("%s", buffer);
                /*
                Country countryToDelete = (Country)lookupInHashTable(Atlas, buffer);
                if(countryToDelete==NULL){
                    printf("can't delete the country\n");
                    break;
                }
                 */
                if(removeFromHashTable(Atlas, buffer)==failure){
                    printf("can't delete the country\n");
                }
                else{
                    printf("Country deleted\n");
                }
                break;

            case 7:
                printf("please enter a country name\n");
                scanf("%s", buffer);
                Country countryToWorkWith = (Country)lookupInHashTable(Atlas, buffer);
                if(countryToWorkWith==NULL){
                    printf("country name not exist\n");
                    break;
                }
                int x,y;
                printf("please enter x and y coordinations:x,y\n");
                scanf("%d, %d", &x, &y);
                if(!IsInArea(countryToWorkWith, x, y)){
                    printf("the coordinate not in the country\n");
                }
                else{
                    printf("the coordinate in the country\n");
                }
                break;

            case 8:
                destroyHashTable(Atlas);
                finishProgram = true;
                printf("all the memory cleaned and the program is safely closed\n");
                break;

            default:
                printf("please choose a valid number\n");
                break;
        }
        if(!finishProgram){
            printf("please choose one of the following numbers:\n");
            printf("1: print Countries\n2: add country\n3: add city to country\n4: delete city from country\n"
                   "5: print country by name\n6: delete country\n7: is country in area\n8: exit\n");
        }
    }
    return 0;
}





/**
 * The function serves only in main.c to gather all countries into one array before transferring the data into the hash-table
 * @param countries
 * @param newCountry
 * @param numOfCountries
 * @return true/false
 */
bool AddCountryToCountries(Country* countries ,Country newCountry, int numOfCountries){
    if(countries == NULL || newCountry == NULL){
        return false;
    }
    countries[numOfCountries] = newCountry;
    return true;
}
