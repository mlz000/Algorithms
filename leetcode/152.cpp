typedef long long LL;
const int N = 1e5;
class Solution {
public:
    LL f[N][2];
    vector<LL> a;
    int maxProduct(vector<int>& b) {
        for (auto t : b)    a.push_back(t);
        int n = a.size();
        LL ans = f[0][0] = f[0][1] = a[0];
        for (int i = 1; i < n; ++i) {
            f[i][0] = min(a[i], min(f[i - 1][0] * a[i], f[i - 1][1] * a[i]));
            f[i][1] = max(a[i], max(f[i - 1][0] * a[i], f[i - 1][1] * a[i]));
            ans = max(ans, f[i][1]);
        }
        return ans;
    }
};
