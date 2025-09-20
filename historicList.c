#include "historicList.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define LNULL NULL


void createListH(tListH *l){
//crea una lista vacia
    *l = LNULL;
}

bool isEmptyListH(tListH l){
//comprueba si la lista está vacía
    return (l == LNULL);
}

LPosH firstH(tListH l){
//devuelve el primer elemento de la lista
    return l;
}

LPosH nextH(LPosH p, tListH l){
//devuelve el nodo siguiente de la posición insertada
    return p->next;
}

bool createNode(LPosH * p){
//funcion auxiliar de insertItem
    *p = malloc(sizeof(struct tNode));

    return *p != LNULL;
}

bool insertItemH(tItemH d, tListH *l){
//inserta un elemento en la lista

    LPosH n, r;

    //caso que no haya memoria
    if (!createNode(&n)) return false;
    //caso que haya suficiente memoria
    else{
        n->data = d;
        n->next = NULL;

        if(*l == LNULL){
        //la lista está vacía
            *l = n;
        }
        else{
        //iserta al final
            for(r = *l; r->next != LNULL; r = r->next);
            r->next = n;
        }

        return true;
    }
}

void deleteAtPositionH(LPosH p, tListH *l){
    
}

void clearListH(tListH *l){
//elimina todos los elementos de la lista
    LPosH p;
    while(*l != LNULL){
        p = *l;
        *l = (*l)->next;
        free(p);
    }
}

tItemH getItemH(LPosH p, tListH l){
//devuelve el elemento de la posicion insertada
    return p->data;
}