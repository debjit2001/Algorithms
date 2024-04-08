#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int time = 1;
int visited[MAX_VERTICES] = {0};
int predecessor[MAX_VERTICES] = {0};
int start_time[MAX_VERTICES] = {0};
int end_time[MAX_VERTICES] = {0};

struct Graph
{
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
};

struct Graph *createGraph(int vertices)
{
    struct Graph *g = (struct Graph *)malloc(sizeof(struct Graph));
    g->numVertices = vertices;
    for (int i = 0; i < g->numVertices; i++)
    {
        for (int j = 0; j < g->numVertices; j++)
        {
            g->adjacencyMatrix[i][j] = 0;
        }
    }
    return g;
}

void addEdge(struct Graph *g, int src, int dest)
{
    g->adjacencyMatrix[src][dest] = 1;
    // For undirected graph
    g->adjacencyMatrix[dest][src] = 1;
}

void dfs(struct Graph *g, int src)
{
    visited[src] = 1;
    predecessor[src] = -1;
    start_time[src] = time;
    time++;
    for (int i = 0; i < g->numVertices; i++)
    {
        if (g->adjacencyMatrix[src][i] == 1 && visited[i] == 0)
        {
            dfs(g, i);
        }
    }
    end_time[src] = time;
    time++;
}

void printfDFS(struct Graph *g)
{
    printf("\nVertex \t visited \t start_time \t end_time");
    for (int i = 0; i < g->numVertices; i++)
    {
        printf("\n%d \t\t %d \t\t %d \t\t %d", i, visited[i], start_time[i], end_time[i]);
    }
}

void printGraph(struct Graph *g)
{
    printf("\nThe Graph is:\n");
    for (int i = 0; i < g->numVertices; i++)
    {
        for (int j = 0; j < g->numVertices; j++)
        {
            printf("%d", g->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int v;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &v);

    struct Graph *g = createGraph(v);
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 2);
    addEdge(g, 1, 3);
    addEdge(g, 2, 4);
    addEdge(g, 3, 4);

    printGraph(g);

    dfs(g, 0);

    printfDFS(g);
    return 0;
}