#include <iostream>
#include <vector>

const int MAX = 31;

int main() {
    std::vector<int> U(MAX);
    std::vector<int> V(MAX);

    // Base
    U[0] = 1;
    U[1] = 0;
    V[0] = 0;
    V[1] = 1;

    for (int i = 2; i < MAX; i++) {
        U[i] = U[i - 2] + 2 * V[i - 1];
        V[i] = U[i - 1] + V[i - 2];
    }

    int n;
    while (std::cin >> n && n != -1) {
        std::cout << U[n] << std::endl;
    }
}
