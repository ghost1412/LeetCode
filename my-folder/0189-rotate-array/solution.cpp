class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //1,2,3,4,5,6,7
        // 7,6,5,4,3,2,1
            //3
        //
        int n = nums.size();
        reverse(nums.begin(), nums.end());
        // int i = 0;
        // for (auto it = nums.begin(); it != nums.end(); ++it) {
        //     if (i==k) break;
        //     i++;
        // }
       // if (k>n) return;
        reverse(nums.begin()+k%n, nums.end());
        reverse(nums.begin(), nums.begin()+k%n);
    }
};
