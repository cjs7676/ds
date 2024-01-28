#include <iostream>
#include <queue>
#define NODE 6
using namespace std;

typedef struct node {
    int val;
    int state;
} node;

int graph[NODE][NODE] = {
    {0, 1, 1, 1, 0, 0},
    {0, 0, 0, 1, 1, 0},
    {1, 0, 0, 1, 0, 1},
    {1, 1, 1, 0, 1, 1},
    {0, 1, 0, 1, 0, 1},
    {0, 0, 1, 1, 1, 0},
};

void bfs(node *vertices, node s) {
    queue<node> que;
    que.push(s);
    vertices[s.val].state = 1;

    while (!que.empty()) {
        node u = que.front();
        que.pop();
        cout << char(u.val + 'A') << " "; // Print the visited node

        for (int i = 0; i < NODE; i++) {
            if (graph[u.val][i] == 1 && vertices[i].state == 0) {
                que.push(vertices[i]);
                vertices[i].state = 1;
            }
        }
    }
}

int main() {
    node vertices[NODE];
    node start;
    char s = 'C';

    for (int i = 0; i < NODE; i++) {
        vertices[i].val = i;
        vertices[i].state = 0; // Initialize state to 0 (not visited)
    }

    start.val = s - 'A'; // Convert character to corresponding integer index
    cout << "BFS Traversal: ";
    bfs(vertices, start);
    cout << endl;

    return 0;
}

