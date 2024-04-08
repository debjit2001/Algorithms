#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int vertexNumber;
    struct ListNode* next;
};

struct Graph {
    int v;
    int e;
    struct ListNode** adj;
};

struct Graph* adjListOfGraph() {
    int i, x, y;
    struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph));
    if (!g) {
        printf("Memory error");
        return NULL;
    }

    printf("Enter number of vertices: ");
    scanf("%d", &g->v);
    printf("Enter number of edges: ");
    scanf("%d", &g->e);

    g->adj = malloc(g->v * sizeof(struct ListNode *));
    for (int i = 0; i < g->v; i++) {
        g->adj[i] = (struct ListNode*)malloc(sizeof(struct ListNode *));
        g->adj[i]->vertexNumber = i;
        g->adj[i]->next = NULL;
    }

    for(int i=0;i<g->e;i++){
        printf("Reading edges:");
        scanf("%d %d",&x, &y);
        struct ListNode* temp1 = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp1->vertexNumber = y;
        if(g->adj[x]->next==NULL){
            g->adj[x]->next=temp1;
            temp1->next=NULL;
        }
        else{
            temp1->next = g->adj[x]->next;
            g->adj[x]->next = temp1;
        }
    }

    return g;
}

int main() {
    struct Graph* graph = adjListOfGraph();
    struct ListNode *current =NULL;
    if (graph != NULL) {
        printf("Graph created with %d vertices and %d edges.\n", graph->v, graph->e);
        
        printf("Adjacency Lists:\n");
        for (int i = 0; i < graph->v; i++) {
            printf("Vertex %d: ", i);
            current= graph->adj[i]->next; 
            while (current!= NULL) {
                printf("%d ", current->vertexNumber);
                current = current->next;
            }
            printf("\n");
        }
    }
    return 0;
}
