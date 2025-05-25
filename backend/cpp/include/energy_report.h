#ifndef ENERGY_REPORT_H
#define ENERGY_REPORT_H

#include <vector>

class EnergyReport {
public:
    std::vector<double> usage_data;
    double peak_rate, off_peak_rate;
    int month_number;

    EnergyReport(std::vector<double> usage_data, int month_number, double peak_rate = 0.30, double off_peak_rate = 0.20);

    double calculate_cost_per_month();
};

#endif // ENERGY_REPORT_H