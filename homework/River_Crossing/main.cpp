#include <iostream>
#include <algorithm>
#include <cstring>

const int MAX_STONE = 102;
const int MAX_LENGTH = 25000;

// Stone position
int stonePos[MAX_STONE];
// hasStone[i]: If there is a stone in position i?
bool hasStone[MAX_LENGTH];
// f[i]: The least stones it will step on from pos[0] to pos[i]
int f[MAX_LENGTH];

int main() {
    int L, S, T, M;
    std::cin >> L >> S >> T >> M;
    for (int i = 0; i < M; i++) {
        std::cin >> stonePos[i];
    }

    // Special case
    if (S == T) {
        int ret = 0;
        for (int i = 0; i < M; i++) {
            if (stonePos[i] % S == 0) {
                ret++;
            }
        }
        std::cout << ret << std::endl;
    }
    else {
        std::sort(stonePos, stonePos + M);
        memset(hasStone, false, sizeof(hasStone));
        memset(f, -1, sizeof(f));

        // The length of the compressed river
        int N = 0;

        for (int i = 0, pre = 0; i < M; i++) {
            N += std::min(stonePos[i] - pre, 100);
            hasStone[N] = true;
            pre = stonePos[i];
        }
        N += std::min(L - stonePos[M - 1], 100);

        f[0] = 0;
        for (int i = 0; i < N; i++) {
            // If pos[i] can be arrived
            if (f[i] >= 0) {
                for (int j = S; j <= T; j++) {
                    int k = i + j;  // Jump: from pos[i] to pos[k]
                                    // If f[k] hasn't been calculated
                                    // or f[i] + (hasStone[k] ? 1 : 0) is a better solution for f[k]
                    if (f[k] < 0 || f[i] + (hasStone[k] ? 1 : 0) < f[k]) {
                        f[k] = f[i] + (hasStone[k] ? 1 : 0);
                    }
                }
            }
        }

        int ret = M;
        for (int i = N; i < N + T; i++) {
            ret = std::min(ret, f[i]);
        }
        std::cout << ret << std::endl;
    }
}