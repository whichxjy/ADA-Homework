#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int INF = 9999999;

int rankDistance(const std::string& lhs, const std::string& rhs) {
    std::vector<int> lpos(5);
    for (int i = 0; i < 5; i++) {
        lpos[lhs[i] - 'A'] = i;
    }
    std::vector<int> rpos(5);
    for (int i = 0; i < 5; i++) {
        rpos[rhs[i] - 'A'] = i;
    }
    int dist = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if ((lpos[i] < lpos[j] && rpos[i] > rpos[j]) || (lpos[i] > lpos[j] && rpos[i] < rpos[j])) {
                dist += 1;
            }
        }
    }
    return dist;
}

int main() {
    int N;
    while (std::cin >> N && N != 0) {
        std::vector<std::string> strs;
        for (int i = 0; i < N; i++) {
            std::string str;
            std::cin >> str;
            strs.push_back(str);
        }
        
        std::string perm = "ABCDE";
        // Median Ranking
        std::string result;
        int minimal = INF;
        do {
            //  the value of the ranking perm
            int sum = 0;
            for (std::string str : strs) {
                sum += rankDistance(str, perm);
            }
            if (sum < minimal) {
                result = perm;
                minimal = sum;
            }
        } while (std::next_permutation(perm.begin(), perm.end()));

        std::cout << result << " is the median ranking with value " << minimal << "." << std::endl;
    }
}