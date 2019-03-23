#include <iostream>
#include <vector>
#include <stack>

bool canRemoveAll(const std::vector<int>& couple_id, int N) {
    std::stack<int> stk;
    for (int i = 0; i < 2 * N; i++) {
        if (!stk.empty() && stk.top() == couple_id[i]) {
            stk.pop();
        }
        else {
            stk.push(couple_id[i]);
        }
    }
    return stk.empty();
}

int main() {
    int N;
    while (std::cin >> N && N != 0) {
        std::vector<int> couple_id(2 * N);
        for (int i = 0; i < N; i++) {
            // Couple numbers
            int partnerA, partnerB;
            std::cin >> partnerA >> partnerB;
            // Each couple has the same couple id
            couple_id[partnerA - 1] = i;
            couple_id[partnerB - 1] = i;
        }
        if (canRemoveAll(couple_id, N)) {
            std::cout << "Yes" << std::endl;
        }
        else {
            std::cout << "No" << std::endl;
        }
    }
}
