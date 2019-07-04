#include <iostream>

int main() {
    int num1, num2;
    while (std::cin >> num1 >> num2 && num1 != 0 && num2 != 0) {
        // Start Game
        int round_count = 0;

        while (num1 > 0 && num2 > 0) {
            round_count += 1;

            if (num1 > num2) {
                if ((num1 / num2) >= 2) {
                    break;
                }
                else {
                    num1 -= num2;
                }
            }
            else {
                if ((num2 / num1) >= 2) {
                    break;
                }
                else {
                    num2 -= num1;
                }
            }
        }

        if (round_count % 2 == 1) {
            std::cout << "Singa wins" << std::endl;
        }
        else {
            std::cout << "Suny wins" << std::endl;
        }
    }
}