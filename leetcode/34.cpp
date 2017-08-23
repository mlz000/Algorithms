#define pb push_back
class Solution {
public:
    vector<int> ans;
    vector<int> searchRange(vector<int>& a, int target) {
        auto l = lower_bound(a.begin(), a.end(), target);
        if (l == a.end() || *l != target) {
            ans.pb(-1), ans.pb(-1);
            return ans;
        }
        auto r = upper_bound(a.begin(), a.end(), target);
        ans.pb(l - a.begin()), ans.pb(r - a.begin() - 1);
        return ans;
    }
};