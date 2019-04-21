#include <iostream>
#include <string>
#include <cmath>

unsigned long long mul(unsigned long long a, unsigned long long b, unsigned long long mod) {
    unsigned long long c = 0;
    const int base = 2;
    for (; b != 0; b /= base) {
        c += (b % base) * a;
        c %= mod;
        a = (a * base) % mod;
    }
    return c;
}

unsigned long long cube(unsigned long long num, unsigned long long mod) {
    return mul(mul(num, num, mod), num, mod);
}

int main() {
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::string num;
        std::cin >> num;

        unsigned long long endNum = 0;
        unsigned long long res = 0; // final result

        for (int index = num.size() - 1, r_index = 0; index >= 0; index--, r_index++) {
            unsigned long long power = pow(10, r_index);
            unsigned long long step = power;

            endNum += (num[index] - '0') * power;
            
            while (cube(res, power * 10) != endNum) {
                res += step;
            }

        }
        std::cout << res << std::endl;
    }
}

