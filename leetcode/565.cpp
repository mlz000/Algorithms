const int N = 20005;
class Solution {
public:
    bool vis[N];
    int arrayNesting(vector<int>& a) {
        int n = a.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                int now = 1, t = i;
                while (a[t] != i) {
                    vis[t] = 1;
                    ++now;
                    t = a[t];
                }
                ans = max(ans, now);
            }
        }
        return ans;
    }
};