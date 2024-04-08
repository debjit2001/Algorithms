#include <stdio.h>
#include <stdlib.h>

#include "queueBfs.h"

#define MAX_VERTICES 100

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

void addEdge(struct Graph *g, int src, int dest)
{
    g->adjacencyMatrix[src][dest] = 1;
    // For undirected graph
    g->adjacencyMatrix[dest][src] = 1;
}

void bfs(struct Graph *g, int src, int v)
{
    printf("\nSource: %d", src);
    printf("\nVertex count: %d", v);

    int visited[v];
    int predecessor[v];
    int count = 0;

    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
        predecessor[i] = -1;
    }

    visited[src] = 1;
    predecessor[src] = -1;
    enqueue(src);

    while (!isEmpty())
    {
        int u = dequeue();
        printf("\nVisiting vertex: %d", u);
        for (int i = 0; i < v; i++)
        {
            if (g->adjacencyMatrix[u][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                predecessor[i] = u;
                enqueue(i);
                count += 1;
                printf("\nAdding vertex %d to queue", i);
            }
        }
    }

    printf("\nVertex \t visited \t predecessor");
    for (int i = 0; i < g->numVertices; i++)
    {
        printf("\n%d \t\t %d \t\t %d", i, visited[i], predecessor[i]);
    }
}

int main()
{
    int v;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &v);

    queue_size = v;
    QUEUE = (int *)malloc(queue_size * sizeof(int));

    struct Graph *g = createGraph(v);
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 2);
    addEdge(g, 1, 3);
    addEdge(g, 2, 4);
    addEdge(g, 3, 4);

    printGraph(g);

    bfs(g, 0, v);
    return 0;
}