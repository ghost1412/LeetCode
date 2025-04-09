class Solution {
   // unordered_set<long long> pattern;
public:
    long long breakDownNumber(int n) {
        long long sum = 0;
        int temp;
        while (n > 0) {
            temp = n % 10;
            n /= 10;
            sum += temp*temp;
        }
        return sum;
    }

    bool isHappy(int n) {
        if (n == 1) return true;
        // if (pattern.count(n) > 0) return false;
        // pattern.insert(n);
        // long long newN = breakDownNumber(n);
        // if (newN == 1) return true;
        // return isHappy(newN);
        int slow = n;
        int fast = n;
        do {
            slow = breakDownNumber(slow);
            fast = breakDownNumber(breakDownNumber(fast));
        } while (slow != fast);

        return slow ==  1;
    }
};
