class Solution {
public:

    int binarySearch(int s, int value, vector<int> & stones) {
        int r = stones.size()-1;
        int mid = 0;
        while (s <= r) {
            mid = s + (r-s)/2;
            if (stones[mid] == value) return mid;
            else if (stones[mid] > value) r = mid-1;
            else s = mid+1;
        }
        return -1;
    }


    bool canCross(vector<int>& stones) {
    //    vector<int> dp(stones.size(), 0);
        unordered_set<int> stoneSet(stones.begin(), stones.end());
        unordered_set<string> visited;
       // dp[0] = 1;
        int i = 0, j = 0;
        int k = 0;
        queue<pair<int, int>> q;
        q.push({0, 0});
        string state = "";
        while (!q.empty()) {
            auto top = q.front();
            j = top.first;
            k = top.second;
            q.pop();
            if (j==stones.back()) return true;
          //  if (dp[j]) continue;
           // k = stones[j]-stones[i];
            for (int jump: {k-1, k, k+1}) {
                if (jump <= 0) continue;
                int newPosi = j+jump;
                //binarySearch(j, stones[j]+jump, stones);
                         //       cout<<newPosi<<jump<<" ";
                state = to_string(newPosi)+"->"+ to_string(jump);
                if (stoneSet.count(newPosi) && !visited.count(state)) {
                    q.push({newPosi, jump});
                    visited.insert(state);
                }
            }
        }
        return false;
    }
};
