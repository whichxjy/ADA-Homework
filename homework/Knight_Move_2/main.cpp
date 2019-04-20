#include <iostream>
#include <vector>
#include <algorithm>

// Chess Map:
// 1 <= row <= ROW
// 1 <= col <= COL
// 1 <= index <= SUM

const int ROW = 8;
const int COL = 8;
const int SUM = ROW * COL;

struct POS {
    int row;
    int col;
    
    POS(int row, int col) : row(row), col(col) {
    }

    POS operator+(const POS& other) {
        return POS(this->row + other.row, this->col + other.col);
    }
};

// Whether the position was visited
bool visited[1 + SUM];
// Print Sequence
int printSeq[1 + SUM];
// How many pos have been visited?
int counter;
// Finished?
int done;

std::vector<POS> directions = {
    POS(1, -2), POS(2, -1), POS(2, 1), POS(1, 2),
    POS(-1, 2), POS(-2, 1), POS(-2, -1), POS(-1, -2)
};

// index -> Pos
POS idxToPos(int index) {
    int row = (index  - 1) / COL + 1;
    int col = (index - 1) % COL + 1;
    return POS(row, col);
}

// Pos -> index
int posToIdx(POS pos) {
    if (pos.row >= 1 && pos.row <= ROW && pos.col >= 1 && pos.col <= COL) {
        return ((pos.row - 1) * COL + pos.col);
    }
    else {
        return -1;
    }
}

// The positions knight can move to (from the start index)
std::vector<int> canMove(int startIdx) {
    std::vector<int> targetIdxs;
    for (POS direction : directions) {
        POS target = idxToPos(startIdx) + direction;
        int targetIdx = posToIdx(target);
        if (targetIdx >= 1 && targetIdx <= SUM && !visited[targetIdx]) {
            targetIdxs.push_back(targetIdx);
        }
    }
    return targetIdxs;
}

// How many positions can knight move to (from the start index)?
int countCanMove(int startIdx) {
    int count = 0;
    for (POS direction : directions) {
        POS target = idxToPos(startIdx) + direction;
        int targetIdx = posToIdx(target);
        if (targetIdx >= 1 && targetIdx <= SUM && !visited[targetIdx]) {
            count += 1;
        }
    }
    return count;
}

// Compare funtion
bool comp(int lhs, int rhs) {
    return countCanMove(lhs) < countCanMove(rhs);
}

void display(int printSeq[]) {
    for (int i = 1; i <= SUM; i++) {
        std::cout << printSeq[i];
        if (i != SUM) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

void DFS(int startIdx) {
    if (done) {
        return;
    }

    if (counter == SUM) {
        display(printSeq);
        done = true;
        return;
    }

    // Continue DFS
    std::vector<int> targetIdxs = canMove(startIdx);
    std::sort(targetIdxs.begin(), targetIdxs.end(), comp);

    for (int targetIdx : targetIdxs) {
        visited[targetIdx] = true;
        counter += 1;
        printSeq[counter] = targetIdx;

        DFS(targetIdx);

        visited[targetIdx] = false;
        counter -= 1;
    }
}

int main() {
    int N;
    while (std::cin >> N && N != -1) {
        for (int i = 1; i <= SUM; i++) {
            visited[i] = false;
        }
        visited[N] = true;
        printSeq[1] = N;
        counter = 1;
        done = false;

        DFS(N);
    }
}
