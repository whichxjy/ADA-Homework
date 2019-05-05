#include <iostream>
#include <vector>

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
        for (int i = 0; i < N; i++) {
            int min_height = height[i];
            for (int j = i; j < N; j++) {
                if (height[j] < min_height) {
                    min_height = height[j];
                }
                int area = (j - i + 1) * min_height;
                if (area > max_area) {
                    max_area = area;
                }
            }
        }
        std::cout << max_area << std::endl;
    }
}
