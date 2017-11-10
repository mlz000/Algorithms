// Forward declaration of the knows API.
bool knows(int a, int b);

#define pb push_back
class Solution {
public:
    int findCelebrity(int n) {
        vector<vector<bool> > g(n, vector<bool>());
        vector<int> now;
        for (int i = 0; i < n; ++i) now.pb(i);
        while (now.size() >= 2) {
            vector<int> t;
            for (int i = 0; i < now.size() - 1; i += 2) {
                if (knows(now[i], now[i + 1]))    g[now[i]][now[i + 1]] = 1, t.pb(now[i + 1]);
                else t.pb(now[i]);
            }
            if (now.size() & 1) t.pb(now[now.size() - 1]);
            now = t;
        }
        for (int i = 0; i < n; ++i) {
            if (i == now[0])    continue;
            if (!g[i][now[0]] && !knows(i, now[0])) return -1;
            if (knows(now[0], i))   return -1;
        }
        return now[0];
    }
};