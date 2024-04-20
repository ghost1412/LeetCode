class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> magDic;

        for (int i=0; i<magazine.size(); i++) {
            if (magDic.find(magazine[i]) == magDic.end()) {
                magDic[magazine[i]] = 1;
            } else {
                magDic[magazine[i]]++;
            }
        }

        for (int i=0; i<ransomNote.size(); i++) { 
            if (magDic.find(ransomNote[i]) == magDic.end() || magDic[ransomNote[i]] == 0) {
                return false;
            } else {
                magDic[ransomNote[i]]--;
            }
        }
        return true;
    }
};
