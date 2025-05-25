#ifndef ELECTRICITY_USAGE_H
#define ELECTRICITY_USAGE_H

#include <vector>
#include "appliance.h"

class ElectricityUsage {
public:
    std::vector<Appliance> appliances;
    std::vector<double> usage_matrix;

    ElectricityUsage(std::vector<Appliance> appliances);

    std::vector<double> calculate_daily_usage();
};

#endif // ELECTRICITY_USAGE_H