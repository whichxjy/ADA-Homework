#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

namespace my {

    template <typename T>
    void swap(T& lhs, T& rhs) {
        T temp(std::move(lhs));
        lhs = std::move(rhs);
        rhs = std::move(temp);
    }

    template <typename Iter>
    void iter_swap(Iter lhs, Iter rhs) {
        my::swap(*lhs, *rhs);
    }

    template <typename Iter>
    void reverse(Iter begin, Iter end) {
        while (begin != end && begin != --end) {
            my::iter_swapiter_swap(begin, end);
            ++begin;
        }
    }

    template <typename Iter>
    bool next_permutation(Iter begin, Iter end) {
        Iter preEnd = end - 1;
        if (begin == end && begin == preEnd) {
            return false;
        }

        Iter cur = end - 1;
        Iter pre = cur - 1;
        while (cur != begin && *pre >= *cur) {
            --cur;
            if (pre != begin) {
                --pre;
            }
        }

        if (cur == begin) {
            my::reverse(begin, end);
            return false;
        }
        else {
            cur = end - 1;
            while (*cur <= *pre) {
                --cur;
            }
            my::iter_swap(cur, pre);
            my::reverse(pre + 1, end);
            return true;
        }
    }
}

int main() {
    int T;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        std::cin >> N;
        // Sub-strings
        std::vector<std::string> strs;

        for (int j = 0; j < N; j++) {
            std::string str;
            std::cin >> str;
            strs.emplace_back(str);
        }

        std::sort(strs.begin(), strs.end());
        std::string smallest = "";

        do {
            std::string tmp = "";
            for (std::string str : strs) {
                tmp += str;
            }

            if (smallest == "" || tmp < smallest) {
                smallest = tmp;
            }
        } while (my::next_permutation(strs.begin(), strs.end()));

        std::cout << smallest << std::endl;
    }
}
