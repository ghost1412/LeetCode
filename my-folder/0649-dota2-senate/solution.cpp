class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> q1, q2;
        for(int i=0; i<n; i++){
            if(senate[i] == 'R') q1.push(i);
            else q2.push(i);
        }
        while(!q1.empty() && !q2.empty()){
            if(q1.front() < q2.front()){
                q1.push(q1.front()+n);
                q1.pop();
                q2.pop();
            }else{
                q2.push(q2.front()+n);
                q1.pop();
                q2.pop();                
            }
        }
        return q1.empty() ? "Dire": "Radiant";
    }
};
