#include "Graph.h"
#include <stdlib.h>

Graph* new_graph()
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));

    if (graph == NULL)
    {
        return NULL;
    }

    graph->capacity = GRAPH_INITIAL_CAPACITY;
    graph->verticesIndex = 0;
    graph->edgesIndex = 0;

    graph->vertices = calloc((size_t)graph->capacity, sizeof(GraphVertex*));

    if (graph->vertices == NULL)
    {
        free(graph);
        return NULL;
    }

    graph->edges = calloc((size_t)graph->capacity, sizeof(GraphEdge*));

    if (graph->edges == NULL)
    {
        free(graph->vertices);
        free(graph);
        return NULL;
    }

    for (int i = 0; i < graph->capacity; i++)
    {
        graph->vertices[i] = NULL;
        graph->edges[i] = NULL;
    }

    return graph;
}

void free_graph(Graph* graph)
{
    if (graph != NULL)
    {
        for (int i = 0; i < graph->capacity; i++)
        {
            GraphVertex* vertex = graph->vertices[i];
            if (vertex != NULL)
            {
                free(vertex);
            }
        }

        for (int i = 0; i < graph->capacity; i++)
        {
            GraphEdge* edge = graph->edges[i];
            if (edge != NULL)
            {
                free(edge);
            }
        }

        free(graph->vertices);
        free(graph->edges);
        free(graph);
        graph = NULL;
    }
}

GraphVertex* graph_add_vertex(Graph* graph, char* vertexName, GraphVertexValue vertexValue)
{
    if (graph == NULL || vertexName == NULL || vertexValue == NULL)
    {
        return NULL;
    }

    GraphVertex* vertex = (GraphVertex*)malloc(sizeof(GraphVertex));

    if (vertex == NULL)
    {
        return NULL;
    }

    vertex->name = vertexName;
    vertex->value = vertexValue;

    graph->vertices[graph->verticesIndex++] = vertex;

    return vertex;
}

void graph_add_edge(Graph* graph, GraphVertex* from, GraphVertex* to)
{
    if (graph == NULL || from == NULL || to == NULL)
    {
        return NULL;
    }

    GraphEdge* edge = (GraphEdge*)malloc(sizeof(GraphEdge));

    if (edge == NULL)
    {
        return NULL;
    }

    edge->from = from;
    edge->to = to;

    graph->edges[graph->edgesIndex++] = edge;
}