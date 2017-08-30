#define pb push_back
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        for (int i = n; i >= k + 1; --i)    ans.pb(i);
        int cur = k + 1;
        for (int i = k, now = -1; i >= 1; --i, now *= -1) {
            cur += now * i;
            ans.pb(cur);
        }
        return ans;
    }
};