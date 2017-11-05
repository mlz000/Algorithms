#define pb push_back
vector<vector<int> > ans;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& a) {
        int n = a.size();
        ans.clear();
        for (int i = 0; i < 1 << n; ++i) {
            vector<int> now;
            for (int j = 0; j < n; ++j)
                if (i >> j & 1) now.pb(a[j]);
            ans.pb(now);
        }
        return ans;
    }
};