const int N = 50005;
long long p[N];
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& a, int k) {
        int n = a.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int l = 0, r = i, pos = -1;
            while (l <= r) {
                int m = (l + r) >> 1;
                long long x = 1;
                for (int j = m; j <= i; ++j) {
                    x *= a[j];
                    if (x > k) {
                        l = m + 1;
                        break;
                    }
                }
                if (x < k) {
                    pos = m;
                    r = m - 1;
                }
                else l = m + 1;
                
            }
            if (~pos) {
                ans += i - pos + 1;
            }
        }
        return ans;
    }
};