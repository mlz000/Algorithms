class Solution {
public:
    static const int N = 205;
    int n, m, f[N * N], sz[N * N];
    vector<int> ans;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int find(int x) {
        return f[x] == x ? x : find(f[x]);
    }
    
    inline int get(int x, int y) {
        return x * m + y;    
    }
    
    bool in(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;    
    }
    
    void merge(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx != fy)   f[fx] = fy, sz[fy] += sz[fx];
    }
    
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        ans.clear();
        for (auto row : hits)
            grid[row[0]][row[1]] ^= 2;
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                f[get(i, j)] = get(i, j);
                sz[get(i, j)] = 1;
            }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) 
                if (grid[i][j] == 1) {
                    if (i == 0) merge(n * m, get(i, j));
                    for (int d = 0; d < 4; ++d) {
                        int x = i + dx[d];
                        int y = j + dy[d];
                        if (in(x, y) && grid[x][y] == 1)    merge(get(i, j), get(x, y));
                    }
                }
        for (int i = hits.size() - 1; i >= 0; --i) {
            int prev = sz[find(n * m)];
            int x = hits[i][0], y = hits[i][1];
            if (grid[x][y] != 3)    ans.push_back(0);
            else {
                if (x == 0) merge(n * m, get(x, y));
                for (int d = 0; d < 4; ++d) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (in(nx, ny) && grid[nx][ny] == 1)   merge(get(x, y), get(nx, ny));
                }
                grid[x][y] = 1;
                int now = sz[find(n * m)];
                ans.push_back(max(0, now - prev - 1));
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};