class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> m;
        for(int i=0; i<arr1.size(); i++){
            m[arr1[i]]++;
        }
        int j=0;
        for(int i=0; i<arr2.size(); i++){
            while(m[arr2[i]]--){
                arr1[j++] = arr2[i];
            }
        }
        for(auto it:m){
            cout<<it.second;
            while(it.second>0){
                arr1[j++] = it.first;
                //cout<<it.first;
                it.second--;
            }
        }
        return arr1;
    }
};
