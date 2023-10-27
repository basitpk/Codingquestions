#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
 
#define MAX_VERTICES 50
bool visited[MAX_VERTICES];
 
// This struct represents a directed graph using
// adjacency list representation
typedef struct Graph_t {
 
    // No. of vertices
    int V;
    bool adj[MAX_VERTICES][MAX_VERTICES];
} Graph;
 
// Constructor
Graph* Graph_create(int V)
{
    Graph* g = malloc(sizeof(Graph));
    g->V = V;
 
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            g->adj[i][j] = false;
        }
    }
 
    return g;
}
 
// Destructor
void Graph_destroy(Graph* g) { free(g); }
 
// Function to add an edge to graph
void Graph_addEdge(Graph* g, int v, int w)
{
    // Add w to v’s list.
    g->adj[v][w] = true;
}

void Graph_DFS(Graph *g, int s)
{
    if (!g)
        return;
       
    // Mark the value s as visited
    visited[s] = true;
    printf("%d ",s);
        
    for (int adjacent=0; adjacent < g->V; adjacent++)
    {
        if (visited[g->adj[s][adjacent]])
                continue;
        else
            Graph_DFS(g, g->adj[s][adjacent]) // Traverse recursively all neigbours
    }    
}


// Driver code
int main()
{
    // Create a graph
    Graph* g = Graph_create(4);
    Graph_addEdge(g, 0, 1);
    Graph_addEdge(g, 0, 2);
    Graph_addEdge(g, 1, 2);
    Graph_addEdge(g, 2, 0);
    Graph_addEdge(g, 2, 3);
    Graph_addEdge(g, 3, 3);
 
    printf("Following is Depth First Traversal "
           "(starting from vertex 2) \n");
    Graph_DFS(g, 2);
    Graph_destroy(g);
 
    return 0;
}