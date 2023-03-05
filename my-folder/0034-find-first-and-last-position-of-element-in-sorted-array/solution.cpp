class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int sz = nums.size();
        if (sz == 0) return vector<int> {-1, -1};

        if (sz == 1) {
            if (nums[0] == target) return vector<int> {0, 0};
            else return vector<int> {-1 , -1};
        }

        int first = 1, last = sz - 1, mid, firstIndex = 0;
        mid = first + (last - first)/2;

        while(first <= last) {

            if (nums[mid - 1] < target && nums[mid] == target) {
                firstIndex = mid;
                cout<<firstIndex;
                break;
            } else if (nums[mid] < target) {
                first = mid + 1;
            } else {
                last = mid - 1;
            }
            mid = first + (last - first) / 2;
        }

        if (firstIndex == 0 && nums[0] != target) return vector<int> {-1, -1};

        first = firstIndex;
        last = sz - 2;
        int lastIndex = sz - 1;
        mid = first + (last - first)/2;
    
        while (first <= last) {

            if (nums[mid+1] > target && nums[mid] == target) {
                lastIndex = mid;
                break;
            } else if (nums[mid] > target) {
                last = mid - 1;
            } else {
                first = mid + 1;
            }
            mid = first + (last - first) / 2;
        }
        return vector<int> {firstIndex, lastIndex};
    }
};
