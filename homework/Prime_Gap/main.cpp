#include <iostream>
#include <cmath>

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int num;
    while (std::cin >> num && num != 0) {
        if (isPrime(num)) {
            std::cout << 0 << std::endl;
        }
        else {
            int lower = num - 1;
            int upper = num + 1;

            while (!isPrime(lower)) {
                lower -= 1;
            }

            while (!isPrime(upper)) {
                upper += 1;
            }

            std::cout << (upper - lower) << std::endl;
        }
    }
}

