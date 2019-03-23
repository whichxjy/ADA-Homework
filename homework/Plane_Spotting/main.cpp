#include <iostream>
#include <limits>
#include <queue>
#include <cmath>

struct Period {
    double average;
    int length;
    int end;
    Period(double average, int length, int end)
        : average(average), length(length), end(end) {}
};

bool operator<(const Period& lhs, const Period& rhs) {
    if (std::abs(lhs.average - rhs.average) > std::numeric_limits<double>::epsilon()) {
        // averages of lhs and rhs are not equal
        return lhs.average < rhs.average;
    }
    else if (lhs.length != rhs.length) {
        return lhs.length < rhs.length;
    }
    else {
        return lhs.end > rhs.end;
    }
}

int main() {
    int N;
    std::cin >> N;
    for (int run = 1; run <= N; run++) {
        // the number of quarters 
        int quarters;
        // the number of requested best periods
        int requested;
        // the minimum number of quarters Craig
        // wants to spend spotting planes
        int minQuarter;
        // the observed number of planes per quarter
        std::vector<int> planes;
   
        std::cin >> quarters >> requested >> minQuarter;

        for (int j = 0; j < quarters; j++) {
            int plane;
            std::cin >> plane;
            planes.push_back(plane);
        }

        std::priority_queue<Period> periods;

        for (int begin = 1; begin <= quarters; begin++) {
            int totalPlane = 0;
            for (int end = begin; end <= quarters; end++) {
                totalPlane += planes[end - 1];
                int length = end - begin + 1;
                if (length >= minQuarter) {
                    double average = (double)totalPlane / length;
                    periods.emplace(average, length, end);
                }
            }
        }

        std::cout << "Result for run " << run << ":" << std::endl;
        for (int j = 0; j < requested && j < periods.size(); j++) {
            int end = periods.top().end;
            int begin = end - periods.top().length + 1;
            std::cout << begin << "-" << end << std::endl;
            periods.pop();
        }
    }
}
