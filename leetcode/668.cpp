class Solution {
public:
    int findKthNumber(int n, int m, int k) {
        int l = 1, r = n * m, ans;
        while (l <= r) {
            int mid = l + r >> 1;
            int now = 0;
            for (int i = 1; i <= n; ++i)    now += min(mid / i, m);
            if (now >= k) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};