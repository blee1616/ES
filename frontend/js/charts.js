const ctx = document.getElementById('usageChart').getContext('2d');
let usageChart;

function renderChart(labels, data) {
    if (usageChart) {
        usageChart.destroy();
    }

    usageChart = new Chart(ctx, {
        type: 'line',
        data: {
            labels: labels,
            datasets: [{
                label: 'Energy Usage (kWh)',
                data: data,
                borderColor: 'rgba(75, 192, 192, 1)',
                backgroundColor: 'rgba(75, 192, 192, 0.2)',
                borderWidth: 1
            }]
        },
        options: {
            scales: {
                y: {
                    beginAtZero: true
                }
            }
        }
    });
}

function fetchSimulationResults() {
    fetch('/api/simulation')
        .then(response => response.json())
        .then(data => {
            const labels = data.labels;
            const usageData = data.usage;
            renderChart(labels, usageData);
        })
        .catch(error => console.error('Error fetching simulation results:', error));
}

document.getElementById('simulateButton').addEventListener('click', () => {
    fetchSimulationResults();
});