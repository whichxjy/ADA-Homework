#include <iostream>
#include <vector>

struct Segment {
    int lower;
    int upper;
    int rate;
    Segment(int lower, int upper, int rate)
        : lower(lower), upper(upper), rate(rate) {}
};

int main() {
    int count = 0;  // set number
    int weight, rate;
    while (std::cin >> weight >> rate) {
        std::vector<Segment> segs;
        // weight1 rate1
        segs.emplace_back(0, weight, rate);
        // weight2 rate2
        std::cin >> weight >> rate;
        segs.emplace_back(segs[0].upper + 1, weight, rate);
        // weight3 rate3
        std::cin >> weight >> rate;
        segs.emplace_back(segs[1].upper + 1, weight, rate);
        // rate4
        std::cin >> rate;
        segs.emplace_back(segs[2].upper + 1, 1000, rate);

        count++;
        std::cout << "Set number " << count << ":" << std::endl;

        // package size
        int size;
        while (std::cin >> size && size != 0) {
            int best;   // best price
            int addPounds = 0;
            for (Segment seg : segs) {
                if (size >= seg.lower && size <= seg.upper) {
                    best = size * seg.rate;
                }
                else if (size < seg.lower && (seg.lower * seg.rate) < best) {
                    best = seg.lower * seg.rate;
                    addPounds = seg.lower - size;
                }
            }
            std::cout << "Weight (" << size << ") has best price $"
                << best << " (add " << addPounds << " pounds)" << std::endl;
        }
        std::cout << std::endl;
    }
}
