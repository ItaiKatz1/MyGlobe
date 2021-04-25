//
// Created by itai and tomer.
//

#ifndef EX2ADVANCEDCODING_LINKEDLIST_H
#define EX2ADVANCEDCODING_LINKEDLIST_H
#include "Defs.h"

typedef struct node * Node;
typedef struct s_List * List;


//declarations on functions

List createLinkedList (copyFunction copyFunc, freeFunction freeFunc, printFunction printFunc, equalFunction equalFunc );
status destroyList (List list);
bool appendNode (List list, Element Data);
status deleteNode (List list, Element userData);
status displayList(List list);
Element searchInList(List list, Element userData);

#endif //EX2ADVANCEDCODING_LINKEDLIST_H
