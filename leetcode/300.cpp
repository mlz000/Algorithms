#define pb push_back
class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || a[i] > ans.back()) ans.pb(a[i]);
            else    *lower_bound(ans.begin(), ans.end(), a[i]) = a[i];
        }
        return ans.size();
    }
};