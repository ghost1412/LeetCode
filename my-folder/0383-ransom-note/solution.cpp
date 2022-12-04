class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> m1, m2;
        for (int i=0; i<magazine.size(); i++) {
            m1[magazine[i]]++;
        }
        for (int i=0; i<ransomNote.size(); i++) {
            m2[ransomNote[i]]++;
        }
        for (int i=0; i<ransomNote.size(); i++) {
            if (m2[ransomNote[i]] > m1[ransomNote[i]]) {
                return false;
            }
        }
        return true;
    }
};
