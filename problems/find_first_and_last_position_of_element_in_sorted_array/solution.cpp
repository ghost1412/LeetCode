class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0)
            return vector<int>{-1, -1};
        if(n == 1)
            return (nums[0] == target)? vector<int>{0, 0}: vector<int>{-1, -1};
        int s = 1, e = n - 1, mid = s + (e - s)/2, first = 0;
        while(s <= e){
            if(nums[mid-1] < target && nums[mid] == target){
                first = mid;
                break;
            }
            else if(nums[mid] < target)
                s = mid + 1;
            else 
                e = mid - 1;
            mid = s + (e - s)/2;
        }
        if(first == 0 && target != nums[0]) return vector<int>{-1, -1};
        s = first;
        e = n - 2;
        mid = s + (e - s)/2;
        int last = n - 1;
        while(s <= e){
            if(nums[mid] == target && nums[mid+1] > target){
                last = mid;
                break;
            }
            else if(nums[mid] > target){
                e = mid - 1;
            }
            else
                s = mid + 1;
            mid = s + (e - s)/2;
        }
        return vector<int>{first, last};
    }
};