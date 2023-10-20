#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
 
#define MAX_VERTICES 50
 
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

void Graph_BFS(Graph *g, int s)
{
  if (!g)
        return;
    // Mark all the vertices as not visited
    bool visited[MAX_VERTICES];
    for (int i = 0; i < g->V; i++) {
        visited[i] = false;
    }  
    int queue[g->V]
    int front = 0, rear =0;
  
    // Mark the current node as visited and enqueue it
    visited[s] = 1;
    queue[rear++] = s;

    while (front != rear)
    {
          s = queue[front++];
          printf("%d ",s);
          for(int adj = 0; adj < g->V; adj++)
          {
                if(g->adj[s][adjacent] && !visited[s])
                {
                    visited[s] = true;
                    queue[rear++] = adjacent
                }
          }
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
 
    printf("Following is Breadth First Traversal "
           "(starting from vertex 2) \n");
    Graph_BFS(g, 2);
    Graph_destroy(g);
 
    return 0;
}