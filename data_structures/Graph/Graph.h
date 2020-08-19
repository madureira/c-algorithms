#ifndef GRAPH_H
#define GRAPH_H

#ifdef __cplusplus
extern "C" {
#endif

#define GRAPH_INITIAL_CAPACITY 128
#define GRAPH_INVALID_ARGUMENT (void*)0
#define GRAPH_MEM_ALLOC_FAILURE (void*)0

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

    typedef struct GraphEdgesList
    {
        GraphEdge** edges;
        unsigned int size;
        unsigned int capacity;
    } GraphEdgesList;

    typedef struct Graph
    {
        GraphVertex** vertices;
        GraphEdge** edges;
        int verticesIndex;
        int edgesIndex;
        unsigned int capacity;
    } Graph;

    /*
        Creates a new empty Graph.
    */
    Graph* new_graph();

    /*
        Deletes all allocated memory for the Graph.
    */
    void free_graph(Graph* graph);

    /*
        Deletes all allocated memory for the GraphEdgesList.
    */
    void free_graph_edges_list(GraphEdgesList* edgesList);

    /*
        Adds a new vertex to the Graph.
    */
    GraphVertex* graph_add_vertex(Graph* graph, const char* vertexName, GraphVertexValue vertexValue);

    /*
        Creates a new relationship between two vertex.
    */
    void graph_add_edge(Graph* graph, GraphVertex* vertexFrom, GraphVertex* vertexTo);

    /*
        Gets an existing vertex by name.
    */
    GraphVertex* graph_get_vertex(Graph* graph, const char* vertexName);

    /*
        Gets a list of all edges that has a relationship with the vertex.
    */
    GraphEdgesList* graph_get_edges(Graph* graph, GraphVertex* vertex);

    /*
        Remove the directed edge from "vertexFrom" to "vertexTo".
    */
    unsigned int graph_remove_edge(Graph* graph, GraphVertex* vertexFrom, GraphVertex* vertexTo);

    /*
        Removes a existent vertex and all edges associated with it.
    */
    unsigned int graph_remove_vertex(Graph* graph, GraphVertex* vertex);

#ifdef __cplusplus
}
#endif

#endif // GRAPH_H