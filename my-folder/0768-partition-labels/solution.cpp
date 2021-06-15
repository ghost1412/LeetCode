class Solution {
public:
    
    vector<int> partitionLabels(string s) {
        int mp[26] = {0};
        for(int i=0; i<s.size(); i++){
            mp[s[i]-'a'] = i;
        }
        int i=0;
        vector<int> ans;
        while(i<s.length()){
            int end = mp[s[i] - 'a'];
            int j = i;
            while(j != end){
                end = max(end, mp[s[j] - 'a']);
                j++;
            }
            ans.push_back(j-i+1);
            i = j+1;
        }
        return ans;
    }
};
