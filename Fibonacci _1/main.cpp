#include <iostream>

int fib(int n) {
    if (n <= 0) {
        return 0;
    }
    else if (n <= 2) {
        return 1;
    }
    else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
    int num;
    while (std::cin >> num) {
        std::cout << (fib(num) % 1000000007) << std::endl;
    }
}