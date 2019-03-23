#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

struct Node {
    std::string BBS_ID;
    std::string Main_ID;
    Node(const std::string& BBS_ID, const std::string& Main_ID)
        : BBS_ID(BBS_ID), Main_ID(Main_ID) {}
};

bool comp(const Node& nodeA, const Node& nodeB) {
    return nodeA.Main_ID < nodeB.Main_ID;
}

int main() {
    int N;
    while (std::cin >> N && N != 0) {
        // IP address -> Main ID
        std::map<std::string, std::string> Main_ID;
        std::vector<Node> result;
        for (int i = 0; i < N; i++) {
            std::string BBS_ID, IP_Address;
            std::cin >> BBS_ID >> IP_Address;
            if (Main_ID.count(IP_Address) > 0) {
                result.emplace_back(BBS_ID, Main_ID[IP_Address]);
            }
            else {
                Main_ID[IP_Address] = BBS_ID;
            }
        }
        std::sort(result.begin(), result.end(), comp);
        for (Node node : result) {
            std::cout << node.BBS_ID << " is the MaJia of " << node.Main_ID << std::endl;
        }
        std::cout << std::endl;
    }
}