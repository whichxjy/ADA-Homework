#include <iostream>
#include <vector>
#include <queue>

const int MAX_N = 100;
const int MAX_M = 100;
const int MAX_V = MAX_N + MAX_M + 2;

int graph[MAX_V][MAX_V];
int rGraph[MAX_V][MAX_V];

int INF = 9999999;

bool BFS(int graph[MAX_V][MAX_V], int V, int s, int t, std::vector<int>& parent) {
    std::vector<int> visited(V, false);

    std::queue<int> q;
    q.push(s);

    parent[s] = -1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v == t) {
            return true;
        }

        visited[v] = true;

        for (int i = 0; i < V; i++) {
            if (graph[v][i] > 0 && !visited[i]) {
                q.push(i);
                parent[i] = v;
            }
        }
    }

    return false;
}

int fordFulkerson(int graph[MAX_V][MAX_V], int V, int s, int t) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            rGraph[i][j] = graph[i][j];
        }
    }

    std::vector<int> parent(V);
    int max_flow = 0;

    while (BFS(graph, V, s, t, parent)) {
        int path_flow = INF;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            if (rGraph[u][v] < path_flow) {
                path_flow = rGraph[u][v];
            }
        }

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    int N, M;
    while (std::cin >> N >> M) {
        int V = N + M + 2;

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                graph[i][j] = 0;
            }
        }

        // S -> Girls
        int S = N + M;
        for (int i = 0; i < N; i++) {
            graph[S][i] = 1;
        }

        // Boys -> T
        int T = N + M + 1;
        for (int i = N; i < (N + M); i++) {
            graph[i][T] = 1;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int num;
                std::cin >> num;
                if (num == 1) {
                    graph[i][j + N] = 1;
                }
            }
        }

        std::cout << fordFulkerson(graph, V, S, T) << std::endl;
    }
}