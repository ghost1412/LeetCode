class Solution {
public:
    
    bool binarySearch(vector<int> m, int target, int l, int r) {
        if (l <= r) {
            int mid = l + (r - l)/2;
            if (m[mid] == target) return true;
            else if (m[mid] > target) return binarySearch(m, target, l, mid-1);
            else return binarySearch(m, target, mid+1, r);
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i=0; i < matrix.size(); i++) {
            if (target == matrix[i][matrix[i].size() - 1]) {
                return true;
            } else {
                if (target < matrix[i][matrix[i].size() - 1]) {
                    return binarySearch(matrix[i], target, 0, matrix[i].size() - 1);
                }
            }
        }
        return false;
    }
};