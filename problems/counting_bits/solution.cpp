class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bin(num+1);
        for(int i=1; i<=num; i++){
            bin[i] = bin[i/2]+i%2;
        }
        return bin;
    }
};