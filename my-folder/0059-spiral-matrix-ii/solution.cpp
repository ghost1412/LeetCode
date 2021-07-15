class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
       vector<vector<int>> v(n, vector<int> (n));
        int t = 0, b = n-1, l = 0, r = n-1, val = 1;
        while(val<=n*n){
            for(int i=l; i<=r; i++){
                v[t][i] = val;
                val++;
            }
            t++;
            if(val >= n*n)
                break;
            for(int i=t; i<=b; i++){
                v[i][r] = val;
                val++;
            }
            r--;
            for(int i=r; i>=l; i--){
                v[b][i] = val;
                val++;
            }
            b--;
            for(int i=b; i>=t; i--){
                v[i][l] = val;
                val++;
            }
            l++;
        }
        return v;
    }
};
