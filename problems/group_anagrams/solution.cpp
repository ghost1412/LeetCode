class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size() == 0){
            return {{}};
        }
        unordered_map<string, vector<string>> mp;
        for(auto s: strs){
            string temp(s);
            sort(temp.begin(), temp.end());
            mp[temp].push_back(s);
        }
        vector<vector<string>> res;
        for(auto s: mp){
            res.push_back(s.second);
        }
        return res;
    }
};