#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

int main() {
    int T;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        int number;
        std::cin >> number;
        std::vector<int> items;
        for (int j = 0; j < number; j++) {
            int item;
            std::cin >> item;
            items.push_back(item);
        }
        std::sort(items.begin(), items.end(), std::greater<int>());
        int maxDiscount = 0;
        for (int j = 2; j < number; j += 3) {
            maxDiscount += items[j];
        }
        std::cout << maxDiscount << std::endl;
    }
}
