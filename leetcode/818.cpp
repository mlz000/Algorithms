#define F first
#define S second
typedef pair<int, int> pii;
class Solution {
public:
    int dp[40005][42], p[21];
    int racecar(int target) {
        memset(dp, 0, sizeof(dp));
        p[1] = 1;
        for (int i = 2; i <= 20; ++i)  p[i] = p[i - 1] << 1;
        queue<pii> q;
        q.push(make_pair(0, 1));
        while (q.size()) {
            pii now = q.front();
            q.pop();
            int x = now.F + p[abs(now.S)] * (now.S > 0 ? 1 : -1), s = now.S + (now.S > 0 ? 1 : -1);
            if (!(x >= -20000 && x <= 20000))   continue;
            if (!dp[x + 20000][s + 20]) {
                dp[x + 20000][s + 20] = dp[now.F + 20000][now.S + 20] + 1;
                if (x == target)    return dp[x + 20000][s + 20];
                q.push(make_pair(x, s));
            }
            x = now.F, s = now.S > 0 ? -1 : 1;
            if(!dp[x + 20000][s + 20]) {
                dp[x + 20000][s + 20] = dp[now.F + 20000][now.S + 20] + 1;
                if (x == target)    return dp[x + 20000][s + 20];
                q.push(make_pair(x, s));  
            }
        }
    }
};