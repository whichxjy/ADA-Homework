#include <iostream>
#include <vector>

// The target number
long long target;
// The best approximation of the target number using the 5 given numbers
long long max;

void DFS(const std::vector<long long>& nums) {
    for (long long num : nums) {
        if (num <= target && num > max) {
            max = num;
        }
    }

    if (max == target || nums.size() <= 1) {
        return;
    }

    for (int i = 0; i < nums.size() - 1; i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            std::vector<long long> next;
            for (int k = 0; k < nums.size(); k++) {
                if (k != i && k != j) {
                    next.push_back(nums[k]);
                }
            }

            // nums[i] + nums[j]
            std::vector<long long> plusNext(next);
            plusNext.push_back(nums[i] + nums[j]);
            DFS(plusNext);

            // nums[i] - nums[j]
            std::vector<long long> minusNext1(next);
            minusNext1.push_back(nums[i] - nums[j]);
            DFS(minusNext1);

            // nums[j] - nums[i]
            std::vector<long long> minusNext2(next);
            minusNext2.push_back(nums[j] - nums[i]);
            DFS(minusNext2);

            // nums[i] * nums[j]
            std::vector<long long> multiplyNext(next);
            multiplyNext.push_back(nums[i] * nums[j]);
            DFS(multiplyNext);

            // (nums[i] / nums[j]) or (nums[j] / nums[i]) => larger / smaller
            long long larger = nums[i] > nums[j] ? nums[i] : nums[j];
            long long smaller = nums[i] < nums[j] ? nums[i] : nums[j];
            if (smaller != 0 && larger % smaller == 0) {
                std::vector<long long> divideNext(next);
                divideNext.push_back(larger / smaller);
                DFS(divideNext);
            }
        }
    }
}

int main() {
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::vector<long long> nums(5);
        for (int j = 0; j < 5; j++) {
            std::cin >> nums[j];
        }
        std::cin >> target;
        max = -999999;
        DFS(nums);
        std::cout << max << std::endl;
    }
}
