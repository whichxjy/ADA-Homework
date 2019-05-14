#include <iostream>
#include <vector>
#include <limits>

const int INF = std::numeric_limits<int>::max();

const int MAX_V = 10;
int graph[MAX_V][MAX_V];
int parent[MAX_V];

int main() {
    int T;
    std::cin >> T;
    for (int t = 0; t < T; t++) {
        int V, E, K;
        std::cin >> V >> E >> K;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                graph[i][j] = 0;
            }
        }

        for (int e = 0; e < E; e++) {
            int src, dst, d;
            std::cin >> src >> dst >> d;
            graph[src - 1][dst - 1] = d;
            graph[dst - 1][src - 1] = d;
        }

        // Bellman-Ford
        std::vector<int> dist(V);

        for (int i = 0; i < V; i++) {
            parent[i] = -1;
            dist[i] = INF;
        }
        dist[0] = 0;

        for (int k = 0; k < V - 1; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (graph[i][j] > 0 && dist[i] != INF && dist[i] + graph[i][j] < dist[j]) {
                        if (j == V - 1) {
                            int count = 0;
                            int ptr = i;
                            while (ptr != 0) {
                                count += 1;
                                ptr = parent[ptr];
                            }
                            if (count > K) {
                                continue;
                            }
                        }
                        dist[j] = dist[i] + graph[i][j];
                        parent[j] = i;
                    }
                }
            }
        }

        if (dist[V - 1] == INF) {
            std::cout << -1 << std::endl;
            continue;
        }

        std::cout << dist[V - 1] << std::endl;
    }
}
