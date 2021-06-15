class Solution {
public:
    int reverse(int n) {
        long long x = n;
        bool flag = 0;
        if(x<0){
            flag = 1;
            x *= -1;
        } 
        long long ans = 0, carry;
        while(x){
            carry = x%10;
            ans = ans*10 + carry;
            x = x/10;
        }
        if(ans > std::numeric_limits<int>::max()) return 0;
        if(flag) ans *= -1;
        return ans;
    }
};