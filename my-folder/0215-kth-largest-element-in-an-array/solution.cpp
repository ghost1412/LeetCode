class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(count<k){
                pq.push(nums[i]);
                count++;
            }else{
                if(pq.top() < nums[i]){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
        return pq.top();
    }
};
