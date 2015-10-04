//
//  Stack.c
//  Graphs
//
//  Created by Кирилл Алексеенко on 01.01.15.
//  Copyright (c) 2015 Кирилл Алексеенко. All rights reserved.
//

#include "Stack.h"

void Stack_Init(struct Stack* stack)
{
    (*stack).list = NULL;
}
void Stack_Push(struct Stack* stack, int vertex)
{
    List_Add(&(*stack).list, vertex);
}
void Stack_Pop(struct Stack* stack)
{
    if((*stack).list!=NULL)
    {
        struct List* p = (*stack).list;
        (*stack).list = p->next;
        free(p);
    }
}
int Stack_Top(struct Stack *stack)
{
    if((*stack).list!=NULL)
    {
        int l = (*stack).list->vertex;
        return l;
    }
    return 0;
}
void Stack_Delete_All(struct Stack *stack)
{
    if((*stack).list!=NULL)
    {
        struct List* p = (*stack).list;
        struct List* p1 = NULL;
        while(p!=NULL)
        {
            p1 = p;
            free(p1);
            p = p->next;
        }
        (*stack).list = p;
    }
}