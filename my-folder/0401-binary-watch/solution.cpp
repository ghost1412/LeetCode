class Solution {
public:

    unsigned int countSetBits(int n) {
        return __builtin_popcount(n);
        unsigned int count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> times;

        for (int hour=0; hour<12; hour++) {
            for (int min=0; min<60; min++) {
                string time = "";
                int hrSetBits = countSetBits(hour);
                int minSetBits = countSetBits(min);

                if (hrSetBits + minSetBits == turnedOn) {
                    time += to_string(hour) + ":";

                    if (min < 10) {
                        time += "0";
                    }
                    time += to_string(min);
                    times.push_back(time);
                }
            }
        }

        return times;
    }
};
