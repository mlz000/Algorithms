const int N = 1005, mod = 1e9 + 7;
int c[N][N];
class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        int l = min(startPos, endPos);
        int r = max(startPos, endPos);
        if ((r - l) % 2 != k % 2 || r - l > k) {
            return 0;
        }
        for (int i = 0; i <= k; ++i) {
            c[i][0] = c[i][i] = 1;
        }
        for (int i = 1; i <= k; ++i)
            for (int j = 1; j < i; ++j) {
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
            }
        int ans = 0;
        return c[k][(k - (r - l)) / 2];
    }
};
