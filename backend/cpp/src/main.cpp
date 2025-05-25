#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <numeric>
#include "appliance.h"
#include "electricity_usage.h"
#include "energy_report.h"

std::vector<double> monthCosts;
std::vector<double> appliancesUsage(13);

std::ofstream MonthlyCost; 
std::ofstream JoulesPerAppliance; 

int main() {
    std::vector<Appliance> appliances = {
        Appliance("Fridge", 300, 450, 0, 24),
        Appliance("Mini Fridge", 30, 70, 0, 24),
        Appliance("Stove", 1000, 2000, 9, 10),
        Appliance("Toaster & Microwave", 800, 1600, 8, 14),
        Appliance("Oven", 2000, 3000, 17, 18),
        Appliance("Phone(s) & Tablet(s)", 15, 50, 0, 24),
        Appliance("Laptop(s)", 30, 90, 0, 24),
        Appliance("PC(s)", 50, 350, 0, 24),
        Appliance("TV(s)", 50, 100, 8, 18),
        Appliance("Lightbulbs & Lamps", 20, 80, 0, 24),
        Appliance("Washing Machine", 800, 1000, 17, 18),
        Appliance("Dryer", 1800, 3200, 18, 19),
    };

    for (int month = 0; month < 12; month++) {
        if (month == 6) {
            appliances.push_back(Appliance("AC", 4000, 5000, 10, 18));
        } else if (month == 9) {
            appliances.pop_back();
        }

        ElectricityUsage usage(appliances);
        std::vector<double> hourly_usage = usage.calculate_daily_usage();

        EnergyReport report(hourly_usage, month);
        monthCosts.push_back(report.calculate_cost_per_month());
    }

    MonthlyCost.open("MonthlyCosts.txt");
    JoulesPerAppliance.open("JoulesPerAppliance.txt");

    for (double cost : monthCosts) {
        MonthlyCost << cost << std::endl;
    }

    for (int i = 0; i < appliancesUsage.size(); i++) {
        JoulesPerAppliance << appliancesUsage[i] << std::endl;
    }

    MonthlyCost.close();
    JoulesPerAppliance.close();
    return 0;
}