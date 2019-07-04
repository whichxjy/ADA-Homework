#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

const int INF = 99999999;

struct City {
    int x;
    int y;

    City(int x, int y) : x(x), y(y) {}
};

// Get distance
double getDist(const City& lhs, const City& rhs) {
    return std::sqrt((lhs.x - rhs.x) * (lhs.x - rhs.x) + (lhs.y - rhs.y) * (lhs.y - rhs.y));
}

int main() {
    int T;
    std::cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        std::cin >> N;

        std::vector<City> cities;
        for (int i = 0; i < N; i++) {
            int x, y;
            std::cin >> x >> y;
            cities.emplace_back(x, y);
        }

        std::vector<std::vector<double>> distance(N, std::vector<double>(N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                distance[i][j] = getDist(cities[i], cities[j]);
                distance[j][i] = getDist(cities[i], cities[j]);
            }
        }

        // The bits of set in which all cities are
        int full_set_bits = 0;
        for (int i = 0; i < N; i++) {
            full_set_bits = full_set_bits | (1 << i);
        }
        // Or just let full_set_bits = (1 << N) - 1

        std::vector<std::vector<double>> dp(full_set_bits + 1, std::vector<double>(N));
        for (int i = 0; i <= full_set_bits; i++) {
            for (int j = 0; j < N; j++) {
                dp[i][j] = INF;
            }
        }

        // Base case
        for (int i = 0; i < N; i++) {
            dp[0][i] = 0;
        }
        dp[1][0] = 0;

        // i: all subsets of cities containing city 0:
        for (int i = 1; i <= full_set_bits; i++) {
            // If city 0 is not in i
            if ((i & 1) == 0) {
                continue;
            }

            // j: all cities except 0-th city
            for (int j = 1; j < N; j++) {
                // Check if city j is in the set
                if (((1 << j) & i) != 0) {
                    // If city j is in the set, then:
                    // dp[i][j] = min{ dp[i - (1 << j)][k] + distance[k][j] }
                    // where city k is in i and k != j
                    for (int k = 0; k < N; k++) {
                        if (((1 << k) & i) != 0 && dp[i - (1 << j)][k] != INF
                            && dp[i - (1 << j)][k] + distance[k][j] < dp[i][j]) {
                            // Update dp
                            dp[i][j] = dp[i - (1 << j)][k] + distance[k][j];
                        }
                    }
                }
            }
        }

        double result = dp[full_set_bits][N - 1];
        std::cout << std::setprecision(2) << std::setiosflags(std::ios::fixed)
                  << result << std::endl;
    }
}