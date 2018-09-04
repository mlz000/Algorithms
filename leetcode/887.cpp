class Solution {
public:
    int f[10001][101];
    int superEggDrop(int K, int N) {
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= K; ++j) {
                f[i][j] = f[i - 1][j - 1] + f[i - 1][j] + 1;
            }
        for (int i = 1; i <= N; ++i)
            if (f[i][K] >= N)   return i;
    }
};
