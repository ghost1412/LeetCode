class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> temp(arr.size(), 0);
        for(int i=0; i<arr.size(); i++)
            temp[i] = abs(arr[i] - x);
        int i = 0, j = arr.size()-1;
        vector<int> ans;
        while((j-i) >= k && (j > i)){
            if(temp[i] > temp[j]) i++;
            else j--;
        }
        cout<<i<<j;
        for(; i<=j; i++)
            ans.push_back(arr[i]);
        return ans;
    }
};
