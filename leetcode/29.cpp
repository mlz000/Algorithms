typedef long long LL;
class Solution {
public:
    int divide(int xx, int yy) {
        LL x = abs((LL)xx), y = abs((LL)yy);
        int sgn = (LL)xx * yy > 0 ? 1 : -1;
        LL ans = 0;
        cout << x << "XXXX" << y << endl;
        for (LL i = 31; i >= 0; --i)
            if ((y << i) <= x) {
                ans += 1ll << i;
                x -= y << i;
            }
       // cout << ans << endl;
        return min((LL)INT_MAX, ans * sgn);
    }
};