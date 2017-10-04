typedef long long LL;
#define pb push_back
vector<LL> a;
class Solution {
public:
    string nearestPalindromic(string s) {
        int n = s.size();
        a.clear();
        LL x = stol(s);
        a.pb(pow(10, n) + 1), a.pb(pow(10, n - 1) - 1);
        string pre = s.substr(0, (n + 1) / 2);
        for (int i = -1; i <= 1; ++i) {
            string t = to_string(stol(pre) + i);
            string tt = t;
            reverse(tt.begin(), tt.end());
            string now = t + tt.substr((n & 1), t.size() - (n & 1));
            a.pb(stol(now));
        }
        LL dif = 1e18, ans = 1e18;
        for (auto& t : a) {
            if (t == x) continue;
            if (abs(t - x) < dif)   dif = abs(t - x), ans = t;
            else if (abs(t - x) == dif) ans = min(ans, t);
        }
        return to_string(ans);
    }
};