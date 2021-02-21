class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1)return true;
        for(int i=1; i<=num/2; i++){
            float temp = (float)num/i;
            if(temp == i)
                return true;
        }
        return false;
    }
};