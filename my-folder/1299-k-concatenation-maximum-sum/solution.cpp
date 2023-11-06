class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int maxSum = 0, sum = 0;
        int n = arr.size();
        for (auto i=0; i<min(2,k)*n; ++i) {
            sum = max(sum + arr[i % n], arr[i % n]);
            maxSum = max(maxSum, sum); 
        }
        long long arraySum = accumulate(begin(arr), end(arr), 0ll);
        return ((long long)maxSum +  max(0ll, arraySum) * max(0, k - 2)) % 1000000007;
    }
};
