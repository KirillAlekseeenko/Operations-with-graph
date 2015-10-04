//
//  Order.c
//  Graphs
//
//  Created by Кирилл Алексеенко on 01.01.15.
//  Copyright (c) 2015 Кирилл Алексеенко. All rights reserved.
//

#include "Order.h"

void Order_Init(struct Order *order)
{
    (*order).begin = NULL;
    (*order).end = NULL;
}
void Order_Push(struct Order *order, int vertex)
{
    struct List* p = (struct List*)malloc(sizeof(struct List));
    p->vertex = vertex;
    p->next = NULL;
    if((*order).end == NULL)
    {
        (*order).end = p;
        (*order).begin = p;
        return;
    }
    (*order).begin->next = p;
    (*order).begin = (*order).begin->next;
}
int Order_Pop(struct Order *order)
{
    if((*order).end == NULL)
    {
        return 0;
    }
    struct List* p1 = (*order).end;
    int v = p1->vertex;
    (*order).end = p1->next;
    free(p1);
    return v;
}
void Order_DeleteAll(struct Order *order)
{
    struct List* p = (*order).end;
    struct List* p1 = NULL;
    while(p!=NULL)
    {
        p1 = p;
        p = p->next;
        free(p1);
    }
}