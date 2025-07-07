#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

void dijkstra(int start, vector<vector<pii>> &graph, vector<int> &dist) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (u_dist > dist[u]) continue;

        for (auto edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n = 5; // number of vertices
    vector<vector<pii>> graph(n);

    // Example graph initialization
    graph[0].push_back({1, 10});
    graph[0].push_back({4, 5});
    graph[1].push_back({2, 1});
    graph[1].push_back({4, 2});
    graph[2].push_back({3, 4});
    graph[3].push_back({0, 7});
    graph[3].push_back({2, 6});
    graph[4].push_back({1, 3});
    graph[4].push_back({2, 9});
    graph[4].push_back({3, 2});

    vector<int> dist(n, INT_MAX);
    dijkstra(0, graph, dist);

    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << " \t\t " << dist[i] << endl;
    }

    return 0;
}
