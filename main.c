//
//  main.c
//  Graphs
//
//  Created by Кирилл Алексеенко on 31.12.14.
//  Copyright (c) 2014 Кирилл Алексеенко. All rights reserved.
//

#include "Graph.h"


int main(int argc, const char * argv[]) {
    
    struct Graph graph;
    Graph_Init(&graph);
    printf("1.Add edge\n2.Print graph\n3.Delete edge\n4.Depth search\n5.Breadth search.\n6.Create metagraph\n7.Exit\n");
    int menu;
    printf("Type number: ");
    scanf("%d", &menu);
    while(menu!=7)
    {
        switch(menu)
        {
            case 1:
            {
                printf("Type begin and end: ");
                int begin, end;
                scanf("%d %d",&begin, &end);
                Graph_Add_Edge(&graph, begin, end);
                break;
            }
            case 2:
            {
                Graph_Print(graph, stdout);
                break;
            }
            case 3:
            {
                printf("Type begin and end: ");
                int begin, end;
                scanf("%d %d",&begin, &end);
                Graph_Delete_Edge(&graph, begin, end);
                break;
            }
            case 4:
            {
                Graph_Depth_Search(&graph, 1);
                break;
            }
            case 5:
            {
                Graph_Breadth_Search(&graph, 1);
                break;
            }
            case 6:
            {
                Create_Metagraph(&graph);
                printf("%d \n",graph.nscc);
                for(int i = 0;i<N;i++)
                {
                    if (graph.scc[i]!= -1)
                    {
                        printf("%d : %d\n",graph.scc[i],i);
                    }
                }
                break;
            }

        }
        printf("Type number: ");
        scanf("%d", &menu);
    }
    Graph_Delete_All(&graph);
    return 0;
}














