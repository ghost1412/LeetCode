class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        int num1 = 0, num2 = 1;
        for (int i=2; i<=n; i++) {
            num2 += num1;
            num1 = num2 - num1;
        }
        return num2;
    }
};
