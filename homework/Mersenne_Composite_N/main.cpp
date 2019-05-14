#include <iostream>
#include <vector>
#include <cmath>

bool isPrime(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

std::vector<long long> factor(long long num) {
    std::vector<long long> ret;
    for (long long i = 2; i * i < num; i++) {
        while (num % i == 0) {
            ret.push_back(i);
            num /= i;
        }
    }
    if (num > 1) {
        ret.push_back(num);
    }
    return ret;
}

int main() {
    int k;
    std::cin >> k;
    for (int i = 2; i < k; i++) {
        if (isPrime(i)) {
            std::vector<long long> factors = factor((long long)pow(2, i) - 1);
            if (factors.size() > 1) {
                std::cout << factors[0];
                for (int j = 1; j < factors.size(); j++) {
                    std::cout << " * " << factors[j];
                }
                std::cout << " = " << ((long long)pow(2, i) - 1) << " = ( 2 ^ "
                    << i << " ) - 1" << std::endl;
            }
        }
    }
}
