#include "energy_report.h"
#include <numeric>

EnergyReport::EnergyReport(std::vector<double> usage_data, int month_number, double peak_rate, double off_peak_rate)
    : usage_data(usage_data), month_number(month_number), peak_rate(peak_rate), off_peak_rate(off_peak_rate) {}

double EnergyReport::calculate_cost_per_month() {
    int days_in_month = (month_number == 1) ? 28 : 30;
    double cost = 0.0;
    for (int day = 0; day < days_in_month; day++) {
        for (int hour = 0; hour < 24; hour++) {
            double rate = (hour >= 17 && hour <= 19) ? peak_rate : off_peak_rate;
            cost += usage_data[hour] * rate / 1000; // Convert watts to kWh
        }
    }
    return cost;
}