#include "electricity_usage.h"
#include "appliance.h"
#include <numeric>

ElectricityUsage::ElectricityUsage(std::vector<Appliance> appliances) : appliances(appliances) {}

std::vector<double> ElectricityUsage::calculate_daily_usage() {
    std::vector<double> usage_matrix;
    for (int hour = 0; hour < 24; hour++) {
        double total_usage = 0.0;

        for (int i = 0; i < appliances.size(); i++) {
            if (appliances[i].is_operating(hour)) {
                double appliance_wattage = appliances[i].get_random_wattage();
                total_usage += appliance_wattage;
                appliancesUsage[i] += appliance_wattage;
            }
        }
        usage_matrix.push_back(total_usage);
    }
    return usage_matrix;
}