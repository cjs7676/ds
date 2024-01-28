#include<iostream>
#include<algorithm>
using namespace std;

const int Max = 1e4 + 5;
int id[Max], Nodes, edges;

void init() {
    for (int i = 0; i < Max; i++) {
        id[i] = i;
    }
}

int root(int x) {
    while (id[x] != x) {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y) {
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

long long kruskal(pair<long long, pair<int, int> > p[]) {
    int x, y;
    long long cost, minimumCost = 0;
    for (int i = 0; i < edges; ++i) {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if (root(x) != root(y)) {
            minimumCost += cost;
            union1(x, y);
        }
    }
    return minimumCost;
}

int main() {
    int x, y;
    long long weight, minimumCost;
    init();
    cout << "Enter Nodes and edges: ";
    cin >> Nodes >> edges;
    pair<long long, pair<int, int> > p[Max];
    for (int i = 0; i < edges; ++i) {
        cout << "Enter the value of x, y, and weight: ";
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    sort(p, p + edges);
    minimumCost = kruskal(p);
    cout << "Minimum cost is: " << minimumCost << endl;
    cout << "" << endl;
    return 0;
}
