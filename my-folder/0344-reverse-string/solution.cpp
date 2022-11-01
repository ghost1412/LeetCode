class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left <= right) {
            char tempStored = s[left];
            s[left] = s[right];
            s[right] = tempStored;
            left++, right--;
        }
    }
};
