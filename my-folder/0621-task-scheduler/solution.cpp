class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int k = tasks.size();
        vector<int> c(26);
        int mx = 0;
        for(int i=0; i<k; i++){
            c[tasks[i] - 'A']++;
            mx = max(c[tasks[i] - 'A'], mx);
        }
        int ans = (mx - 1)*(n + 1);
        for(int i=0; i<26; i++)
            if(c[i] == mx)
                ans++;
        return max(ans, k);
    }
};
