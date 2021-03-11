class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if(n>=1){
            if(n%2==1)
                ans.push_back(0);
        }
        else
            return ans;
        for(int i=1; i<n;){
            ans.push_back(i);
            ans.push_back(i*-1);
            i+=2;
        }
        return ans;
    }
};