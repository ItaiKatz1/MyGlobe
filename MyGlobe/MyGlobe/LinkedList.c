//
// Created by itai and tomer.
//
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

//Linked List Node
struct node{
    Element Data;
    Node next;
};//
// Created by tomer on 01/12/2018.
//

struct s_List{
    Node head;
    Node tail;
    copyFunction copyFunc;
    freeFunction freeFunc;
    printFunction printFunc;
    equalFunction equalFunc;
};

/**
 * creates an element of a node
 * @param Data
 * @param list
 * @return pointer to the new node
 */
Node createNode (Element Data, List list) {
    if(Data==NULL || list==NULL) {
        return NULL;
    }
    Node ptr = (Node) malloc(sizeof(struct node));
    if (ptr==NULL){
        return NULL;
    }
    ptr->Data = list->copyFunc(Data);
    ptr->next = NULL;
    return ptr;
}

/**
 * creates a new linked list
 * @param copyFunc
 * @param freeFunc
 * @param printFunc
 * @param equalFunc
 * @return ptr, new linked list
 */
List createLinkedList (copyFunction copyFunc, freeFunction freeFunc, printFunction printFunc, equalFunction equalFunc){
    if (copyFunc==NULL||freeFunc==NULL||printFunc==NULL||equalFunc==NULL){
        return NULL;
    }
    List ptr = (List)malloc((sizeof(struct s_List)));
    if(ptr==NULL){
        return NULL;
    }
    ptr->copyFunc=copyFunc;
    ptr->freeFunc=freeFunc;
    ptr->equalFunc=equalFunc;
    ptr->printFunc=printFunc;
    ptr->head=NULL;
    ptr->tail=NULL;
    return ptr;
}

/**
 * Destroys the linked list and cleans the memory of all nodes
 * @param list
 */
status destroyList (List list){
    if (list==NULL){
        return failure;
    }
    Node temp = NULL;
    while(!(list->head==NULL)){
        temp=list->head->next;
        list->freeFunc(list->head->Data);
        // free(list->head->Data);
        free(list->head);
        list->head=NULL;
        list->head=temp;
    }
    free(list);
    return success;
}

/**
 * adding data as a new element to the linked list
 * @param list
 * @param Data
 * @return true/false
 */
bool appendNode (List list, Element Data) {
    if(Data==NULL||list==NULL) {
        return false;
    }
    Node temp = createNode(Data, list);
    if(temp==NULL){
        return false;
    }
    if(list->head==NULL){ // if the list is empty
        list->tail = temp;
        list->head = temp;
    } else{
        list->tail->next = temp;
        list->tail = list->tail->next;
    }
    return true;
}


/**
 * seaarches if the data exists in the linked list and deletes it
 * @param list
 * @param userData
 * @return status - failure or success
 */
status deleteNode (List list, Element userData){
    if(userData==NULL||list==NULL){
        return failure;
    }
    bool flag=false;
    Node temp = list->head;
    Node beforeTemp = NULL;
    if(temp != NULL){ //if the list includes only one nude or if the data we want to delete is located at the first node of the list
        if(list->equalFunc(temp->Data,userData)) {
            list->freeFunc(temp->Data);
            // free(temp->Data); //need to understand why you cant free the pointer data
            list->head = temp->next;
            free(temp);
            flag = true;
        }
    }
    if(!flag) {
        beforeTemp = temp;
        temp = temp->next;
    }
    while(!flag && (temp->next != NULL)) {
        if (list->equalFunc(temp->Data, userData)) {
            list->freeFunc(temp->Data);
            // free(temp->Data);
            beforeTemp->next = temp->next;
            free(temp);
            flag = true;
        }
        beforeTemp = temp;
        temp = temp->next;
    }
    if(!flag && temp->next == NULL && temp!=NULL){ // if we still didn't find the data and we reached the last node in the list, or if the list contained only one node
        if(list->equalFunc(temp->Data,userData)) {
            list->freeFunc(temp->Data);
            // free(temp->Data);
            list->tail = beforeTemp;
            free(temp);
            list->tail->next = NULL;
            flag = true;
        }
    }
    if(!flag){
        return failure;
    }
    return success;
}
/**
 * prints all information within the linked list
 * @param list
 */
status displayList(List list){
    if(list==NULL){
        return failure;
    }
    Node temp = list->head;
    while(temp != NULL){
        list->printFunc(temp->Data);
        temp=temp->next;
    }
    return success;
}


/**
 * searches if the data exists within the linked list
 * @param list
 * @param userData
 * @return a pointer to the data
 */
Element searchInList(List list, Element userData){
    if(list==NULL||userData==NULL){
        return NULL;
    }
    Node temp = list->head;
    while(temp != NULL){
        if(list->equalFunc(temp->Data,userData)){
            return temp->Data; //bug in this line - returns data, key value pair, and NOT a country
        }
        else{
            temp=temp->next;
        }
    }
    return NULL;
}
