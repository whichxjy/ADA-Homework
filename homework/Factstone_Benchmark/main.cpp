#include <iostream>
#include <cmath>

int main() {
    int year;
    while (std::cin >> year && year != 0) {
        int bit = pow(2, 2 + (year - 1960) / 10);
        int n = 0;
        double sumLog = 0; // log(1) + log(2) + ... + log(n)
        while (sumLog < bit * log(2)) {
            n += 1;
            sumLog += log(n);
        }
        std::cout << (n - 1) << std::endl;
    }
}
