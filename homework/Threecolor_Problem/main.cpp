#include <iostream>
#include <string>

int main() {
    int T;
    std::cin >> T;
    for (int t = 0; t < T; t++) {
        int n, m;
        std::cin >> n >> m;

        std::string str;
        std::cin >> str;

        int r_count = 0;
        int y_count = 0;
        int b_count = 0;

        for (char ch : str) {
            if (ch == 'r') {
                r_count += 1;
            }
            else if (ch == 'y') {
                y_count += 1;
            }
            else if (ch == 'b') {
                b_count += 1;
            }
        }

        // [ r | y | b ]
        if (m - 1 < r_count) {
            // r: [0, r_count - 1]
            std::cout << "r" << std::endl;
        }
        else if (m - 1 < r_count + y_count) {
            // y: [r_count, r_count + y_count -1]
            std::cout << "y" << std::endl;
        }
        else {
            // b: [r_count + y_count, r_count + y_count + b_count - 1]
            std::cout << "b" << std::endl;
        }
    }
}