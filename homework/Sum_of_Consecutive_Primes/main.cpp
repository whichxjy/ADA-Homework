#include <iostream>
#include <vector>
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
    std::vector<int> prime;
    for (int i = 2; i <= 10000; i++) {
        if (isPrime(i)) {
            prime.push_back(i);
        }
    }

    int num;
    while (std::cin >> num && num != 0) {
        int count = 0;
        for (int first = 0; first < prime.size(); first++) {
            int sum = 0;
            for (int last = first; last < prime.size(); last++) {
                sum += prime[last];
                if (sum == num) {
                    count += 1;
                    break;
                }
                else if (sum > num) {
                    break;
                }
            }
        }
        std::cout << count << std::endl;
    }
}
