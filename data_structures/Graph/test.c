#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "Graph.h"

#define ASSERT_NULL(a) assert((a) == NULL)
#define ASSERT_NOT_NULL(a) assert((a) != NULL)
#define ASSERT_INT_EQUALS(a, b) assert((a) == (b))
#define ASSERT_STRING_EQUALS(a, b) assert(strcmp(((const char*)(a)), ((const char*)(b))) == 0)
#define TEST_DONE printf_s("Test: \"%s\" - success\n", __func__);

static void print_graph(Graph* graph);

void test_new_graph()
{
    Graph* graph = new_graph();

    ASSERT_INT_EQUALS(graph->capacity, GRAPH_INITIAL_CAPACITY);
    ASSERT_INT_EQUALS(graph->verticesIndex, -1);
    ASSERT_INT_EQUALS(graph->edgesIndex, -1);
    ASSERT_NOT_NULL(graph->vertices);
    ASSERT_NOT_NULL(graph->edges);

    free_graph(graph);

    TEST_DONE
}

void test_graph_add_vertex()
{
    Graph* graph = new_graph();

    graph_add_vertex(graph, "A", "a");
    graph_add_vertex(graph, "B", "b");
    graph_add_vertex(graph, "C", "c");

    ASSERT_INT_EQUALS(graph->verticesIndex, 2);

    free_graph(graph);

    TEST_DONE
}

void test_graph_get_vertex()
{
    Graph* graph = new_graph();

    graph_add_vertex(graph, "A", "a");

    GraphVertex* found = graph_get_vertex(graph, "A");

    ASSERT_STRING_EQUALS(found->name, "A");
    ASSERT_STRING_EQUALS((char*)found->value, "a");
    ASSERT_NULL(graph_get_vertex(graph, "Z"));

    free_graph(graph);

    TEST_DONE
}

void test_graph_add_edge()
{
    Graph* graph = new_graph();

    GraphVertex* A = graph_add_vertex(graph, "A", "a");
    GraphVertex* B = graph_add_vertex(graph, "B", "b");
    GraphVertex* C = graph_add_vertex(graph, "C", "c");

    graph_add_edge(graph, A, B);
    graph_add_edge(graph, A, C);
    graph_add_edge(graph, B, C);
    graph_add_edge(graph, C, A);

    ASSERT_INT_EQUALS(graph->edgesIndex, 3);

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

void test_graph_remove_edge()
{
    Graph* graph = new_graph();

    GraphVertex* A = graph_add_vertex(graph, "A", "a");
    GraphVertex* B = graph_add_vertex(graph, "B", "b");
    GraphVertex* C = graph_add_vertex(graph, "C", "c");

    graph_add_edge(graph, A, B);
    graph_add_edge(graph, A, C);
    graph_add_edge(graph, B, C);
    graph_add_edge(graph, C, A);

    ASSERT_INT_EQUALS(graph->edgesIndex, 3);

    unsigned int success = graph_remove_edge(graph, A, C);

    ASSERT_INT_EQUALS(success, 1);
    ASSERT_INT_EQUALS(graph->edgesIndex, 2);

    ASSERT_STRING_EQUALS(graph->edges[0]->from->name, "A");
    ASSERT_STRING_EQUALS(graph->edges[0]->to->name, "B");

    ASSERT_STRING_EQUALS(graph->edges[1]->from->name, "B");
    ASSERT_STRING_EQUALS(graph->edges[1]->to->name, "C");

    ASSERT_STRING_EQUALS(graph->edges[2]->from->name, "C");
    ASSERT_STRING_EQUALS(graph->edges[2]->to->name, "A");

    success = graph_remove_edge(graph, C, B);

    ASSERT_INT_EQUALS(success, 0);
    ASSERT_INT_EQUALS(graph->edgesIndex, 2);

    free_graph(graph);

    TEST_DONE
}

void test_graph_remove_vertex()
{
    Graph* graph = new_graph();

    GraphVertex* A = graph_add_vertex(graph, "A", "a");
    GraphVertex* B = graph_add_vertex(graph, "B", "b");
    GraphVertex* C = graph_add_vertex(graph, "C", "c");

    graph_add_edge(graph, A, B);
    graph_add_edge(graph, A, C);
    graph_add_edge(graph, B, C);
    graph_add_edge(graph, C, A);

    free_graph(graph);

    TEST_DONE
}

int main()
{
    printf_s("Graph tests\n\n");

    test_new_graph();
    test_graph_add_vertex();
    test_graph_get_vertex();
    test_graph_add_edge();
    test_graph_get_edges();
    test_graph_remove_edge();
    test_graph_remove_vertex();

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