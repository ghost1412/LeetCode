class Solution {
public:
    void sortColors(vector<int>& a) {
        int x=0, y=0, z=0;
        for(int i=0; i<a.size(); i++){
            if(a[i]==0) x++;
            else if(a[i]==1) y++;
            else if(a[i]==2) z++;
        }
        for(int i=0; i<a.size(); i++){
            if(x-->0) a[i]=0;
            else if(y-->0) a[i]=1;
            else if(z-->0) a[i]=2;
        }
    }
};