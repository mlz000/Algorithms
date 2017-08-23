#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef pair<int, int> pii;
class Solution {
public:
    vector<pii> g, ans;
    vector<pair<int, int>> getSkyline(vector<vector<int>>& a) {
        for (auto x : a)    g.pb(mp(x[0], -x[2])), g.pb(mp(x[1], x[2]));
        sort(g.begin(), g.end());
        multiset<int> St;
        int last = 0;
        St.insert(0);
        for (auto x : g) {
            if (x.S < 0)    St.insert(-x.S);
            else St.erase(St.find(x.S));
            int now = *St.rbegin();
            if (now != last) {
                ans.pb(mp(x.F, now));
                last = now;
            }
        }
        return ans;
    }
};