#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt_hash.h"
#define TABLESIZE 3751
/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry **entryArray=NULL;
unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;
    while (*str) {
        hash = hash * seed + (*str++);
    }
    return (hash % TABLESIZE);
}
entry *findName(char lastName[], entry *pHead)
{
    unsigned int hashvalue = BKDRHash(lastName);
    pHead = *(entryArray+hashvalue);
    while (pHead != NULL) {
        if (strcasecmp(lastName, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    if(entryArray == NULL) {
        entryArray = (entry **)malloc((TABLESIZE+1)*sizeof(entry *));
    }
    unsigned int hashvalue = BKDRHash(lastName);
    e = *(entryArray+hashvalue);
    if(e == NULL) {
        e = (entry *) malloc(sizeof(entry));
    }
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;
    *(entryArray+hashvalue) = e;
    return e;
}
