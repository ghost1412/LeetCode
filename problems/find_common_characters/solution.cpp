class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> c(26, INT_MAX);
        for(int i=0; i< A.size(); i++){
            vector<int> temp(26, 0);
            for(int j=0; j<A[i].size(); j++){
                //cout<<(int)A[i][j] - 'a'<<" ";
                temp[(int)A[i][j] - 'a'] += 1;
            }
            for(int i=0; i<26; i++)
                c[i] = min(c[i], temp[i]);
        }
        vector<string> ans;
        string s = "";
        for(int i=0; i<c.size(); i++){
            s = "";
            if(c[i] != INT_MAX){
                while(c[i]--){
                    s = "";
                    s += (char)i + 'a';
                    ans.push_back(s);          
                }
            }
        }
        return ans;
    }
};