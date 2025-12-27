class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        unordered_map<int, long long> usedCount;
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> endingTime;
        priority_queue<long long, vector<long long>, greater<long long>> roomAvailable;

        for (int i=0; i<n; i++) roomAvailable.push(i);

        for (int i=0; i<meetings.size(); i++) {

            while (!endingTime.empty() && meetings[i][0] >= endingTime.top().first) {
                roomAvailable.push(endingTime.top().second);
                endingTime.pop();
            }

            if (!roomAvailable.empty()) {
                int room = roomAvailable.top();
                endingTime.push({meetings[i][1], room});
                usedCount[room]++;
                roomAvailable.pop();
            } else {
                auto top = endingTime.top();
                endingTime.pop();
                long long extraDuration = meetings[i][1]+ top.first-meetings[i][0];
                endingTime.push({extraDuration, top.second});
                usedCount[top.second]++;
            }
        }

        int bestRoom = 0;
        long long bestCount = 0;

        for (int i = 0; i < n; i++) {
            long long cnt = usedCount[i];
            if (cnt > bestCount) {
                bestCount = cnt;
                bestRoom = i;
            }
        }

        return bestRoom;
    }
};
