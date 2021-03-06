#include "Graph.h"
#include <stdlib.h>

Graph* new_graph()
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));

    if (graph == NULL)
    {
        return GRAPH_MEM_ALLOC_FAILURE;
    }

    graph->capacity = GRAPH_INITIAL_CAPACITY;
    graph->verticesIndex = -1;
    graph->edgesIndex = -1;

    graph->vertices = calloc((size_t)graph->capacity, sizeof(GraphVertex*));

    if (graph->vertices == NULL)
    {
        free(graph);
        return GRAPH_MEM_ALLOC_FAILURE;
    }

    graph->edges = calloc((size_t)graph->capacity, sizeof(GraphEdge*));

    if (graph->edges == NULL)
    {
        free(graph->vertices);
        free(graph);
        return GRAPH_MEM_ALLOC_FAILURE;
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

            GraphEdge* edge = graph->edges[i];
            if (edge != NULL)
            {
                free(edge);
            }
        }

        free(graph->vertices);
        free(graph->edges);
        free(graph);
    }
}

void free_graph_edges_list(GraphEdgesList* edgesList)
{
    if (edgesList != NULL)
    {
        free(edgesList->edges);
        free(edgesList);
    }
}

GraphVertex* graph_add_vertex(Graph* graph, const char* vertexName, GraphVertexValue vertexValue)
{
    if (graph == NULL || vertexName == NULL || vertexValue == NULL)
    {
        return GRAPH_INVALID_ARGUMENT;
    }

    GraphVertex* vertex = (GraphVertex*)malloc(sizeof(GraphVertex));

    if (vertex == NULL)
    {
        return GRAPH_MEM_ALLOC_FAILURE;
    }

    vertex->name = vertexName;
    vertex->value = vertexValue;

    graph->vertices[++graph->verticesIndex] = vertex;

    return vertex;
}

void graph_add_edge(Graph* graph, GraphVertex* vertexFrom, GraphVertex* vertexTo)
{
    if (graph == NULL || vertexFrom == NULL || vertexTo == NULL)
    {
        return GRAPH_INVALID_ARGUMENT;
    }

    GraphEdge* edge = (GraphEdge*)malloc(sizeof(GraphEdge));

    if (edge == NULL)
    {
        return GRAPH_MEM_ALLOC_FAILURE;
    }

    edge->from = vertexFrom;
    edge->to = vertexTo;

    graph->edges[++graph->edgesIndex] = edge;
}

GraphVertex* graph_get_vertex(Graph* graph, const char* vertexName)
{
    if (graph == NULL || vertexName == NULL)
    {
        return GRAPH_INVALID_ARGUMENT;
    }

    for (int i = 0; i <= graph->verticesIndex; i++)
    {
        GraphVertex* vertex = graph->vertices[i];
        if (vertex != NULL && vertex->name == vertexName)
        {
            return vertex;
        }
    }

    return NULL;
}

GraphEdgesList* graph_get_edges(Graph* graph, GraphVertex* vertex)
{
    if (graph == NULL || vertex == NULL)
    {
        return GRAPH_INVALID_ARGUMENT;
    }

    GraphEdgesList* edgesList = (GraphEdgesList*)malloc(sizeof(GraphEdgesList));

    if (edgesList == NULL)
    {
        return GRAPH_MEM_ALLOC_FAILURE;
    }

    edgesList->capacity = GRAPH_INITIAL_CAPACITY;
    edgesList->size = 0;
    edgesList->edges = calloc((size_t)edgesList->capacity, sizeof(GraphEdge*));

    if (edgesList->edges == NULL)
    {
        free(edgesList);
        return GRAPH_MEM_ALLOC_FAILURE;
    }

    for (int i = 0; i <= graph->edgesIndex; i++)
    {
        GraphEdge* edge = graph->edges[i];
        if (edge != NULL && (edge->from == vertex || edge->to == vertex))
        {
            edgesList->edges[edgesList->size++] = edge;
        }
    }

    return edgesList;
}

unsigned int graph_remove_edge(Graph* graph, GraphVertex* vertexFrom, GraphVertex* vertexTo)
{
    if (graph == NULL || vertexFrom == NULL || vertexTo == NULL || graph->edgesIndex == -1)
    {
        return 0;
    }

    for (int i = 0; i <= graph->edgesIndex; i++)
    {
        if (graph->edges[i] != NULL && graph->edges[i]->from == vertexFrom && graph->edges[i]->to == vertexTo)
        {
            memmove(&graph->edges[i], &graph->edges[i + 1], (graph->edgesIndex - i) * sizeof(graph->edges[0]));
            graph->edges[graph->edgesIndex--] = NULL;

            return 1;
        }
    }

    return 0;
}

unsigned int graph_remove_vertex(Graph* graph, GraphVertex* vertex)
{
    return 0;
}