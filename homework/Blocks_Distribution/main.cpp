#include <iostream>
#include <queue>

struct Child {
    int has;
    int need;

    Child(int has, int need)
        : has(has), need(need) {}
};

bool operator<(const Child& lhs, const Child& rhs) {
   if (lhs.need != rhs.need) {
       return lhs.need > rhs.need;
   }
   else {
       return lhs.has < rhs.has;
   }
}

int main() {
    int n, s;
    
    while (std::cin >> n >> s && n != 0) {
        std::priority_queue<Child> children;

        for (int i = 0; i < n; i++) {
            int has, need;
            std::cin >> has >> need;
            children.emplace(has, need);
        }

        while (!children.empty()) {
            if (s >= children.top().need) {
                s += children.top().has;
                children.pop();
            }
            else {
                break;
            }
        }

        if (children.empty()) {
            std::cout << "YES" << std::endl;
        }
        else {
            std::cout << "NO" << std::endl;
        } 
    }
}