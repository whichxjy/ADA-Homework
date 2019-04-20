#include <iostream>
#include <limits>
#include <algorithm>

const int MAX_V = 100;

// Infinity
const int INF = std::numeric_limits<int>::max();

int main() {
    // dist[i][j] -> shortest distance from i to j
    int dist[MAX_V][MAX_V];

    int V, E, Q;
    std::cin >> V >> E >> Q;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j) {
                dist[i][j] = 0;
            }
            else {
                dist[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < E; i++) {
        int s, d, w;
        std::cin >> s >> d >> w;
        dist[s - 1][d - 1] = std::min(w, dist[s - 1][d - 1]);
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < Q; i++) {
        int s, d;
        std::cin >> s >> d;
        if (dist[s - 1][d - 1] == INF) {
            // There is no path from i to j
            std::cout << -1 << std::endl;
        }
        else {
            std::cout << dist[s - 1][d - 1] << std::endl;
        }
    }
}
