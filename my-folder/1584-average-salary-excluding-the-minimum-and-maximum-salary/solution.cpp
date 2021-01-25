class Solution {
public:
    double average(vector<int>& salary) {
        int min1 = INT_MAX, max1 = INT_MIN;
        for(int i=0; i<salary.size(); i++){
            min1 = min(min1, salary[i]);
            max1 = max(max1, salary[i]);
        }
        double avg = 0, count = 0;
        for(int i=0; i<salary.size(); i++){
            if(salary[i]!=min1 && salary[i]!=max1){
                avg += salary[i];
                count++;
            }
        }
        return (double)(avg/count);
    }
};
