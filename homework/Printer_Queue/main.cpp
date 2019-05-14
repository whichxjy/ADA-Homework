#include <iostream>
#include <queue>

struct Job {
    int initIndex;
    int priority;

    Job(int initIndex, int priority)
        : initIndex(initIndex), priority(priority) {}
};

int main() {
    int T;
    std::cin >> T;
    for (int t = 0; t < T; t++) {
        int num;
        int pos;
        std::cin >> num >> pos;
        std::queue<Job> jobs;
        std::priority_queue<int> priorities;
        for (int i = 0; i < num; i++) {
            int priority;
            std::cin >> priority;
            jobs.emplace(i, priority);
            priorities.push(priority);
        }

        int count = 0;
        while (!jobs.empty()) {
            // The highest priority
            int max = priorities.top();
            priorities.pop();

            while (jobs.front().priority != max) {
                Job temp = jobs.front();
                jobs.pop();
                jobs.push(temp);
            }

            // Print
            count += 1;

            if (jobs.front().initIndex == pos) {
                // Your job is completely printed
                std::cout << count << std::endl;
                break;
            }
            else {
                jobs.pop();
            }
        }
    }
}