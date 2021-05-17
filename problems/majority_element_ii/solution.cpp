class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = 0, c2 = 0;
        int a, b;
        for(int n: nums){
            if(a == n)
                c1++;
            else if(b == n)
                c2++;
            else if(c1 == 0 ){
                c1++;
                a = n;
            }
            else if(c2 == 0 ){
                c2++;
                b = n;
            }else{
                c1--;
                c2--;
            }
        }
        c1 = c2 = 0;
        for(int n:nums){
            if(n == a) c1++;
            else if(n == b) c2++;
        }
        vector<int> result;
        if(c1 > nums.size()/3) result.push_back(a);
        if(c2 > nums.size()/3) result.push_back(b);
        return result;
    }
};