#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

int main() {

    int n, e;
    cin >> n >> e;

    vector<Edge> edges(e);

    // Input edges
    for (int i = 0; i < e; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int source;
    cin >> source;

    vector<int> dist(n, 1e9);

    dist[source] = 0;

    // Bellman Ford
    for (int i = 1; i <= n - 1; i++) {

        for (int j = 0; j < e; j++) {

            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != 1e9 && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Negative cycle check
    bool cycle = false;

    for (int j = 0; j < e; j++) {

        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != 1e9 && dist[u] + w < dist[v]) {
            cycle = true;
        }
    }

    if (cycle) {
        cout << "Negative Cycle Found";
    }
    else {

        for (int i = 0; i < n; i++) {

            if (dist[i] == 1e9)
                cout << "INF ";
            else
                cout << dist[i] << " ";
        }
    }

    return 0;
}
