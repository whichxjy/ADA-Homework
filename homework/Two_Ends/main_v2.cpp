#include <iostream>
#include <algorithm>
#include <vector>

// Player_A first, then Player_B

// cards in the game
std::vector<int> cards;

// maximum possible difference between Player_A's score and Player_B's score
std::vector<std::vector<int>> maxScoreDiff;

// Get the smaximum possible difference between Player_A's score
// and Player_B's score in cards[left, right]
int getMaxScoreDiff(std::vector<int> cards) {

    maxScoreDiff = std::vector<std::vector<int>>(cards.size(), std::vector<int>(cards.size(), 0));

    // Base
    for (int i = 0; i < cards.size() - 1; i++) {
        maxScoreDiff[i][i + 1] = abs(cards[i] - cards[i + 1]);
    }

    for (int intvl = 2; intvl < cards.size(); intvl++) {
        for (int left = 0; left + intvl < cards.size(); left++) {
            int right = left + intvl;

            // If Player_A takes cards[left],
            // Player_B will choose max { cards[left + 1], cards[right] }

            int takeLeft;   // the score diff if Player_A takes cards[left]
            if (cards[right] > cards[left + 1]) {
                // Player_B takes cards[right]
                takeLeft = (cards[left] - cards[right]) + maxScoreDiff[left + 1][right - 1];
            }
            else {
                // Player_B takes cards[left + 1]
                takeLeft = (cards[left] - cards[left + 1]) + maxScoreDiff[left + 2][right];
            }

            // If Player_A takes cards[right],
            // Player_B will choose max { cards[left], cards[right - 1] }

            int takeRight;  // the score diff if Player_A takes cards[right]
            if (cards[left] >= cards[right - 1]) {
                // Player_B takes cards[left]
                takeRight = (cards[right] - cards[left]) + maxScoreDiff[left + 1][right - 1];
            }
            else {
                // Player_B takes cards[right - 1]
                takeRight = (cards[right] - cards[right - 1]) + maxScoreDiff[left][right - 2];
            }

            maxScoreDiff[left][right] = std::max(takeLeft, takeRight);
        }
    }
    return maxScoreDiff[0][cards.size() - 1];
}

int main() {
    int count = 0;
    int n;
    while (std::cin >> n && n != 0) {
        cards.clear();

        for (int i = 0; i < n; i++) {
            int card;
            std::cin >> card;
            cards.push_back(card);
        }

        count++;
        std::cout << "In game " << count << ", the greedy strategy might lose by as many as "
            << getMaxScoreDiff(cards) << " points." << std::endl;
    }
}
