class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int ev = 0, odd = 0;
        for(int i=0; i<position.size(); i++){
            if(position[i]%2 == 0){
                ev++;
            }else{
                odd++;
            }
        }
        return min(ev, odd);
    }
};