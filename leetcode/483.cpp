typedef long long LL;
class Solution {
public:
    LL gao(int L, LL n) {
        LL l = 1, r = (LL)pow(n, 1.0 / L) + 1;
        while (l <= r) {
            LL mid = l + (r - l) / 2;
            LL now = 0, x = 1;
            for (int i = 0; i <= L; ++i, x *= mid)  now += x;
            if (now == n)   {
                cout << mid << endl;
                return mid;
            }
            if (now < n)    l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
    string smallestGoodBase(string N) {
        LL n = (LL)stoll(N);
        for (int i = 63; i >= 1; --i) {
            if ((1ll << i) < n) {
                LL t = gao(i, n);
                if (~t) return to_string(t);
            }
        }
        return to_string(n - 1);
    }
};