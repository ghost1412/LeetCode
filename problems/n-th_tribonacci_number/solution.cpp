class Solution {
public:
    int tribonacci(int n) {
        int num1 = 0, num2 = 1, num3 = 1;
        if (n == 0) return num1;
        if (n == 1 || n == 2) return num2;

        for (int i=3; i<=n; i++) {
            int temp = num3;
            num3 += (num1 + num2);
            num1 = num2;
            num2 = temp;
        }
        return num3;
    }
};