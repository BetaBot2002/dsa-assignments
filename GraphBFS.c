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

void BFS(UndirectedGraph* graph,int start,bool visited[]){
    int *queue=(int*)malloc(graph->vertices*sizeof(int));
    int front = 0, rear = 0;

    printf("%d ", start);
    visited[start] = true;
    queue[rear++] = start;

    while (front < rear) {
        int currentVertex = queue[front++];
        
        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                printf("%d ", i);
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int vertices = 5;
    UndirectedGraph* graph = initGraph(vertices);

    // Adding edges
    addEdge(graph, 0, 1);
    printf("Edge between vertices 0 and 1 added.\n");

    addEdge(graph, 0, 3);
    printf("Edge between vertices 0 and 3 added.\n");

    addEdge(graph, 1, 2);
    printf("Edge between vertices 1 and 2 added.\n");

    addEdge(graph, 1, 3);
    printf("Edge between vertices 1 and 3 added.\n");

    addEdge(graph, 3, 4);
    printf("Edge between vertices 3 and 4 added.\n");

    addEdge(graph, 4, 1);
    printf("Edge between vertices 4 and 1 added.\n");

    printf("Graph created with %d vertices.\n", vertices);

    bool *visited=(bool*)malloc(graph->vertices*sizeof(bool));
    for(int i=0;i<graph->vertices;i++){
        visited[i]=false;
    }

    printf("BFS traversal starting from vertex 0: ");
    BFS(graph, 0, visited);
    printf("\n");

    free(graph);
    return 0;
}
