bool operator<(vector<int> a, vector<int> b){
    return a[0] < b[0];
}

class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& a) {
        vector<vector<int>> ans;
        sort(a.begin(), a.end());
        ans.push_back(a[0]);
        int pos = 0;
        for(int i=1; i<a.size(); i++){
            if(ans[pos][1] >= a[i][0]){
                vector<int> n;
                n.push_back(ans[pos][0]);
                if(ans[pos][1] > a[i][1])
                    n.push_back(ans[pos][1]);
                else
                    n.push_back(a[i][1]);
                ans.pop_back();
                ans.push_back(n);
            }else{
                ans.push_back(a[i]);
                pos++;
            }
        }
        return ans;
    }
};
