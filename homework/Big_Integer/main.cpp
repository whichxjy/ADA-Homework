#include <iostream>
#include <string>
#include <vector>

int mod(const std::string& divided, int divisor) {
    int ret = 0;
    for (char dig : divided) {
        ret = (ret * 10 + (dig - '0')) % divisor;
    }
    return ret;
}

int main() {
    int T;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        std::cin >> N;
        std::vector<int> bases;
        for (int j = 0; j < N; j++) {
            int base;
            std::cin >> base;
            bases.push_back(base);
        }
        std::string bigInt;
        std::cin >> bigInt;
        std::cout << "(";
        for (int j = 0; j < N; j++) {
            std::cout << mod(bigInt, bases[j]) << (j == (N - 1) ? ")" : ",");
        }
        std::cout << std::endl;
    }
}
