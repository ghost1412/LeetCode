class Solution {
public:
    
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> p(stones.begin(), stones.end());
        while(p.size() > 1){
            int a = p.top();
            p.pop();
            int b = p.top();
            p.pop();
            if(a != b) p.push(abs(b-a));
        }
        return  p.empty() ?0:p.top();
    }
};