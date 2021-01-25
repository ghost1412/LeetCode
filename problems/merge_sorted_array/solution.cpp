class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int loc = m; 
        for(int i=m; i<nums1.size(); i++) nums1[i] = INT_MIN;
        if(loc) loc--;
        int i = nums1.size()-1, j = nums2.size()-1;
        while(loc>=0 && j>=0 && i>=0){             
            if(nums1[loc] > nums2[j]){
                if(i==loc && j==0){
                    nums1[i] = nums2[j];
                    return;
                }
               // cout<<nums1[loc]<<i;
                nums1[i--] = nums1[loc];
                nums1[loc] = INT_MIN;
                if(loc!=0) loc--;
            }else{           
                nums1[i--] = nums2[j--];
            }
        }
    }
};