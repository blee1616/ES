from flask import Flask, jsonify, request
import subprocess
import json

app = Flask(__name__)

@app.route('/simulate', methods=['POST'])
def simulate():
    try:
        # Call the C++ simulation executable
        result = subprocess.run(['./path_to_cpp_executable'], capture_output=True, text=True)
        
        # Assuming the C++ program outputs JSON data
        simulation_results = json.loads(result.stdout)
        
        return jsonify(simulation_results), 200
    except Exception as e:
        return jsonify({"error": str(e)}), 500

if __name__ == '__main__':
    app.run(debug=True)