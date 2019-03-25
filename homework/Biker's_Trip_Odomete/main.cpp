#include <iostream>
#include <iomanip>

int main() {
    int count = 0;
    double diameter, time;
    int revolutions;
    while (std::cin >> diameter >> revolutions >> time && revolutions != 0) {
        count += 1;
        double distant = (3.1415927 * diameter * revolutions) / (12 * 5280);
        double MPH = (60 * 60 * distant) / time;
        std::cout << "Trip #" << count << ": "
            << std::fixed << std::setprecision(2)
            << distant << " " << MPH << std::endl;
    }
}
