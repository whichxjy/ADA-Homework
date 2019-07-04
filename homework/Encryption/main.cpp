#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::string String_A, String_B;
    while (std::cin >> String_A >> String_B) {
        // Longest Common Subsequence
        int** lcs = new int*[String_A.size() + 1];
        for (int i = 0; i <= String_A.size(); i++) {
            lcs[i] = new int[String_B.size() + 1];
        }

        for (int i = 0; i <= String_A.size(); i++) {
            for (int j = 0; j <= String_B.size(); j++) {
                if (i == 0 || j == 0) {
                    lcs[i][j] = 0;
                }
                else if (String_A[i - 1] == String_B[j - 1]) {
                    lcs[i][j] = 1 + lcs[i - 1][j - 1];
                }
                else {
                    lcs[i][j] = std::max(lcs[i][j - 1], lcs[i - 1][j]);
                }
            }
        }

        std::cout << lcs[String_A.size()][String_B.size()] << std::endl;

        for (int i = 0; i <= String_A.size(); i++) {
            delete[] lcs[i];
        }
        delete[] lcs;
    }
}