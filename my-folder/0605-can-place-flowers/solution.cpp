class Solution {
public:
    bool canPlaceFlowers(vector<int>& a, int n) {
        if(a.size() == 1 && a[0] == 0 && n == 1)
            return true;
        if(a.size() == 1 && a[0] == 0 && n == 0)
            return true;        
        if(a.size()<n) return false;
        if(a.size() == 1 && a[0] == 1 && n == 1)
            return false;
        if(a.size() == 1 && a[0] == 1 && n == 0)
            return true;
        for(int i=0; i< a.size(); i++){
            if(i==0 ){
                if(a[i] == 0 && a[i+1] == 0){
                    n--;
                    a[i] = 1;
                    cout<<"t";
                }
            }
            else if(i==a.size()-1) {
                if(a[i] == 0 && a[i-1] == 0){
                    n--;
                    a[i] = 1;
                    cout<<"u";
                }
            }else
                if(a[i-1] == 0 && a[i] == 0 && a[i+1] == 0){
                    n--;
                    a[i] = 1;
                    cout<<"p"<<i;
                }
            if(n<=0) return true;
        }
        cout<<n;
        if(n==0) return true;
        return false;
    }
};
