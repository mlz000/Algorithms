#define F first
#define S second
#define mp make_pair
#define pb push_back
class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int ans = 0;
        unordered_set<int> s;
        for (auto x: obstacles)
            s.insert(x[0] * 100000 + x[1]);
        int x = 0, y = 0, dir = 0;
        for (auto op: commands) {
            if (op == -2)   dir = (dir + 3) % 4;
            else if (op == -1)  dir = (dir + 1) % 4;
            else {
                int nx = x, ny = y;
                for (int i = 0; i < op; ++i) {
                    nx += dx[dir];
                    ny += dy[dir];
                    if (s.count(nx * 100000 + ny)){
                        nx -= dx[dir];
                        ny -= dy[dir];
                        break;
                    }
                }
                x = nx, y = ny;
                ans = max(ans, x * x + y * y);
            }
        }
        return ans;
    }
};
