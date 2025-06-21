#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Breadth-First Search function
void bfs(int startNode, const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    cout << "BFS traversal starting from node " << startNode << ": ";

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    cout << endl;
}

int main() {
    int n = 6; // number of nodes (0 to 5)
    vector<vector<int>> graph(n);

    // Add undirected edges
    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 4};
    graph[3] = {1, 5};
    graph[4] = {1, 2, 5};
    graph[5] = {3, 4};

    bfs(0, graph);

    return 0;
}
