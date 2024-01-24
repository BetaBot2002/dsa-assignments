#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct UndirectedGraph{
    int vertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} UndirectedGraph;

UndirectedGraph* initGraph(int vertices){
    UndirectedGraph *newGraph = (UndirectedGraph *)malloc(sizeof(UndirectedGraph));
    newGraph->vertices = vertices;
    for (int i = 0; i < vertices; i++){
        for (int j = 0; j < vertices; j++){
            newGraph->adjacencyMatrix[i][j]=0;
        }
    }

    return newGraph;
}

void addEdge(UndirectedGraph* graph,int start,int end){
    if(start>=0 && start<graph->vertices && end>=0 && end<graph->vertices){
        graph->adjacencyMatrix[start][end]=1;
        graph->adjacencyMatrix[end][start]=1;
    }
}

void removeEdge(UndirectedGraph* graph,int start,int end){
    if(start>=0 && start<graph->vertices && end>=0 && end<graph->vertices){
        graph->adjacencyMatrix[start][end]=0;
        graph->adjacencyMatrix[end][start]=0;
    }
}

void DFS(UndirectedGraph* graph,int vertex,bool visited[]){
    visited[vertex]=true;
    for(int i=0;i<graph->vertices;i++){
        if(graph->adjacencyMatrix[vertex][i]==1 && !visited[i]){
            DFS(graph,i,visited);
        }
    }
}

bool isConnected(UndirectedGraph* graph){
    bool *visited=(bool*)malloc(graph->vertices*sizeof(bool));
    for(int i=0;i<graph->vertices;i++){
        visited[i]=false;
    }

    DFS(graph,0,visited);
    for(int i=0;i<graph->vertices;i++){
        if(!visited[i]) return false;
    }
    return true;
}

int main() {
    int vertices = 5;
    UndirectedGraph* graph = initGraph(vertices);

    // Adding edges
    addEdge(graph, 0, 1);
    printf("Edge between vertices 0 and 1 added.\n");

    addEdge(graph, 1, 2);
    printf("Edge between vertices 1 and 2 added.\n");

    addEdge(graph, 2, 3);
    printf("Edge between vertices 2 and 3 added.\n");

    addEdge(graph, 3, 4);
    printf("Edge between vertices 3 and 4 added.\n");

    printf("Graph created with %d vertices.\n", vertices);

    // Checking if the graph is connected
    if (isConnected(graph)) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    // Removing an edge
    removeEdge(graph, 2, 3);
    printf("Edge between vertices 2 and 3 removed.\n");

    // Checking again after removing an edge
    if (isConnected(graph)) {
        printf("After removing an edge, the graph is still connected.\n");
    } else {
        printf("After removing an edge, the graph is not connected.\n");
    }

    // Adding another edge
    addEdge(graph, 1, 4);
    printf("Edge between vertices 1 and 4 added.\n");

    // Checking connectivity after adding an edge
    if (isConnected(graph)) {
        printf("After adding an edge, the graph is connected.\n");
    } else {
        printf("After adding an edge, the graph is not connected.\n");
    }

    // Freeing memory
    free(graph);

    return 0;
}

