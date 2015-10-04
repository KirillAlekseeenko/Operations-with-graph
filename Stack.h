//
//  Stack.h
//  Graphs
//
//  Created by Кирилл Алексеенко on 01.01.15.
//  Copyright (c) 2015 Кирилл Алексеенко. All rights reserved.
//

#ifndef __Graphs__Stack__
#define __Graphs__Stack__

#include <stdio.h>
#include "List.h"

struct Stack{
    struct List* list;
};

void Stack_Init(struct Stack* stack);
void Stack_Push(struct Stack* stack, int vertex);
int Stack_Top(struct Stack* stack);
void Stack_Pop(struct Stack* stack);
void Stack_Delete_All(struct Stack *stack);

#endif /* defined(__Graphs__Stack__) */
