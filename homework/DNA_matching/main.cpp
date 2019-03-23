#include <iostream>
#include <string>
#include <set>
#include <map>

int main() {
    // nucleotide -> nucleotide
    std::map<char, char> pair;
    pair['A'] = 'T';
    pair['T'] = 'A';
    pair['C'] = 'G';
    pair['G'] = 'C';

    int T;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        int count = 0;
        std::multiset<std::string> strands;
        int N;
        std::cin >> N;
        for (int j = 0; j < N; j++) {
            std::string strand, match_strand = "";
            std::cin >> strand;
            for (char nucleotide : strand) {
                match_strand += pair[nucleotide];
            }
            const auto hit = strands.find(match_strand);
            if (hit != strands.end()) {
                // match
                count += 1;
                strands.erase(hit);
            }
            else {
                strands.insert(strand);
            }
        }
        std::cout << count << std::endl;
    }
}
