#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int T;
    std::cin >> T;
    for (int t = 0; t < T; t++) {
        int N, M;
        std::cin >> N >> M;
        std::vector<int> S1(N + 1), S2(M + 1);
        for (int i = 1; i <= N; i++) {
            int num;
            std::cin >> num;
            S1[i] = num;
        }
        for (int i = 1; i <= M; i++) {
            int num;
            std::cin >> num;
            S2[i] = num;
        }

        std::sort(S1.begin() + 1, S1.end());
        std::sort(S2.begin() + 1, S2.end());

        // f[i][j] represents F(S1[1, i], S2[1, j])
        std::vector<std::vector<int>> f(N + 1, std::vector<int>(M + 1, 0));

        // Base
        for (int i = 1; i <= N; i++) {
            f[i][i] = f[i - 1][i - 1] + abs(S1[i] - S2[i]);
        }

        for (int i = 1; i <= N; i++) {
            for (int j = i + 1; j <= M; j++) {
                // To calculate f[i][j], there are two options.
                //
                // Option 1: choose S2[j]
                // => match S1[i] and S2[j]
                // => f[i - 1][j - 1] + abs(S1[i] - S2[j])
                // 
                // Option 2: not to choose S2[j]
                // => not to match S1[i] and S2[j]
                // => f[i][j - 1]
                //
                // Which one is smaller?
                // For a given i, if you choose S2[j] but the result is larger, then
                // drop it (Option 2). But if you choose S2[j] and the result is smaller, 
                // then match S1[i] and S2[j] (Option 1).
                f[i][j] = std::min(f[i - 1][j - 1] + abs(S1[i] - S2[j]), f[i][j - 1]);
            }
        }

        std::cout << f[N][M] << std::endl;
    }
}