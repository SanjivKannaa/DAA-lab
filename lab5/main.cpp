#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n;
int adj[100][100];

void primMST() {
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);

    dist[0] = 0;
    for (int i = 0; i < n - 1; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        visited[u] = true;
        for (int v = 0; v < n; v++) {
            if (adj[u][v] != 0 && !visited[v] && adj[u][v] < dist[v]) {
                dist[v] = adj[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Minimum Spanning Tree using Prim's algorithm:" << endl;
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " : " << adj[parent[i]][i] << endl;
    }
}

struct Edge {
    int u, v, w;
    bool operator<(Edge const& other) {
        return w < other.w;
    }
};

void kruskalMST() {
    vector<Edge> edges;
    for (int u = 0; u < n; u++) {
        for (int v = u + 1; v < n; v++) {
            if (adj[u][v] != 0) {
                edges.push_back({u, v, adj[u][v]});
            }
        }
    }

    sort(edges.begin(), edges.end());

    vector<int> parent(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    cout << "Minimum Spanning Tree using Kruskal's algorithm:" << endl;
    int totalWeight = 0;
    for (Edge e : edges) {
        int u = e.u, v = e.v, w = e.w;
        int pu = parent[u], pv = parent[v];
        if (pu != pv) {
            cout << u << " - " << v << " : " << w << endl;
            totalWeight += w;
            parent[pu] = pv;
        }
    }
    cout << "Total weight: " << totalWeight << endl;
}

int main() {
    n = 5;
    adj[0][1] = 4;
    adj[0][2] = 3;
    adj[1][2] = 1;
    adj[1][3] = 2;
    adj[2][3] = 4;
    adj[2][4] = 5;
    adj[3][4] = 6;
    primMST();
    cout << endl;
    kruskalMST();
}
