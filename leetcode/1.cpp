#define pb push_back
class Solution {
public:
    unordered_map<int, int> mp;
    vector<int> ans;
    vector<int> twoSum(vector<int>& a, int target) {
        int n = a.size();
        for (int i = 0; i < n; ++i)  mp[a[i]] = i;
        for (int i = 0; i < n; ++i) {
            int t = target - a[i];
            if (mp.count(t) && mp[t] != i) {
                ans.pb(i), ans.pb(mp[t]);
                break;
            }
        }
        return ans;
    }
};