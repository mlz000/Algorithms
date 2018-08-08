const int M = 1e9 + 7;
typedef long long LL;
class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        int gcd = __gcd(A, B);
        int lcm = A / gcd * B;
        int ans = -1;
        int l = 1, r = 1e9;
        while (l <= r) {
            int mid = (l + r) >> 1;
            long long t = mid + (LL)mid * A / B - (LL)mid * A / lcm;
            if (t == N) {
                ans = (LL)mid * A % M;
                return ans;
            }
            if (t < N) {
                l = mid + 1;
            }
            else r = mid - 1;
        }
        l = 1, r = 1e9;
        while (l <= r) {
            int mid = (l + r) >> 1;
            long long t = mid + (LL)mid * B / A - (LL)mid * B / lcm;
            if (t == N) {
                ans = (LL)mid * B % M;
                return ans;
            }
            if (t < N) {
                l = mid + 1;
            }
            else r = mid - 1;
        }
    }
};
