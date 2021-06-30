class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> c(26, INT_MAX);
        for(int i=0; i<words.size(); i++){
            vector<int> c_t(26, 0);
            for(int j=0; j<words[i].size(); j++){
                c_t[words[i][j]-'a']++;
            }
            for(int k=0; k<26; k++){
                c[k] = min(c[k], c_t[k]);
            }
        }
        vector<string> ans;
        for(int i=0; i<26; i++){
            while(c[i]){
                char cc = (char)(i+97);
                string s;
                s += cc;
                ans.push_back(s);
                c[i]--;
            }
        }
        return ans;
    }
};