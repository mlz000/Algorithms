const int N = 1005;
vector<int> ans;
int l[N], r[N], h[N];
class Solution {
public:
    vector<int> fallingSquares(vector<pair<int, int>>& a) {
        int n = a.size();
        ans.clear();
        memset(l, 0x3f3f3f3f, sizeof(l));
        memset(r, -1, sizeof(r));
        memset(h, 0, sizeof(h));
        for (int i = 0; i < n; ++i) {
            int L = a[i].first, R = a[i].first + a[i].second - 1;
            for (int j = 0; j < i; ++j) {
                if ((l[j] <= L && L <= r[j]) || (l[j] <= R && R <= r[j]) || (L <= l[j] && R >= r[j])) {
                    h[i] = max(h[i], h[j] + a[i].second);
                }
            }
            if (!h[i]) h[i] = a[i].second;
            l[i] = L, r[i] = R;
            int now = 0;
            for (int j = 0; j <= i; ++j) now = max(now, h[j]);
            ans.push_back(now);
        }
        return ans;
    }
};