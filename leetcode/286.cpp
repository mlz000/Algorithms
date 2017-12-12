#define F first
#define S second
#define mp make_pair
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& a) {
        int n = a.size();
        if (n == 0) return;
        int m = a[0].size();
        queue<pair<int, int> > Q;
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 0)   Q.push(mp(i, j));   
            }
        while (Q.size()) {
            pair<int, int> t = Q.front();
            Q.pop();
            for (int i = 0; i < 4; ++i) {
                int tx = t.F + dx[i], ty = t.S + dy[i];

                if (tx >= 0 && tx < n && ty >= 0 && ty < m && (long long)a[tx][ty] > (long long)a[t.F][t.S] + 1) {
                    a[tx][ty] = a[t.F][t.S] + 1;
                    Q.push(mp(tx, ty));
                }
            }
        }
    }
};