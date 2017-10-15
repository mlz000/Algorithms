const int N = 50000;
int sum[50005], cnt[N * 2 + 5];
class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        if (n == 1) return 0;
        memset(cnt, 0, sizeof(cnt));
        memset(sum, 0, sizeof(sum));
        char last = s[0];
        int cnt = 0, now = 1;
        for (int i = 1; i < n; ++i) {
            if (s[i] != last) {
                sum[cnt] = now;
                last = s[i];
                cnt++;
                now = 1;
            }
            else ++now;
        }
        sum[cnt++] = now;
        int ans = 0;
        for (int i = 0; i < cnt - 1; ++i)
            ans += min(sum[i], sum[i + 1]);
        return ans;
    }
};