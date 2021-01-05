class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=0;
        for(int i=digits.size()-1; i>=0; i--){
            if(i==digits.size()-1){
                if(digits[i] < 9)
                    digits[i]++;
                else{
                    digits[i] = 0;
                    carry = 1;
                }
            }else
            if(digits[i] < 9){
                digits[i] += carry;
                carry = 0;
            }
            else{
                if(carry == 1){
                    digits[i] = 0;
                    carry = 1;
                }
            }
        }
        if(carry == 1)
            digits.insert(digits.begin(),1);
        return digits;
    }
};