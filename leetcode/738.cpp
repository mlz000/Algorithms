#define pb push_back
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        if (n == 0) return 0;
        vector<int> a;
        int t = n;
        while (n) {
            a.pb(n % 10);
            n /= 10;
        }
        reverse(a.begin(), a.end());
        int p = -1;
        for (int i = 1; i < a.size(); ++i)
            if (a[i] < a[i - 1]) {
                p = i - 1;
                break;
            }
        int ans = 0;
        if (p == -1) return t;
        else {
            while (a[p] - 1 < a[p - 1] && p >= 1)  --p;
            for (int i = 0; i < p; ++i) ans = ans * 10 + a[i];
            ans = ans * 10 + a[p] - 1;
            for (int i = p + 1; i < a.size(); ++i)  ans = ans * 10 + 9;
            return ans;
        }
    }
};