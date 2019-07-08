#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void memoryExit() {
    printf("There are not enough memory!");
    exit(1);
}

graph_ptr createGraph(int n) {
    int i, j;
    graph_ptr graph;

    graph = malloc(sizeof(Graph));
    if (graph == NULL)
        memoryExit();

    graph->n = n;
    graph->adj = malloc(n*sizeof(int *));
    if (graph->adj == NULL)
        memoryExit();

    for (i = 0; i < n; i++) {
        graph->adj[i] = malloc(n*sizeof(int));
        if (graph->adj[i] == NULL)
            memoryExit();

        for (j = 0; j < n; j++)
            graph->adj[i][j] = 0;
    }

    return graph;
}

void destroyGraph(graph_ptr graph) {
    int i;

    for (i = 0; i < graph->n; i++)
        free(graph->adj[i]);
    free(graph->adj);
    free(graph);
}

void insertEdge(graph_ptr g, int u, int v) {
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}

void removeEdge(graph_ptr g, int u, int v) {
    g->adj[u][v] = 0;
    g->adj[v][u] = 0;
}

int hasEdge(graph_ptr g, int u, int v) {
    return g->adj[u][v];
}

graph_ptr readGraph() {
    int m, n, i, u, v;
    graph_ptr g;

    scanf("%d %d", &n, &m);
    g = createGraph(n);
    
    for (i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        insertEdge(g, u, v);
    }

    return g;
}

void printEdges(graph_ptr g) {
    int u, v;

    for (u = 0; u < g->n; u++)
        for (v = u+1; v < g->n; v++)
            if (g->adj[u][v])
                printf("{%d,%d}\n", u, v);
}