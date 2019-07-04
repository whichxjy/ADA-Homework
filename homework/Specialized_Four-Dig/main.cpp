#include <iostream>

int sumDigs(int num, int base) {
    int sum = 0;
    while (num != 0) {
        sum += num % base;
        num /= base;
    }
    return sum;
}

int main() {
    for (int i = 2992; i < 10000; i++) {
        if (sumDigs(i, 10) == sumDigs(i, 16) && sumDigs(i, 10) == sumDigs(i, 12)) {
            std::cout << i << std::endl;
        }
    }
}