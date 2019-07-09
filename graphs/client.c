#include <stdio.h>
#include "graph.h"

int main() {
    graph_ptr g;

    printf("Please insert two integers, representing the number of vertices and the number of edges, followed by the edges: ");

    g = readGraph();

    printEdges(g);
    printf("The most popular vertex is %d\n", mostPopular(g));

    destroyGraph(g);
    return 0;
}