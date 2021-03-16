class Solution {
public:
    string pushDominoes(string dominoes) {
        string ans = "";
        int n = dominoes.size();
        vector<int> f(n, 0);
        int df = 0;
        for(int i=0; i<n; i++){
            if(dominoes[i] == 'R') df = n;
            else if(dominoes[i] == 'L') df = 0;
            else df = max(df-1, 0);
            f[i] += df;
        }
        df = 0;
        for(int i=n-1; i>=0; i--){
            if(dominoes[i] == 'L') df = n;
            else if(dominoes[i] == 'R') df = 0;
            else df = max(df-1, 0);
            f[i] -= df;
        }
        for(int i=0; i<n; i++){
            if(f[i] > 0) ans += 'R';
            else if(f[i] < 0) ans += 'L';
            else ans += '.';
        }
        return ans;
    }
};
