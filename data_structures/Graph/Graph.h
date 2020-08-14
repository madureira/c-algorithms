#ifndef GRAPH_H
#define GRAPH_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef void* GraphNodeValue;

    typedef struct  GraphNode
    {
        GraphNodeValue value;
    } GraphNode;

    GraphNode* graph_create_node(GraphNodeValue value);

#ifdef __cplusplus
}
#endif

#endif // GRAPH_H