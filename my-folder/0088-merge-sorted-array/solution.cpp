class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int till = (m > n) ? m : n;
        cout<<m;
        vector<int> mergedArry;
        int j=0, k=0, i=0;
        while(j<m || k<n) {               
            if (m > j && n > k) {
                if (nums1[j] < nums2[k]) {
                    mergedArry.push_back(nums1[j++]);
                } else {
                    mergedArry.push_back(nums2[k++]);
                }
            } else if (m > j) {
                mergedArry.push_back(nums1[j++]);
            } else if (n > k) {
                mergedArry.push_back(nums2[k++]);
            }
            i++;
            cout<<j<<k<<" ";
        }
        nums1 = mergedArry;
    }
};
