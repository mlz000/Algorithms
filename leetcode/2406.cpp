const int N = 1e6 + 5;
class Solution {
public:
    int sum[N];
    int minGroups(vector<vector<int>>& intervals) {
        for (auto interval : intervals) {
            ++sum[interval[0]];    
            --sum[interval[1] + 1];
        }
        int ans = 0, now = 0;
        for (int i = 1; i <= 1e6; ++i) {
            now += sum[i];
            ans = max(ans, now);
        }
        return ans;
    }
};
