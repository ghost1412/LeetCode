class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        unordered_set<int> s;
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        for(auto it=mp.begin(); it!=mp.end(); it++){
            if(s.find(it->second)==s.end())
                s.insert(it->second);
            else
                return 0;
        }
        return 1;
    }
};