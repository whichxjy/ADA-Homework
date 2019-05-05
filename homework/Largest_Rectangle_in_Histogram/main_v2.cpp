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
        for (int right = 0; right < N; right++) {
            if ((right + 1) < N && height[right] <= height[right + 1]) {
                continue;
            }
            int min_height = height[right];
            for (int left = right; left >= 0; left--) {
                if (height[left] < min_height) {
                    min_height = height[left];
                }
                int area = (right - left + 1) * min_height;
                if (area > max_area) {
                    max_area = area;
                }
            }
        }
        std::cout << max_area << std::endl;
    }
}
