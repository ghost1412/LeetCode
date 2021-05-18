class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int maxH = 0, maxV = 0, hprev = 0, vprev = 0;
        for(int i=0; i<horizontalCuts.size(); i++){
            int tempH = horizontalCuts[i] - hprev;
            maxH = max(maxH, tempH);
            hprev = horizontalCuts[i];
        }
        maxH = max(maxH, h-hprev);
        for(int i=0; i<verticalCuts.size(); i++){
            int tempV = verticalCuts[i] - vprev;
            maxV = max(maxV, tempV);
            vprev = verticalCuts[i];
        }
        maxV = max(maxV, w-vprev);
        return ((long long)maxH*maxV%1000000007);
        
    }
};
