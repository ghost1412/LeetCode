class Solution {
public:

    // int getDiffInStrings(string a, string b) {
    //     int count;
    //     for (int i=0; i<a.size(); i++) {
    //         if (a[i]!=b[i]) count++;
    //     }
    //     return count;
    // }

    // void makeGraph(string beginWord, string endWord, vector<string>& wordList, map<string, priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>>> & graph) {
    //     string current = beginWord;
    //     for (int i=0; i<=wordList.size(); i++) {
    //         if (i==0) {
    //             current = beginWord;
    //         } else {
    //             current = wordList[i-1];
    //         }
    //         for (int j=i; j<wordList.size(); j++) {
    //             int diffCurrent = getDiffInStrings(current, wordList[j]);
    //             int targetDiff = getDiffInStrings(endWord, wordList[j]);
    //             if (diffCurrent == 1) {
    //                 graph[current].push(make_pair(targetDiff, wordList[j]));
    //             }
    //         }
    //     }
    // }

    // int traverse(string currentWord, string endWord, map<string, priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>>> & graph, int &dist) {
    //     if (currentWord == endWord) {
    //         return dist;
    //     }
    //     if (graph.find(currentWord) == graph.end()) { 
    //       //  cout<<currentWord;
    //         return 0;
    //     }
    //     string closestWord = graph[currentWord].top().second;
    //     return traverse(closestWord, endWord, graph, ++dist);
    // }

        bool isOneLetterDiff(string& a, string& b) {
            int count = 0;
            for (int i = 0; i < a.size(); i++) {
                if (a[i] != b[i]) {
                    count++;
                }
                if (count > 1) return false;
            }
            return count == 1;
        }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // map<string, priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>>> graph;
        // makeGraph(beginWord, endWord, wordList, graph);
        // int dist = 0;
        // return traverse(beginWord, endWord, graph, dist);
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }
        queue<pair<string, int>> q;
        q.push({beginWord, 1});


         while (!q.empty()) {
            auto [currentWord, level] = q.front();
            q.pop();
            for (auto it = wordSet.begin(); it != wordSet.end(); ) {
                string nextWord = *it;
                if (isOneLetterDiff(currentWord, nextWord)) {
                    if (nextWord == endWord) {
                        return level + 1;
                    }
                    it = wordSet.erase(it);
                    q.push({nextWord, level + 1});
                } else {
                    it++;
                }
            }
         }
         return 0;
    }
};
/*
hit -> hot

hot -> dot
hot -> log

dot -> hot
dot -> log
dot -> dog

log -> cog
log -> dog

dog -> log
dog -> dot

cog -> dog
cog -> log

*/
