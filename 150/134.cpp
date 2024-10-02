class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        int fuelTank = 0;
        int startStation = 0;

        for (int i = 0; i < gas.size(); ++i) {
            totalGas += gas[i];
            totalCost += cost[i];

            fuelTank += gas[i] - cost[i];

            if (fuelTank <0) {
                fuelTank = 0;
                startStation = i +1;
            }
        }
        return (totalGas >= totalCost ? startStation : -1);
    }
};