#include <iostream>
#include <cstdlib> // Include this header for malloc

#define V 5

struct graph {
    struct vertex *point[V];
};

struct vertex {
    int end;
    struct vertex *next;
};

struct Edge {
    int end, start;
};

struct graph *create_graph(struct Edge edges[], int x) {
    int i;
    struct graph *graph = (struct graph *)malloc(sizeof(struct graph));
    for (i = 0; i < V; i++) {
        graph->point[i] = NULL;
    }
    for (i = 0; i < x; i++) {
        int start = edges[i].start;
        int end = edges[i].end;
        struct vertex *v = (struct vertex *)malloc(sizeof(struct vertex)); // Fixed typo in 'struct'
        v->end = end;
        v->next = graph->point[start];
        graph->point[start] = v;
    }
    return graph;
}

int main() {
    struct Edge edges[] = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 4}, {2, 4}, {2, 3}, {3, 1}};
    int n = sizeof(edges) / sizeof(edges[0]);
    struct graph *graph = create_graph(edges, n);
    int i;
    std::cout << "The graph created is:\n";
    for (i = 0; i < V; i++) {
        struct vertex *ptr = graph->point[i];
        
		while (ptr != NULL) {
            std::cout << "(" << i << "->" << ptr->end << ")\t";
            ptr = ptr->next;
        }
        std::cout << std::endl;
    }
    std::cout << "";
    return 0;
}
