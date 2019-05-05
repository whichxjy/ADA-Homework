#include <iostream>
#include <vector>
#include <stack>

int main() {
    int T;
    std::cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        std::cin >> N;
        std::vector<int> height(N);
        for (int i = 0; i < N; i++) {
            std::cin >> height[i];
        }
        int max_area = 0;
        // Indexs of rectangle
        std::stack<int> stk;
        height.push_back(0);
        int index = 0;
        while (index < height.size()) {
            if (stk.empty() || height[stk.top()] <= height[index]) {
                stk.push(index);
                index += 1;
            }
            else {
                int cur = stk.top();
                stk.pop();
                // Calculate Area
                int area;
                if (stk.empty()) {
                    area = height[cur] * index;
                }
                else {
                    area = height[cur] * (index - stk.top() - 1);
                }
                if (area > max_area) {
                    max_area = area;
                }
            }
        }
        std::cout << max_area << std::endl;
    }
}
