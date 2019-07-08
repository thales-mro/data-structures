typedef struct Graph {
    int **adj;
    int n;
} Graph;

typedef Graph * graph_ptr;

graph_ptr createGraph(int n);

void destroyGraph(graph_ptr g);

graph_ptr readGraph();

void insertEdge(graph_ptr g, int u, int v);

void removeEdge(graph_ptr g, int u, int v);

int hasEdge(graph_ptr g, int u, int v);

void printEdges(graph_ptr g);