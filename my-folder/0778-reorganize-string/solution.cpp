class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        priority_queue<pair<int, char>> pq;
        vector<int> freq(26, 0);
        for (int i=0; i<s.size(); i++) {
             freq[s[i]-'a']++;
        }
        for (int i=0; i<26; i++) {
            if (freq[i] != 0) {
                pq.push({freq[i], i+'a'});
            }
        }
        string ans;
        while (!pq.empty()) {
            auto first = pq.top();
            pq.pop();
            if (pq.empty()) {
                if (first.first > 1) return "";
                ans += first.second;
                return ans;
            }
            auto second = pq.top();
            pq.pop();
            ans += first.second;
            ans += second.second;
            if (first.first-1 != 0) {
                pq.push({first.first-1, first.second});
            }
            if (second.first-1 != 0) {
                pq.push({second.first-1, second.second});
            }
            
        }
        return ans;
    }
};
