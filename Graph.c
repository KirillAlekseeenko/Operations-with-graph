//
//  Graph.c
//  Graphs
//
//  Created by Кирилл Алексеенко on 31.12.14.
//  Copyright (c) 2014 Кирилл Алексеенко. All rights reserved.
//

#include "Graph.h"
#include "Order.h"
#include "Stack.h"

int Clock;
struct Stack Out;

void Graph_Init(struct Graph* graph)
{
    (*graph).vertices = NULL;
    Clock = 1;
    (*graph).nvertices = 0;
    (*graph).nscc = 0;
    for(int i = 0;i<N;i++)
    {
        (*graph).list[i] = NULL;
        (*graph).scc[i] = -1;
        (*graph).Discovered[i] = -1;
    }
    for(int i = 0;i<N;i++)
        for(int j = 0;j<N;j++)
        {
            //(*graph).Matrix[i][j] = 0;
        }
}
void Graph_Add_Edge(struct Graph* graph, int begin, int end)
{
    List_Add(&(*graph).list[begin],end);
    //(*graph).Matrix[begin][end] = 1;
    (*graph).Discovered[begin] = 0;
    (*graph).Discovered[end] = 0;
}
void Graph_Print(struct Graph graph, FILE* file)
{
    struct List *p = NULL;
    for(int i = 0;i<N;i++)
    {
        if(graph.Discovered[i] == 0)
        {
           p = graph.list[i];
           printf("%d: ", i);
           while(p!=NULL)
           {
               printf("%d ", p->vertex);
               p = p->next;
           }
           printf("\n");
        }
    }
}
void Graph_Delete_Edge(struct Graph* graph, int begin, int end)
{
    struct List* p = (*graph).list[begin];
    struct List* prev = NULL;
    while(p!=NULL)
    {
        if(p->vertex == end)
        {
            if(prev == NULL)
            {
                (*graph).list[begin] = p->next;
                free(p);
            }
            else
            {
                prev->next = p->next;
                free(p);
            }
            return;
        }
        prev = p;
        p = p->next;
    }
}
void Graph_Delete_All(struct Graph* graph)
{
    struct List* l = (*graph).vertices;
    struct List* l1 = (*graph).vertices;
    while(l!=NULL)
    {
        l1 = l;
        l = l->next;
        free(l1);
    }
    for(int i = 0;i<N;i++)
    {
        if((*graph).list[i]!=NULL)
        {
            struct List* p = (*graph).list[i];
            struct List* p1 = NULL;
            while(p!=NULL)
            {
                p1 = p;
                p = p->next;
                free(p1);
            }
            (*graph).list[i] = p;
        }
    }
}
void ds(struct Graph *graph, int start)
{
    struct Stack stack;
    Stack_Init(&stack);
    int v = start;
    Stack_Push(&stack, v);
    struct List* p;
    do
    {
        if((*graph).Observed[v])
        {
            if(!(*graph).Processed[v])
            {
                printf("Exit from %d: \n",v);
                (*graph).Processed[v] = 1;
                (*graph).Out[v] = Clock;
                Clock++;
                Stack_Push(&Out, v);
            }
            Stack_Pop(&stack);
        }
        else
        {
            (*graph).Discovered[v] = 1;
            printf("Enter to %d: \n",v);
            p = (*graph).list[v];
            (*graph).In[v] = Clock;
            (*graph).Observed[v] = 1;
            Clock++;
            while(p!=NULL)
            {
                if((*graph).Discovered[p->vertex]==0)
                {
                    (*graph).Parent[p->vertex] = v;
                    printf("Dealing with edge %d -> %d \n",v,p->vertex);
                    Stack_Push(&stack, p->vertex);
                }
                else
                    printf("Dealing with edge %d -> %d \n",v,p->vertex);
                p = p->next;
            }
        }
    }while((v = Stack_Top(&stack)) != 0);
}
void bs(struct Graph *graph, int start)
{
    struct Order order;
    Order_Init(&order);
    int v = start;
    (*graph).Discovered[start] = 1;
    struct List* p;
    do
    {
        printf("Dealing with vertice %d: \n",v);
        p = (*graph).list[v];
        while(p!=NULL)
        {
            if((*graph).Discovered[p->vertex]==0)
            {
                (*graph).Discovered[p->vertex] = 1;
                (*graph).Parent[p->vertex] = v;
                printf("Dealing with edge %d -> %d \n",v,p->vertex);
                Order_Push(&order, p->vertex);
            }
            p = p->next;
        }
        (*graph).Observed[v] = 1;
    }while((v = Order_Pop(&order)) != 0);
}
void Graph_Breadth_Search(struct Graph *graph, int start)
{
    for(int i = 0;i<N;i++)
    {
        (*graph).Observed[i] = 0;
    }
    bs(graph, start);
    struct List *p = (*graph).vertices;
    while(p!=NULL)
    {
        if((*graph).Discovered[p->vertex]==0)
        {
            bs(graph,p->vertex);
        }
        p = p->next;
    }
}
void Graph_Depth_Search(struct Graph *graph, int start)
{
    Stack_Init(&Out);
    Clock = 1;
    for(int i = 0;i<N;i++)
    {
        (*graph).Observed[i] = 0;
        (*graph).Processed[i] = 0;
    }
    for(int i = 1;i<N;i++)
    {
        if((*graph).Discovered[i]==0)
        {
            ds(graph,i);
        }
    }
}
void Explore(struct Graph *graph, int start, int scc)
{
    struct Order order;
    Order_Init(&order);
    int v = start;
    (*graph).Discovered[start] = 1;
    struct List* p;
    do
    {
        printf("Dealing with vertice %d: \n",v);
        (*graph).scc[v] = scc;
        Stack_Pop(&Out);
        p = (*graph).list[v];
        while(p!=NULL)
        {
            if((*graph).Discovered[p->vertex]==0)
            {
                (*graph).Discovered[p->vertex] = 1;
                Order_Push(&order, p->vertex);
            }
            p = p->next;
        }
        (*graph).Observed[v] = 1;
    }while((v = Order_Pop(&order)) != 0);
}
void Create_ReversedGraph(struct Graph graph, struct Graph* ReversedGraph)
{
    struct List *p = NULL;
    for(int i = 0;i<N;i++)
    {
        if(graph.Discovered[i] == 0)
        {
            p = graph.list[i];
            while(p!=NULL)
            {
                Graph_Add_Edge(ReversedGraph, p->vertex, i);
                p = p->next;
            }
        }
    }
}
void Create_Metagraph(struct Graph *graph)
{
    struct Graph ReversedGraph;
    Graph_Init(&ReversedGraph);
    Create_ReversedGraph((*graph), &ReversedGraph);
    int start;
    for(int i = 1;i<N;i++)
    {
        if(ReversedGraph.Discovered[i]==0)
        {
            start = i;
            break;
        }
    }
    Graph_Depth_Search(&ReversedGraph, start);
    while(Stack_Top(&Out) != 0)
    {
        Explore(graph, Stack_Top(&Out), (*graph).nscc + 1);
        (*graph).nscc++;
    }
}






