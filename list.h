#ifndef SO_LIST_H
#define SO_LIST_H
#define LNULL NULL 

#define MAXCMDLINE 1024

#include <stdbool.h>


typedef char line[MAXCMDLINE];

typedef struct tItemL {
    line cmdline;
} tItemL;

typedef struct tNode * LPos;

struct tNode{
    tItemL data;
    LPos next;
};

typedef LPos tList;

// funciones
void createList(tList*);
bool insertItem(tItemL, tList*);
LPos first(tList);
LPos next(LPos, tList);
tItemL getItem(LPos, tList);
bool isEmptyList(tList);
void clearList(tList*);

#endif