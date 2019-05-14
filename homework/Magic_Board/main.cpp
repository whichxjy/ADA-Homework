#include <iostream>
#include <array>
#include <string>
#include <set>
#include <queue>

struct Node {
    // 8 numbers
    std::array<int, 8> nums;
    // Operation
    std::string opt;

    std::string str() {
        std::string n_str = "";
        for (int i = 0; i < 8; i++) {
            n_str += nums[i];
        }
        return n_str;
    }

    bool operator==(const Node& other) {
        for (int i = 0; i < 8; i++) {
            if (this->nums[i] != other.nums[i]) {
                return false;
            }
        }
        return true;
    }
};

Node operA(const Node& node) {
    Node result;

    for (int i = 0; i < 4; i++) {
        result.nums[i] = node.nums[i + 4];
    }
    for (int i = 4; i < 8; i++) {
        result.nums[i] = node.nums[i - 4];
    }

    result.opt = node.opt + 'A';
    return result;
}

Node operB(const Node& node) {
    Node result;

    result.nums[0] = node.nums[3];
    for (int i = 1; i < 4; i++) {
        result.nums[i] = node.nums[i - 1];
    }
    result.nums[4] = node.nums[7];
    for (int i = 5; i < 8; i++) {
        result.nums[i] = node.nums[i - 1];
    }

    result.opt = node.opt + 'B';
    return result;
}

Node operC(const Node& node) {
    Node result;

    result.nums[0] = node.nums[0];
    result.nums[3] = node.nums[3];
    result.nums[4] = node.nums[4];
    result.nums[7] = node.nums[7];

    result.nums[1] = node.nums[5];
    result.nums[2] = node.nums[1];
    result.nums[6] = node.nums[2];
    result.nums[5] = node.nums[6];

    result.opt = node.opt + 'C';
    return result;
}


int main() {
    Node START;
    START.nums = { 1, 2, 3, 4, 8, 7, 6, 5 };

    int maxN;
    while (std::cin >> maxN && maxN != -1) {
        Node GOAL;
        for (int i = 0; i < 8; i++) {
            std::cin >> GOAL.nums[i];
        }
        
        std::set<std::string> visited;
        std::queue<Node> q;

        // Start BFS
        visited.insert(START.str());
        q.push(START);

        bool found = false;

        while (!q.empty()) {
            Node curr = q.front();
            q.pop();

            if (curr.opt.size() > maxN) {
                continue;
            }

            if (curr == GOAL) {
                found = true;
                std::cout << curr.opt.size() << " " << curr.opt << std::endl;
                break;
            }

            Node nextA = operA(curr);
            if (visited.find(nextA.str()) == visited.end()) {
                visited.insert(nextA.str());
                q.push(nextA);
            }

            Node nextB = operB(curr);
            if (visited.find(nextB.str()) == visited.end()) {
                visited.insert(nextB.str());
                q.push(nextB);
            }

            Node nextC = operC(curr);
            if (visited.find(nextC.str()) == visited.end()) {
                visited.insert(nextC.str());
                q.push(nextC);
            }
        }

        if (!found) {
            std::cout << -1 << std::endl;
        }
    }
}
