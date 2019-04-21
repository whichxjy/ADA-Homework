#include <iostream>
#include <cmath>

// Real digit
#define REAL(dig) (((dig) <= 3) ? (dig) : ((dig) - 1))

int main() {
    int num;
    while (std::cin >> num && num != 0) {
        int origin = num;
        int realNum = 0;
        int k = 0;
        while (num != 0) {
            realNum += REAL(num % 10) * pow(9, k);
            k += 1;
            num /= 10;
        }
        std::cout << origin << ": " << realNum << std::endl;
    }
}
