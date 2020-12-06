class Solution {
public:
    bool canJump(vector<int>& a) {
        if(a.size() == 1)
            return true;
        int max_1 = 0;
        for(int i=0; i<a.size(); i++){
            if(i<=max_1)
                max_1 = max(i+a[i], max_1);
        }
        return max_1>=a.size()-1;
    }
};