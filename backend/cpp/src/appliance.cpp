#include "appliance.h"
#include <random>

double Appliance::get_random_wattage() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(min_watts, max_watts);
    return dis(gen);
}

bool Appliance::is_operating(int hour) {
    return start_time <= hour && hour < end_time;
}