class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), [](const vector<int> &p, const vector<int> &q){return p[1] < q[1];});
        set<int> ans;
        for (int i = 0; i < a.size(); ++i) {
            auto it1 = ans.lower_bound(a[i][0]);
            auto it2 = ans.upper_bound(a[i][1]);
            int cnt = 0;
            for (; it1 != it2; ++it1)
                if ((*it1) >= a[i][0] && (*it1) <= a[i][1]) ++cnt;
            int now = a[i][1];
            while (cnt < 2) {
                if (ans.find(now) == ans.end()) ans.insert(now), ++cnt;
                --now;
            }
        }
        return ans.size();
    }
};