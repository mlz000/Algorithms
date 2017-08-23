class Solution {
public:
    int mySqrt(int x) {
        if (!x) return 0;
        double ans = x;
        for (int i = 1; i <= 50; ++i)   ans = (ans + x / ans) / 2;
        return ans;
    }
};