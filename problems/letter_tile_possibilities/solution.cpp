class Solution {
public:
    void find_all(string &s, vector<bool> &visited, string &curr, unordered_set<string> &set){
        for(int i=0; i<s.size(); i++){
            if(visited[i]==false){
                curr.push_back(s[i]);
                visited[i] = true;
                set.insert(curr);
                find_all(s, visited, curr, set);
                visited[i] = false;
                curr.pop_back();
            }
        }
    }
    int numTilePossibilities(string tiles) {
        vector<bool> visited(tiles.size());
        unordered_set<string> set;
        string curr;
        find_all(tiles, visited, curr, set);
        return set.size();
    }
};