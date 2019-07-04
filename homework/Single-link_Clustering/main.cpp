#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <iomanip>

const int INF = 99999;

struct Node {
    int x;
    int y;

    Node(int x, int y) : x(x), y(y) {}
};

// Calculate Distance
double cal_distance(const Node& lhs, const Node& rhs) {
    return std::sqrt((lhs.x - rhs.x) * (lhs.x - rhs.x) + (lhs.y - rhs.y) * (lhs.y - rhs.y));
}

// Return parent[] of MST
std::vector<int> prim(std::vector<std::vector<double>> graph) {
    int V = graph.size();
    std::vector<int> parent(V, -1);
    std::vector<bool> inMST(V, false);
    std::vector<double> key(V, INF);

    using iPair = std::pair<double, int>;
    std::priority_queue<iPair, std::vector<iPair>, std::greater<iPair>> pq;

    // Start from 0th node
    key[0] = 0;
    pq.emplace(key[0], 0);

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (int i = 0; i < V; i++) {
            if (!inMST[i] && graph[u][i] != INF && graph[u][i] < key[i]) {
                key[i] = graph[u][i];
                pq.emplace(key[i], i);
                parent[i] = u;
            }
        }
    }

    return parent;
}

int main() {
    int n, k;
    while (std::cin >> n >> k) {
        std::vector<Node> nodes;
        for (int i = 0; i < n; i++) {
            int x, y;
            std::cin >> x >> y;
            nodes.emplace_back(x, y);
        }

        std::vector<std::vector<double>> graph(n, std::vector<double>(n, INF));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double distance = cal_distance(nodes[i], nodes[j]);
                graph[i][j] = distance;
                graph[j][i] = distance;
            }
        }

        std::vector<int> parent = prim(graph);

        std::vector<double> edge_length;
        for (int i = 0; i < n; i++) {
            if (parent[i] != -1) {
                edge_length.push_back(graph[i][parent[i]]);
            }
        }

        std::sort(edge_length.begin(), edge_length.end());
        std::cout << std::setprecision(2) << std::setiosflags(std::ios::fixed)
                  << edge_length[n - k] << std::endl;
    }
}