//
//  List.c
//  Graphs
//
//  Created by Кирилл Алексеенко on 31.12.14.
//  Copyright (c) 2014 Кирилл Алексеенко. All rights reserved.
//

#include "List.h"

void List_Add(struct List** list, int vertex)
{
    struct List* p = (struct List*)malloc(sizeof(struct List));
    p->vertex = vertex;
    p->next = (*list);
    (*list) = p;
}