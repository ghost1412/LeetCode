class Solution {
public:
    int maxDistToClosest(vector<int>& s) {
        int i = 0, n = s.size();
        int f = 0, l = n-1, ans = 0, cnt = 0;
        for(f=0; f<n; f++){
            if(s[f] == 1) break;
             ans++;
        }
        for(l=n-1; l>=0; l--){
            if(s[l] == 1) break;
            cnt++;
        }
        if(f!=0) f--;
        if(l!=n-1) l++;
        ans = max(ans, cnt);
        cnt = 0;
        while(f<=l){
            if(s[f] == 0)
                cnt++;
            else if(s[f] == 1){
                if(cnt%2 == 0){
                    ans = max(ans, cnt/2);
                    cnt = 0;
                }else{
                    ans = max(ans, cnt/2+1);
                    cnt = 0;
                }
            }
            f++;
        }
        return ans;
    }
};
