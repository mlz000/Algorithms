class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int dis[31][31][1 << 6];
    struct data{ 
        int x, y, mask;
        data(int x, int y, int mask) : x(x), y(y), mask(mask) {}
    };
    int shortestPathAllKeys(vector<string>& grid) {
        queue<data> q;
        int n = grid.size(), m = grid[0].size(), x, y;
        memset(dis, 0, sizeof(dis));
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '@')
                    x = i, y = j;
                if (grid[i][j] >= 'a' && grid[i][j] <= 'f') ++cnt;
            }
        q.push(data(x, y, 0));
        while (q.size()) {
            data now = q.front();
            q.pop();
            int nx = now.x, ny = now.y, nmask = now.mask;
            for (int i = 0; i < 4; ++i) {
                int xx = nx + dx[i];
                int yy = ny + dy[i];
                if (xx >= 0 && xx < n && yy >= 0 && yy < m && grid[xx][yy] != '#') {
                    if ((grid[xx][yy] >= 'A' && grid[xx][yy] <= 'F' && (nmask >> (grid[xx][yy] - 'A') & 1)) || grid[xx][yy] == '.' || grid[xx][yy] == '@')  {
                        if (!dis[xx][yy][nmask]) {
                            dis[xx][yy][nmask] = dis[nx][ny][nmask] + 1;
                            q.push(data(xx, yy, nmask));
                        }
                    }
                    else if (grid[xx][yy] >= 'a' && grid[xx][yy] <= 'f') {
                        int nemask = nmask | (1 << (grid[xx][yy] - 'a'));
                        if (!dis[xx][yy][nemask]) {
                            dis[xx][yy][nemask] = dis[nx][ny][nmask] + 1;
                            if (nemask == (1 << cnt) - 1)  return dis[xx][yy][nemask];
                            q.push(data(xx, yy, nemask));
                        }
                    }
                }
            }
        }
        return -1;
    }
};
