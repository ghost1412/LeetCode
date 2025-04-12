class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int maxProdF = 0, maxProd = 1, minProd = 1;

        for (int& a : nums) {
           if (a<0) swap(maxProd, minProd);
           maxProd = max(maxProd*a, a);
           minProd = min(minProd*a, a);
           maxProdF = max(maxProd, maxProdF);
        }
        return maxProdF;
    }
};
