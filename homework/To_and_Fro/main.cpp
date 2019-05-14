#include <iostream>
#include <string>

int main() {
    int column;
    while (std::cin >> column && column != 0) {
        std::string str;
        std::cin >> str;

        std::string result;

        for (int i = 0; i < column; i++) {
            for (int row = 0; row <= (str.size() - 1) / column; row++) {
                // curr = str[row * column + col]
                if (row % 2 == 0) {
                    if (row * column + i < str.size()) {
                        result += str[row * column + i];
                    }
                }
                else {
                    if (row * column + column - i - 1 < str.size()) {
                        result += str[row * column + column - i - 1];
                    }
                }
            }
        }
        
        std::cout << result << std::endl;
    }
}