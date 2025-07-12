#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

struct DSU {
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int xroot = find(x);
        int yroot = find(y);
        if (xroot == yroot) return false;

        if (rank[xroot] < rank[yroot])
            parent[xroot] = yroot;
        else if (rank[xroot] > rank[yroot])
            parent[yroot] = xroot;
        else {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
        return true;
    }
};

int main() {
    int n = 4; // number of vertices
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    sort(edges.begin(), edges.end());

    DSU dsu(n);
    vector<Edge> result;

    for (Edge e : edges) {
        if (dsu.unite(e.u, e.v)) {
            result.push_back(e);
        }
    }

    cout << "Edges in Minimum Spanning Tree:\n";
    int total_weight = 0;
    for (Edge e : result) {
        cout << e.u << " - " << e.v << " : " << e.weight << endl;
        total_weight += e.weight;
    }
    cout << "Total weight of MST: " << total_weight << endl;

    return 0;
}
