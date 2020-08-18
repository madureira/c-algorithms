#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "Graph.h"

#define ASSERT_NULL(a) assert((a) == NULL)
#define ASSERT_INT_EQUALS(a, b) assert((a) == (b))
#define ASSERT_STRING_EQUALS(a, b) assert(strcmp(((const char*)(a)), ((const char*)(b))) == 0)
#define TEST_DONE printf_s("Test: \"%s\" - success\n", __func__);

static void print_graph(Graph* graph);

void test_new_graph()
{
    Graph* graph = new_graph();

    GraphVertex* A = graph_add_vertex(graph, "A", "a");
    GraphVertex* B = graph_add_vertex(graph, "B", "b");
    GraphVertex* C = graph_add_vertex(graph, "C", "c");

    graph_add_edge(graph, A, B);
    graph_add_edge(graph, A, C);
    graph_add_edge(graph, B, C);

    free_graph(graph);

    TEST_DONE
}

void test_graph_get_vertex()
{
    Graph* graph = new_graph();

    graph_add_vertex(graph, "A", "a");
    graph_add_vertex(graph, "B", "b");
    graph_add_vertex(graph, "C", "c");

    GraphVertex* found = graph_get_vertex(graph, "B");

    ASSERT_STRING_EQUALS(found->name, "B");
    ASSERT_STRING_EQUALS((char*)found->value, "b");
    ASSERT_NULL(graph_get_vertex(graph, "Z"));

    free_graph(graph);

    TEST_DONE
}

void test_graph_get_edges()
{
    Graph* graph = new_graph();

    GraphVertex* A = graph_add_vertex(graph, "A", "a");
    GraphVertex* B = graph_add_vertex(graph, "B", "b");
    GraphVertex* C = graph_add_vertex(graph, "C", "c");

    graph_add_edge(graph, A, B);
    graph_add_edge(graph, A, C);
    graph_add_edge(graph, B, C);
    graph_add_edge(graph, C, A);

    GraphEdgesList* edgesList = graph_get_edges(graph, A);

    ASSERT_INT_EQUALS(edgesList->size, 3);

    ASSERT_STRING_EQUALS(edgesList->edges[0]->from->name, "A");
    ASSERT_STRING_EQUALS(edgesList->edges[0]->to->name, "B");

    ASSERT_STRING_EQUALS(edgesList->edges[1]->from->name, "A");
    ASSERT_STRING_EQUALS(edgesList->edges[1]->to->name, "C");

    ASSERT_STRING_EQUALS(edgesList->edges[2]->from->name, "C");
    ASSERT_STRING_EQUALS(edgesList->edges[2]->to->name, "A");

    free_graph_edges_list(edgesList);
    free_graph(graph);

    TEST_DONE
}

int main()
{
    printf_s("Graph tests\n\n");

    test_new_graph();
    test_graph_get_vertex();
    test_graph_get_edges();

    return 0;
}

void print_graph(Graph* graph)
{
    for (int i = 0; i < graph->verticesIndex; i++)
    {
        GraphVertex* vertex = graph->vertices[i];

        printf_s("[%s](%s)", vertex->name, (char*)vertex->value);

        int hasConnection = 0;
        for (int j = 0; j < graph->edgesIndex; j++)
        {
            GraphEdge* edge = graph->edges[j];
            if (edge->from == vertex)
            {
                if (hasConnection == 0) {
                    printf_s(" -> { %s", (char*)edge->to->name);
                    hasConnection++;
                }
                else
                {
                    printf_s(", %s", (char*)edge->to->name);
                }
            }
        }

        printf_s("%s\n", hasConnection > 0 ? " }" : "");
    }
}