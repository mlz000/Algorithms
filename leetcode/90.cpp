#define pb push_back
vector<vector<int> > ans;
vector<int> now;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& a) {
        ans.clear();
        ans.pb(vector<int>());
        sort(a.begin(), a.end());
        int n = a.size(), sz = 0;
        for (int i = 0; i < n; ++i) {
            int id = (i == 0 || a[i] != a[i - 1]) ? 0 : sz;
            sz = ans.size();
            for (int j = id; j < sz; ++j) {
                now = ans[j];
                now.pb(a[i]);
                ans.pb(now);
            }
        }
        return ans;
    }
};