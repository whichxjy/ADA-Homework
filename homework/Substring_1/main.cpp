#include <iostream>
#include <string>

int main() {
    int T;
    std::cin >> T;
    for (int t = 0; t < T; t++) {
        std::string str;
        std::cin >> str;
        int res_count = 0;
        for (int start = 0; start < str.size() ; start++) {
            int zero_count = 0;
            int one_count = 0;
            for (int i = start; i < str.size(); i++) {
                if (str[i] == '0') {
                    zero_count += 1;
                }
                else {
                    one_count += 1;
                }
                if (zero_count == one_count) {
                    res_count += 1;
                }
            }
        }
        std::cout << res_count << std::endl;
    }
}