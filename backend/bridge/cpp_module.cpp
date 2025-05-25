#include <Python.h>
#include "../cpp/include/electricity_usage.h"
#include "../cpp/include/energy_report.h"
#include "../cpp/include/appliance.h"

static PyObject* run_simulation(PyObject* self, PyObject* args) {
    // Initialize appliances
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

    ElectricityUsage usage(appliances);
    std::vector<double> hourly_usage = usage.calculate_daily_usage();

    EnergyReport report(hourly_usage, 1); // Assuming month 1 for simplicity
    double cost = report.calculate_cost_per_month();

    return Py_BuildValue("d", cost); // Return the cost as a Python float
}

static PyMethodDef SimulationMethods[] = {
    {"run_simulation", run_simulation, METH_VARARGS, "Run the energy simulation."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef simulationmodule = {
    PyModuleDef_HEAD_INIT,
    "simulation",
    NULL,
    -1,
    SimulationMethods
};

PyMODINIT_FUNC PyInit_simulation(void) {
    return PyModule_Create(&simulationmodule);
}