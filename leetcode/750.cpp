#define pb push_back
#define mp make_pair
#define F first
#define S second
class Solution {
public:
    vector<pair<int, int> > G;
    int countCornerRectangles(vector<vector<int>>& a) {
        int n = a.size();
        if (n == 0) return 0;
        int m = a[0].size();
        if (n <= 1 || m <= 1)   return 0;
        int ans = 0;
        G.clear();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
               if (a[i][j] == 1)    G.pb(mp(i, j));
            }
        for (int i = 0; i < G.size(); ++i)
            for (int j = i + 1; j < G.size(); ++j) {
                int x1 = G[i].F, y1 = G[i].S, x2 = G[j].F, y2 = G[j].S;
                if (x1 == x2 || y1 == y2)   continue;
                if (a[x1][y1] + a[x2][y2] + a[x1][y2] + a[x2][y1] == 4) ++ans;
            }
        return ans / 2;
    }
};