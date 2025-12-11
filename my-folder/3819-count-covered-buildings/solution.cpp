class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, array<int,2>> mpx, mpy;

        for (int i=0; i<buildings.size(); i++) {
            int x = buildings[i][0];
            int y = buildings[i][1];
            if (!mpx.count(x)) mpx[x] = {INT_MAX, INT_MIN};
            if (!mpy.count(y)) mpy[y] = {INT_MAX, INT_MIN};
            mpx[x][0] = min (mpx[x][0], y);
            mpx[x][1] = max (mpx[x][1], y);
            mpy[y][0] = min (mpy[y][0], x);
            mpy[y][1] = max (mpy[y][1], x);
        }

        int count=0;

        for (int i=0; i<buildings.size(); i++) {
            int x = buildings[i][0];
            int y = buildings[i][1];
            auto &xarray = mpx[x];
            auto &yarray = mpy[y];


            bool xcover = xarray[0] < y && xarray[1] > y;
            bool ycover = yarray[0] < x && yarray[1] > x;


            count += xcover && ycover;

        }
        return count;
    }
};
