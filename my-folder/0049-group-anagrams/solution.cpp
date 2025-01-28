struct ArrayHash {
    size_t operator()(const array<int, 26>& arr) const {
        size_t hashValue = 0;
        for (int num : arr) {
            hashValue ^= hash<int>{}(num) + 0x9e3779b9 + (hashValue << 6) + (hashValue >> 2);
        }
        return hashValue;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<array<int, 26>, vector<string>, ArrayHash> m;

        for (int i=0; i<strs.size(); i++) {
            array<int, 26> alpha = {};
            for (int j=0; j<strs[i].size(); j++) {
                alpha[strs[i][j]-'a']++;
            }

            m[alpha].push_back(strs[i]);
        }

        vector<vector<string>> res;
        for(auto s: m){ 
            res.push_back(s.second);
        }
        return res;
    }
};
