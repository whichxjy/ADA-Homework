#include <iostream>
#include <vector>

int main() {
    int C;
    std::cin >> C;
    for (int c = 1; c <= C; c++) {
        // N: How many unique numbers should be in the lucky lists
        // M: Lenny should choose numbers in [1, M]
        int N, M;
        std::cin >> N >> M;

        // listCount[i][j] represents the number of lucky lists,
        // where i reprents how many numbers in the list, and
        // j represents the end of the list
         std::vector<std::vector<long>> listCount(N + 1, std::vector<long>(M + 1, 0));

         // listCountSum[i][j] represents the number of lucky lists,
         // where i reprents how many numbers in the list, and
         // the end of the list is smaller or equal than j.
         std::vector<std::vector<long>> listCountSum(N + 1, std::vector<long>(M + 1, 0));

        // Base
        for (int j = 1; j <= M; j++) {
            listCount[1][j] = 1;
            listCountSum[1][j] = j;
        }

        for (int i = 2; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                listCount[i][j] = listCountSum[i - 1][j / 2];
                listCountSum[i][j] = listCountSum[i][j - 1] + listCount[i][j];
            }
        }

        std::cout << "Case " << c << ": n = " << N << ", m = " << M
            << ", # lists = " << listCountSum[N][M] << std::endl;
    }
}