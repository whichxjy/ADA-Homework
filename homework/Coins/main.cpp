#include <iostream>
#include <algorithm>
#include <iomanip>

double value[6] = { 0.01, 0.05, 0.1, 0.25, 0.5, 1 };
int weight[6] = { 3, 5, 2, 6, 11, 8 };

double M[7][10001];

int main() {
    int W;
    while (std::cin >> W) {
        int A[6];
        for (int i = 0; i <= 5; i++) {
            std::cin >> A[i];
        }
        
        // M[i][w]:
        // the maximal value when taking coins[0, ..., i - 1] with the capacity of w
        for (int i = 0; i <= 6; i++) {
            for (int w = 0; w <= W; w++) {
                if (i == 0 || w == 0) {
                    M[i][w] = 0;
                }
                else {
                    M[i][w] = 0;
                    // How many coins[i - 1] can you take?
                    int nCount = std::min(A[i - 1], w / weight[i - 1]);
                    for (int k = 0; k <= nCount; k++) {
                        if (k * weight[i - 1] <= w) {
                            M[i][w] = std::max(M[i][w],
                                               k * value[i - 1]+ M[i - 1][w - k * weight[i - 1]]);
                        }
                        else {
                            break;
                        }
                    }
                }
            }
        }
        std::cout << "$" << std::fixed << std::setprecision(2) << M[6][W] << std::endl;
    }
}