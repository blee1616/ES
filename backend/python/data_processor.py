import json

class DataProcessor:
    def __init__(self, appliances_file, rates_file):
        self.appliances_file = appliances_file
        self.rates_file = rates_file
        self.appliances = []
        self.rates = {}

    def load_appliances(self):
        with open(self.appliances_file, 'r') as file:
            self.appliances = json.load(file)

    def load_rates(self):
        with open(self.rates_file, 'r') as file:
            self.rates = json.load(file)

    def get_appliance_data(self):
        return self.appliances

    def get_rates(self):
        return self.rates

    def process_simulation_data(self, simulation_results):
        # Process and format simulation results for frontend
        processed_data = {
            "total_cost": sum(result['cost'] for result in simulation_results),
            "average_cost": sum(result['cost'] for result in simulation_results) / len(simulation_results),
            "detailed_results": simulation_results
        }
        return processed_data