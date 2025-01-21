class Solution {
public:

    bool isOneLetterDiff(string a, string b) {
        int count = 0;
        for (int i=0; i<a.size(); i++) {
            if (a[i] != b[i]) count++;
            if (count > 1) return false;
        }
        return count == 1;
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string, int>> q;
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if (bankSet.find(endGene) == bankSet.end()) return -1;

        q.push({startGene, 0});

        while (!q.empty()) {

            auto [currentGene, level] = q.front();
            q.pop();
            for (auto it=bankSet.begin(); it!=bankSet.end();) {

                string nextGene = *it;
                if (isOneLetterDiff(currentGene, nextGene)) {
                    if (nextGene == endGene) {                   

                        return level + 1;
                    }
                    it = bankSet.erase(it);
                    q.push({nextGene, level+1});
                } else {
                    it++;
                }
            }
        }
        return -1;
    }
};
