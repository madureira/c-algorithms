#ifndef GRAPH_H
#define GRAPH_H

#ifdef __cplusplus
extern "C" {
#endif

#define GRAPH_INITIAL_CAPACITY 128

    typedef void* GraphVertexValue;

    typedef struct GraphVertex
    {
        char* name;
        GraphVertexValue value;
    } GraphVertex;

    typedef struct GraphEdge
    {
        GraphVertex* from;
        GraphVertex* to;
    } GraphEdge;

    typedef struct Graph
    {
        GraphVertex** vertices;
        GraphEdge** edges;
        unsigned int capacity;
        unsigned int verticesIndex;
        unsigned int edgesIndex;
    } Graph;

    Graph* new_graph();

    void free_graph(Graph* graph);

    GraphVertex* graph_add_vertex(Graph* graph, char* vertexName, GraphVertexValue vertexValue);

    void graph_add_edge(Graph* graph, GraphVertex* from, GraphVertex* to);

#ifdef __cplusplus
}
#endif

#endif // GRAPH_H