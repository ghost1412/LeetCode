class comFunction {
    public:
        int operator()(pair<int,string> &a, pair<int,string> &b){
            if(a.first==b.first) {
                return a.second.compare(b.second)<0;
            }
            return a.first>b.first;
        }
};
class Solution {
public:

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for(int i=0; i<words.size(); i++){
            m[words[i]]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, comFunction> pq;
        int count = 0;
        for(auto it=m.begin(); it!=m.end(); it++){
            pq.push(make_pair(it->second, it->first));
            if(pq.size()>k){
                pq.pop();
            }
        }
        words.clear();
        while(!pq.empty()){
            words.push_back(pq.top().second);
            pq.pop();
        }
        reverse(words.begin(), words.end());
        return words;
    }
};
