#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    int T;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        std::cin >> N;
        // Sub-strings
        std::vector<std::string> strs;

        for (int j = 0; j < N; j++) {
            std::string str;
            std::cin >> str;
            strs.emplace_back(str);
        }

        std::sort(strs.begin(), strs.end());
        std::string smallest = "";

        do {
            std::string tmp = "";
            for (std::string str : strs) {
                tmp += str;
            }
            if (smallest == "" || tmp < smallest) {
                smallest = tmp;
            }
        } while (std::next_permutation(strs.begin(), strs.end()));

        std::cout << smallest << std::endl;
    }
}
