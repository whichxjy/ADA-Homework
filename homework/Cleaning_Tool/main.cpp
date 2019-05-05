#include <iostream>
#include <vector>

int main() {
    int T;
    std::cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        std::cin >> N;
        std::vector<int> board(N);
        for (int n = 0; n < N; n++) {
            std::cin >> board[n];
        }
        int count = 0;
        while (true) {
            int ptr = 0;
            while (ptr < N && board[ptr] == 0) {
                ptr += 1;
            }
            if (ptr == N) {
                break;
            }

            while (ptr < N && board[ptr] != 0) {
                board[ptr] -= 1;
                ptr += 1;
            }

            count += 1;
        }
        std::cout << count << std::endl;
    }
}
