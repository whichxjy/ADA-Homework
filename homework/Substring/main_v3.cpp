#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

bool cmp(const std::string& lhs, const std::string& rhs) {
    return lhs + rhs < rhs + lhs;
}

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

        std::sort(strs.begin(), strs.end(), cmp);

        for (std::string str : strs) {
            std::cout << str;
        }
        std::cout << std::endl;
    }
}
