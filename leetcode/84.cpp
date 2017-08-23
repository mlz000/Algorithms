#define mp make_pair
#define F first
#define S second
typedef pair<int, int> pii;
class Solution {
public:
    stack<pii> S;
    int largestRectangleArea(vector<int>& h) {
        h.push_back(0);
        int n = h.size();
        S.push(mp(0, -1));
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            pii now = mp(i, h[i]);
            while (S.top().S > h[i]) {
                now = S.top();
                S.pop();
                ans = max(ans, now.S * (i - now.F));
            }
            S.push(mp(now.F, h[i]));
        }
        return ans;
    }
};