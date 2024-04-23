class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        stringstream ss(s);
        string word;
        int index = 0;

        while (ss >> word) {
            if (index >= pattern.size()) {
                return false; // More words than characters in pattern
            }

            char c = pattern[index];
            if (charToWord.find(c) == charToWord.end() && wordToChar.find(word) == wordToChar.end()) {
                charToWord[c] = word;
                wordToChar[word] = c;
            } else {
                if (charToWord[c] != word || wordToChar[word] != c) {
                    return false; // Conflict in mapping
                }
            }

            index++;
        }

        return index == pattern.size(); // Check if all characters in pattern were used
    }
};

