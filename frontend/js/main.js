document.addEventListener("DOMContentLoaded", function() {
    const simulateButton = document.getElementById("simulate-button");
    const resultsContainer = document.getElementById("results-container");

    simulateButton.addEventListener("click", function() {
        fetch("/api/simulate")
            .then(response => response.json())
            .then(data => {
                displayResults(data);
            })
            .catch(error => {
                console.error("Error:", error);
                resultsContainer.innerHTML = "An error occurred while running the simulation.";
            });
    });

    function displayResults(data) {
        resultsContainer.innerHTML = `
            <h2>Simulation Results</h2>
            <p>Monthly Costs: ${data.monthly_costs.join(", ")}</p>
            <p>Appliance Usage: ${data.appliance_usage.join(", ")}</p>
        `;
    }
});