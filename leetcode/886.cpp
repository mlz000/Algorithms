class Solution {
public:
    int f[4005];
    int find(int x) {
        return f[x] == x ? x : find(f[x]);
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        for (int i = 1; i <= N * 2; ++i)    f[i] = i;
        for (auto e: dislikes) {
            int x1 = e[0], y1 = e[1];
            int x2 = x1 + N, y2 = y1 + N;
            if (find(x1) == find(y1))   return 0;
            if (find(x2) == find(y2))   return 0;
            f[find(x1)] = f[find(y2)];
            f[find(y1)] = f[find(x2)];
        }
        return 1;
    }
};
