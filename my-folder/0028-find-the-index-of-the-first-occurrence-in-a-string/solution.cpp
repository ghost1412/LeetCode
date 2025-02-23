class Solution {
public:
    int strStr(string haystack, string needle) {
        int s = 0, i = 0;
        if (needle.size() > haystack.size()) return -1;
        while (s <= haystack.size() - needle.size()) {
            i = 0;
            while (i<needle.size() && haystack[s+i] == needle[i]) {
                i++;
            }
            if (i == needle.size()) return s;
            s++;
        }
        return -1;
    }
};
