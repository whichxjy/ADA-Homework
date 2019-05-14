#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

//template <class _Ty1, class _Ty2>
//inline
//bool operator<(const pair<_Ty1, _Ty2>& _Left, const pair<_Ty1, _Ty2>& _Right) {
//    return (_Left.first < _Right.first  ||
//        !(_Right.first < _Left.first) && _Left.second < _Right.second);
//}


int main() {
    std::string keyword;
    std::string ciphertext;
    while (std::cin >> keyword >> ciphertext && keyword != "THEEND") {
        int COL = keyword.size();
        int ROW = ciphertext.size() / COL;

        // pair.first  => letter of keyword
        // pair.second => index of letter(= index of column)
        std::vector<std::pair<int, int>> vec;
        for (int i = 0; i < COL; i++) {
            vec.emplace_back(keyword[i], i);
        }
        std::sort(vec.begin(), vec.end());

        std::vector<std::vector<char>> arr(ROW, std::vector<char>(COL));
        // ptr => index of current letter of ciphertext
        for (int i = 0, ptr = 0; i < keyword.size(); i++) {
            int colIndex = vec[i].second;
            for (int j = 0; j < ROW; j++, ptr++) {
                arr[j][colIndex] = ciphertext[ptr];
            }
        }

        std::string result;
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                result += arr[i][j];
            }
        }

        std::cout << result << std::endl;
    }
}