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
                resultsContainer.innerHTML = "<p>Error occurred while running the simulation.</p>";
            });
    });

    function displayResults(data) {
        resultsContainer.innerHTML = ""; // Clear previous results
        const costElement = document.createElement("p");
        costElement.textContent = `Total Cost: $${data.total_cost.toFixed(2)}`;
        resultsContainer.appendChild(costElement);

        const usageList = document.createElement("ul");
        data.appliance_usage.forEach(appliance => {
            const listItem = document.createElement("li");
            listItem.textContent = `${appliance.name}: ${appliance.joules_used} Joules`;
            usageList.appendChild(listItem);
        });
        resultsContainer.appendChild(usageList);
    }
});