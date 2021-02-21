class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        int x = nums.size()/2;
        int y = nums.size() - x;
        int i=1, k=nums.size()-1;
        while(x--){
            nums[i] = temp[k--];
            i += 2;
        }
        i=0;
        while(y--){
            nums[i] = temp[k--];
            i += 2;
        }
    }
};
