#ifndef APPLIANCE_H
#define APPLIANCE_H

#include <string>
#include <random>

class Appliance {
public:
    std::string name;
    double min_watts, max_watts;
    int start_time, end_time;

    Appliance(std::string name, double min_watts, double max_watts, int start_time, int end_time);

    double get_random_wattage();

    bool is_operating(int hour);
};

#endif // APPLIANCE_H