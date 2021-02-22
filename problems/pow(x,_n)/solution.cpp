class Solution {
public:
    double fpower(double x, int n){
        if(n == 0) return 1.0;
        double res = fpower(x, n/2);
        if(n%2==0) return res*res;
        else return res*res*x;
    }
    double myPow(double x, int N) {
        bool flag = false;
        long n = N;
        if(n<0){
            n = -n;
            x = 1/x;
            flag = true;
        }
        double res = fpower(x, n);
        return res;
    }
};