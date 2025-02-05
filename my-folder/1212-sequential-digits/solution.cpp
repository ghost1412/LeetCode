class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string base = "123456789";
        int seq = 0;
        for (int i=2; i<=base.size(); i++) {
            for (int j=0; j<=base.size()-i; j++) {
                seq = stoi(base.substr(j, i));
                if (seq >= low && seq <= high) {
                    ans.push_back(seq);
                }
            }
        }
        return ans;
    }
};
