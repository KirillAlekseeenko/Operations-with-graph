//
//  Graph.h
//  Graphs
//
//  Created by Кирилл Алексеенко on 31.12.14.
//  Copyright (c) 2014 Кирилл Алексеенко. All rights reserved.
//

#ifndef __Graphs__Graph__
#define __Graphs__Graph__
#define N 1000

#include "List.h"



struct Graph{
    struct List *list[N];
    struct List *vertices;
    //int Matrix[N][N];
    int Discovered[N];
    int Observed[N];
    int Processed[N];
    int Out[N];
    int In[N];
    int Parent[N];
    int nvertices;
    int scc[N];
    int nscc;
    struct Graph *Metagraph;
};


void Graph_Init(struct Graph* graph);
void Graph_Add_Edge(struct Graph* graph, int begin, int end);
void Graph_Print(struct Graph graph, FILE* file);
void Graph_Delete_Edge(struct Graph* graph, int begin, int end);
void Graph_Delete_All(struct Graph* graph);
void Graph_Depth_Search(struct Graph *graph, int start);
void Graph_Breadth_Search(struct Graph *graph, int start);
void ds(struct Graph *graph, int start);
void bs(struct Graph *graph, int start);
void Explore(struct Graph *graph, int start, int scc);
void Create_Metagraph(struct Graph *graph);
void Create_ReversedGraph(struct Graph graph, struct Graph* ReversedGraph);

#endif /* defined(__Graphs__Graph__) */
