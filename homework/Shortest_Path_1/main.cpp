#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

// Infinity
const int INF = std::numeric_limits<int>::max();

struct Edge {
    int src;
    int dest;
    int weight;

    Edge(int src, int dest, int weight)
        : src(src), dest(dest), weight(weight) {}
};

struct Graph {
    int V;  // number of vertices
    std::vector<Edge> edges;

    Graph(int V) : V(V) {
        edges = std::vector<Edge>();
    }
};

int main() {
    int V, E;
    std::cin >> V >> E;
    Graph graph(V);
    for (int i = 0; i < E; i++) {
        int s, d, w;
        std::cin >> s >> d >> w;
        graph.edges.emplace_back(s - 1, d - 1, w);
    }
    
    std::vector<int> dist(V);
    dist[0] = 0;
    for (int i = 1; i < V; i++) {
        dist[i] = INF;
    }

    for (int i = 0; i < V - 1; i++) {
        for (Edge edge : graph.edges) {
            int src = edge.src;
            int dest = edge.dest;
            int weight = edge.weight;
            if (dist[src] != INF && dist[src] + weight < dist[dest]) {
                dist[dest] = dist[src] + weight;
            }
        }
    }

    if (dist[V - 1] == INF) {
        // You can't reach city N
        std::cout << -1 << std::endl;
        return 0;
    }

    for (Edge edge : graph.edges) {
        int src = edge.src;
        int dest = edge.dest;
        int weight = edge.weight;
        if (dist[src] != INF && dist[src] + weight < dist[dest]) {
            // You don't need to spend money
            std::cout << 0 << std::endl;
            return 0;
        }
    }

    if (dist[V - 1] >= 0) {
        // Print the money you need to pay
        std::cout << dist[V - 1] << std::endl;
    }
    else {
        // You don't need to spend money
        std::cout << 0 << std::endl;
    }
}
