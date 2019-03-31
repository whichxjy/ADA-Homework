#include <iostream>
#include <algorithm>
#include <vector>

// Player_A first, then Player_B

// cards in the game
std::vector<int> cards;
// whether the score won by Player_A was cached
std::vector<std::vector<bool>> cached;
// cache of the score won by Player_A
std::vector<std::vector<int>> scoreCache;

// Get the score won by Player_A in cards[left, right]
int scoreOfPlayerA(int left, int right) {
    if (left > right) {
        return 0;
    }
    else if (left == right) {
        return cards[left];
    }
    else if (cached[left][right]) {
        return scoreCache[left][right];
    }

    // If Player_A takes cards[left],
    // Player_B will choose max { cards[left + 1], cards[right] }

    int takeLeft;   // the score won by Player_A if he takes cards[left]
    if (cards[right] > cards[left + 1]) {
        // Player_B takes cards[right]
        takeLeft = cards[left] + scoreOfPlayerA(left + 1, right - 1);
    }
    else {
        // Player_B takes cards[left + 1]
        takeLeft = cards[left] + scoreOfPlayerA(left + 2, right);
    }

    // If Player_A takes cards[right],
    // Player_B will choose max { cards[left], cards[right - 1] }

    int takeRight;  // the score won by Player_A if he takes cards[right]
    if (cards[left] > cards[right - 1]) {
        // Player_B takes cards[left]
        takeRight = cards[right] + scoreOfPlayerA(left + 1, right - 1);
    }
    else {
        // Player_B takes cards[right - 1]
        takeRight = cards[right] + scoreOfPlayerA(left, right - 2);
    }

    cached[left][right] = true;
    scoreCache[left][right] = std::max(takeLeft, takeRight);

    return scoreCache[left][right];
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

        cached = std::vector<std::vector<bool>>(n, std::vector<bool>(n, false));
        scoreCache = std::vector<std::vector<int>>(n, std::vector<int>(n));

        int sum = 0;
        for (int card : cards) {
            sum += card;
        }

        int scoreA = scoreOfPlayerA(0, n - 1);
        int scoreB = sum - scoreA;

        count++;
        std::cout << "In game " << count << ", the greedy strategy might lose by as many as "
            << (scoreA - scoreB) << " points." << std::endl;
    }
}
