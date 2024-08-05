class Solution {
public:
    bool checkAllSame(const string& word, bool isUpperCase) {
        for (char ch : word) {
            if ((isUpperCase && !isupper(ch)) || (!isUpperCase && isupper(ch))) {
                return false;
            }
        }
        return true;
    }

    bool detectCapitalUse(const string& word) {
        if (word.empty()) return false;

        bool isFirstUpper = isupper(word[0]);

        if (isFirstUpper) {
            return checkAllSame(word.substr(1), isupper(word[1]));
        } else {
            return checkAllSame(word, false);
        }
    }
};

