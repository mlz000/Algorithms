class Solution {
public:
    int calc(int x, int f) {
        int now = 0;
        int t = !f ? x / 10 : x;
        while (x) {
            t = t * 10 + x % 10;
            x /= 10;
        }
        return t;
    }
    bool isPrime(int x) {
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) return 0;
        }
        return x != 1;
    }
    int primePalindrome(int N) {
        for (int p = 10; ; p *= 10) {
            for (int i = 0; i < 2; ++i) {
                for (int x = p / 10; x < p; ++x) {
                    int y = calc(x, i);
                    if (y >= N && isPrime(y))   return y;
                }
            }
        }
    }
};
