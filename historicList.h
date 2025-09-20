#ifndef historicList_h
#define historicList_h
#define HNULL NULL
#define MAX 1024


typedef struct tItemH{
    char command[1024]; 
} tItemH; 

typedef struct tNode * LPosH;

struct tNode{
    tItemH data;
    LPosH next;
};

typedef LPosH tListH;

void createListH(tListH*);
bool isEmptyListH(tListH); 
LPosH nextH(LPosH, tListH);
tItemH firstH(tListH); 
bool insertItemH(tItemH d, tListH *l);
void clearListH(tListH *l); 
tItemH getItemH(LPosH p, tListH l); 

#endif