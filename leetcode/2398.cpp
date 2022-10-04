const int N = 5e4 + 5;
class Solution {
public:
    long long sum[N];
    int p[21], mx[N][21];
    bool check(int x, int k, long long cost) {
        int t = log2(k);
        int y = x + k - (1 << t);
        return max(mx[x][t], mx[y][t]) + (sum[x + k] - sum[x]) * k <= cost;
    }
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        for (int i = 0; i < chargeTimes.size(); ++i) {
            mx[i][0] = chargeTimes[i];
        }
        p[0] = 1;
        for (int i = 1; i <= 20; ++i)   p[i] = p[i - 1] << 1;
        for (int i = 1; i <= 20; ++i)
            for (int j = 0; j + (1 << i) <= chargeTimes.size(); ++j) {
                mx[j][i] = max(mx[j][i - 1], mx[j + (1 << i - 1)][i - 1]); 
            }
        for (int i = 0; i < runningCosts.size(); ++i) {
            sum[i + 1] = sum[i] + runningCosts[i];
        }
        int ans = 0;
        for (int i = 0; i < chargeTimes.size(); ++i) {
            int l = 1, r = chargeTimes.size() - i;
            while (l <= r) {
                int mid = l + r >> 1;
                if (check(i, mid, budget)) {
                    ans = max(ans, mid);
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
        }
        return ans;
    }
};
