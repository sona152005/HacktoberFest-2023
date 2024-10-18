#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int to, weight;
};

void dijkstra(const vector<vector<Edge>>& graph, int start, vector<int>& dist) {
    dist.assign(graph.size(), INT_MAX);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const Edge& edge : graph[u]) {
            int v = edge.to, weight = edge.weight;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m; // Number of nodes and edges
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].emplace_back(Edge{v, weight});
    }

    int start; // Starting node
    cin >> start;

    vector<int> dist;
    dijkstra(graph, start, dist);

    for (int i = 0; i < n; i++) {
        cout << "Shortest distance from node " << start << " to node " << i << " is: "
             << (dist[i] == INT_MAX ? -1 : dist[i]) << endl;
    }

    return 0;
}
