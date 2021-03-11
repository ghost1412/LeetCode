class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int tempe=0, tempo=0, e=0, o=0;
        for(int i=0; i<nums.size(); i++){
            if(i%2==0){
                tempe += nums[i];
            }else{
                tempo += nums[i];
            }
        }
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(i%2 == 0){
                tempe = tempe - nums[i];
            }else{
                tempo = tempo - nums[i];               
            }
            if(tempe+o==tempo+e)
                count++;
            if(i%2 == 0)
                e += nums[i];
            else
                o += nums[i];
        }
        return count;
    }
};
