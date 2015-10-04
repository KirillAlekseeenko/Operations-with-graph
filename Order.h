//
//  Order.h
//  Graphs
//
//  Created by Кирилл Алексеенко on 01.01.15.
//  Copyright (c) 2015 Кирилл Алексеенко. All rights reserved.
//

#ifndef __Graphs__Order__
#define __Graphs__Order__

#include <stdio.h>
#include "List.h"

struct Order
{
    struct List *begin;
    struct List *end;
};

void Order_Init(struct Order *order);
void Order_Push(struct Order *order, int vertex);
int Order_Pop(struct Order *order);
void Order_DeleteAll(struct Order *order);

#endif /* defined(__Graphs__Order__) */
