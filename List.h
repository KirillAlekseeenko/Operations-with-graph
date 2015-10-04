//
//  List.h
//  Graphs
//
//  Created by Кирилл Алексеенко on 31.12.14.
//  Copyright (c) 2014 Кирилл Алексеенко. All rights reserved.
//

#ifndef __Graphs__List__
#define __Graphs__List__

#include <stdio.h>
#include <stdlib.h>

struct List
{
    struct List*next;
    int vertex;
};

void List_Add(struct List** list, int vertex);

#endif /* defined(__Graphs__List__) */
