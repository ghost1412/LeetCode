class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int numRooms = rooms.size();
        if (numRooms == 1) return true;
        vector<bool> visited(numRooms, false);
        visited[0] = true;
        stack<vector<int>> toVisit;
        toVisit.push(rooms[0]);
        int visitedAll = numRooms;
        while(!toVisit.empty()) {
            vector<int> room = toVisit.top();
            toVisit.pop();
            for (int i=0; i<room.size(); i++) {
                if (room[i] == 0 || visited[room[i]]) continue;
                toVisit.push(rooms[room[i]]);
                visited[room[i]] = true;
            }
        }
        for (int i=0; i<visited.size(); i++) {
            if (!visited[i]) return false;
        }
        return true;
    }
};
