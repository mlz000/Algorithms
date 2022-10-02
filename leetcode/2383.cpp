class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int sum1 = 0, ans2 = 0;
        for (auto x : energy) {
            sum1 += x;
        }
        int last = initialExperience;
        for (auto x : experience) {
            if (last > x) {
                last += x;
                continue;
            }
            else {
                ans2 += x - last + 1;
                last = x * 2 + 1;
            }
        } 
        return std::max(0, sum1 - initialEnergy + 1) + ans2;
    }
};
