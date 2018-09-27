class Solution {
public:
    int p[32], sum[10];
    bool reorderedPowerOf2(int N) {
        p[0] = 1;
        for (int i = 1; i <= 30; ++i)   p[i] = p[i - 1] << 1;
        while (N) {
            ++sum[N % 10];
            N /= 10;
        }
        for (int i = 0; i <= 30; ++i) {
            int cnt[10];
            memset(cnt, 0, sizeof(cnt));
            int x = p[i];
            while (x) {
                ++cnt[x % 10];
                x /= 10;
            }
            bool ok = 1;
            for (int j = 0; j < 10; ++j)
                ok &= (cnt[j] == sum[j]);
            if (ok) return true;
        }
        return false;
    }
};
