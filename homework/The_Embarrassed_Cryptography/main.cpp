#include <iostream>
#include <vector>
#include <string>
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

int mod(const std::string& divided, int divisor) {
    int ret = 0;
    for (char dig : divided) {
        ret = (ret * 10 + (dig - '0')) % divisor;
    }
    return ret;
}

int main() {
    std::vector<int> primes;
    for (int i = 2; i <= 1000000; i++) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }

    std::string key;
    int minimum;
    while (std::cin >> key >> minimum && key != "0" && minimum != 0) {
        bool good = true;
        int factor;

        for (int prime : primes) {
            if (prime >= minimum) {
                break;
            }

            if (mod(key, prime) == 0) {
                good = false;
                factor = prime;
                break;
            }
        }

        if (good) {
            std::cout << "GOOD" << std::endl;
        }
        else {
            std::cout << "BAD " << factor << std::endl;
        }
    }
}