#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

int main() {
    int L;
    std::cin >> L;
    for (int i = 0; i < L; i++) {
        std::string str;
        std::cin >> str;
        auto iter = str.begin();
        while (iter != str.end()) {
            if (*iter != '0') {
                auto start = iter;
                auto end = iter + 1;
                while (end != str.end() && *end != '0') {
                    ++end;
                }
                std::sort(start, end, std::greater<char>());
                iter = end;
            }
            else {
                ++iter;
            }
        }
        std::cout << str << std::endl;
    }
}
