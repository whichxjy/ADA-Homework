#include <iostream>

int main() {
    int T;
    std::cin >> T;
    for (int t = 0; t < T; t++) {
        int a, b, low, high;
        std::cin >> a >> b >> low >> high;

        int gcd = -1;
        for (int i = low; i <= high; i++) {
            if (a % i == 0 && b % i == 0) {
                gcd = i;
            }
        }

        if (gcd == -1) {
            std::cout << "No answer" << std::endl;
        }
        else {
            std::cout << gcd << std::endl;
        }
    }
}