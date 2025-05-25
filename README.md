# Energy Simulation Project

This project simulates energy consumption and cost calculations for various household appliances. It integrates a C++ backend with a Python API and a frontend built using HTML, CSS, and JavaScript.

## Project Structure

```
energy-simulation
├── backend
│   ├── cpp
│   │   ├── include
│   │   │   ├── appliance.h
│   │   │   ├── electricity_usage.h
│   │   │   └── energy_report.h
│   │   ├── src
│   │   │   ├── appliance.cpp
│   │   │   ├── electricity_usage.cpp
│   │   │   ├── energy_report.cpp
│   │   │   └── main.cpp
│   │   ├── CMakeLists.txt
│   │   └── compile.sh
│   ├── python
│   │   ├── api.py
│   │   ├── data_processor.py
│   │   ├── simulation_wrapper.py
│   │   └── requirements.txt
│   └── bridge
│       ├── cpp_module.cpp
│       ├── setup.py
│       └── simulation_bridge.py
├── frontend
│   ├── css
│   │   ├── style.css
│   │   └── charts.css
│   ├── js
│   │   ├── main.js
│   │   ├── simulation.js
│   │   └── charts.js
│   ├── index.html
│   └── results.html
├── data
│   ├── appliances.json
│   ├── rates.json
│   └── simulation_results
│       └── .gitkeep
├── .gitignore
├── README.md
└── setup.sh
```

## Setup Instructions

1. **Clone the Repository**
   ```
   git clone <repository-url>
   cd energy-simulation
   ```

2. **Set Up the Backend**
   - Navigate to the `backend/cpp` directory and compile the C++ code:
     ```
     cd backend/cpp
     ./compile.sh
     ```
   - Install Python dependencies:
     ```
     cd python
     pip install -r requirements.txt
     ```

3. **Set Up the Bridge**
   - Navigate to the `backend/bridge` directory and install the bridge package:
     ```
     cd bridge
     python setup.py install
     ```

4. **Run the Flask API**
   - Start the Flask server:
     ```
     python api.py
     ```

5. **Set Up the Frontend**
   - Open `frontend/index.html` in a web browser to access the application.

## Usage

- Click the "Simulate" button on the frontend to run the energy simulation.
- The results will be displayed on the screen, showing energy consumption statistics and costs.

## Contributing

Contributions are welcome! Please submit a pull request or open an issue for any enhancements or bug fixes.

## License

This project is licensed under the MIT License. See the LICENSE file for details.