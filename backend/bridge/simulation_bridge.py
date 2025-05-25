from ctypes import CDLL, c_double, POINTER
import os

class SimulationBridge:
    def __init__(self):
        self.lib = CDLL(os.path.join(os.path.dirname(__file__), 'cpp_module.so'))

    def run_simulation(self):
        self.lib.run_simulation.restype = POINTER(c_double)
        result = self.lib.run_simulation()
        return [result[i] for i in range(12)]  # Assuming 12 months of data

    def get_appliance_usage(self):
        self.lib.get_appliance_usage.restype = POINTER(c_double)
        usage = self.lib.get_appliance_usage()
        return [usage[i] for i in range(12)]  # Assuming 12 appliances

    def calculate_cost(self, month_number):
        self.lib.calculate_cost.argtypes = [c_double]
        self.lib.calculate_cost.restype = c_double
        return self.lib.calculate_cost(month_number)