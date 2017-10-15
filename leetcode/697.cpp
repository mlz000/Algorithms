class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int> cnt, l, r;
        l.clear(), r.clear(), cnt.clear();
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i];
            cnt[x] += 1;
            if (l.count(x) == 0)  l[x] = i;
            else l[x] = min(l[x], i);
            if (r.count(x) == 0)  r[x] = i;
            else r[x] = max(r[x], i);
            ans = max(ans, cnt[x]);
        }
        int res = 10000000;
        for (auto& x : cnt) {
            if (x.second == ans) {
                res = min(res, (r[x.first] - l[x.first] + 1));
            }
        }
        return res;
    }
};