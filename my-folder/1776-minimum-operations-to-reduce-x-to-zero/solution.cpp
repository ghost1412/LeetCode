class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        if(nums.size() == 1 && nums[0] == x) return 1;
        else if(nums.size() == 1 && nums[0] != x) return -1;
        for(int i=0; i<nums.size(); i++) sum+=nums[i];
        int k = sum-x;
        if(k<0) return -1;
        int maxl = -1;
        int i = 0, j = 0;
        int sof = 0;
        while(j<nums.size() && i<nums.size()){
            sof += nums[j];
            //cout<<sof;
            while(sof > k){
                sof -= nums[i];
                i++;
            }
            if(sof == k){
                cout<<j<<i;
                cout<<endl<<sof;
                maxl = max(maxl, j-i+1);
                sof -= nums[i];
                i++;
            }
            j++;
        }
      //  cout<<maxl;
        if(maxl >= 0)
        return nums.size() - maxl;
        else return -1;
    }
};
