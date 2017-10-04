int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
double dp[101][26][26];
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        double ans = 0.0;
        memset(dp, 0, sizeof(dp));
        dp[0][r][c] = 1.0;
        for (int i = 1; i <= K; ++i)
            for (int x = 0; x < N; ++x)
                for (int y = 0; y < N; ++y)
                    for (int k = 0; k < 8; ++k) {
                        int tx = x + dx[k], ty = y + dy[k];
                        if (tx >= 0 && tx < N && ty >= 0 && ty < N) {
                            dp[i][tx][ty] += dp[i - 1][x][y] * 1.0 / 8;
                        }
                    }
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                ans += dp[K][i][j];
        return ans;
    }
};