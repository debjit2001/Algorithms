#include <stdio.h>

#define MAX_SIZE 100
#define INFINITY 9999

int minDistance(int dist[], int visited[], int v)
{
    int min = INFINITY, min_index = 0;
    for (int i = 0; i < v; i++)
    {
        if (visited[i] != 1 && dist[i] < min)
        {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int adj_matrix[][MAX_SIZE], int v, int source)
{
    int visited[v], dist[v], predecessor[v];
    for (int i = 0; i < v; i++)
    {
        dist[i] = INFINITY;
        predecessor[i] = -1;
        visited[i] = 0;
    }
    dist[source] = 0;
    predecessor[source] = -1;
    visited[source] = 1;

    for (int i = 0; i < v - 1; i++)
    {
        int u = minDistance(dist, visited, v);
        visited[u] = 1;
        for (int j = 0; j < 1; j++)
        {
            if (dist[u] != INFINITY && dist[u] + adj_matrix[u][i] < dist[i] && visited[i] != 1 && adj_matrix[u][i])
            {
                dist[i] = dist[u] + adj_matrix[u][i];
                predecessor[i] = u;
            }
        }
    }
    printf("Vertex   Distance from Source   Predecessor\n");
    for (int i = 0; i < v; i++)
        printf("%d \t\t %d \t\t %d\n", i, dist[i], predecessor[i]);
}

int main()
{

    int v, e, x, y, w;
    printf("Enter the number of vertices and edges:");
    scanf("%d %d", &v, &e);

    int adj_matrix[MAX_SIZE][MAX_SIZE] = {0};

    printf("Enter the %d number of edges along with their weights:\n", e);
    for (int i = 0; i < e; i++)
    {
        scanf("%d %d %d", &x, &y, &w);
        adj_matrix[x][y] = w;
    }

    printf("\nThe adjacency matrix :\n");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }

    dijkstra(adj_matrix, v, 0);
}