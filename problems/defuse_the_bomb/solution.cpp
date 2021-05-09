class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans;
        int n = code.size();
        bool flag = 0;
        if(k < 0){
            reverse(code.begin(), code.end());
            k *= -1;   
            flag = 1;
        }
        for(int i=0; i<code.size(); i++){
            if(k == 0)
                ans.push_back(0);
            else{
                int sum = 0;
                for(int j=(i+1); j<=(i+k);){
                    sum += code[j%n];
                    if(j%n==(i+k)%n) break;
                    j = (j+1)%n;
                }
                ans.push_back(sum);
            }
        }
        if(flag) reverse(ans.begin(), ans.end());
        return ans;
    }
};