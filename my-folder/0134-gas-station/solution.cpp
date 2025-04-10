class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalTank = 0, currTank = 0, index = 0;

        for (int i=0; i<gas.size(); i++) {
            int diff = gas[i] - cost[i];
            currTank += diff;
            totalTank += diff;

            if (currTank < 0) {
                index = i + 1;
                currTank = 0;
            }
        }
        return (totalTank >= 0) ? index : -1;
    }
};
