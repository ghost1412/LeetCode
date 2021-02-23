class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int h = 0;
       // if(citations.size()!=0 && h == 0 && citations[0] != 0) h = 1;
        for(int i=1; i<=citations.size(); i++){
            //cout<<citations[i];
          //  cout<<citations.size()-i;
            if(citations[citations.size()-i]>=i)
                h = i;
                
        }
        return h;
    }
};
