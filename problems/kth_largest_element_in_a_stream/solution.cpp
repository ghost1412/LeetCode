class KthLargest {
priority_queue<int, vector<int>,   
                       greater<int> > pq;
int count = 0, kk;    
public:
    KthLargest(int k, vector<int>& nums) {
        kk = k;
        for(int i=0; i<nums.size(); i++){
            if(count<k){
                pq.push(nums[i]);
                count++;
            }
            else{
                int top = pq.top();
                if(top < nums[i]){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
    }
    
    int add(int val) {
        if(count<kk){
            pq.push(val);
            count++;
            return pq.top();
        }else{
            int top = pq.top();
            if(top < val){
                pq.pop();
                pq.push(val);
                return pq.top();
            }else{
                return pq.top();
            }
        }
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */