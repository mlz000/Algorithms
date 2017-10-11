class Solution {
public:
    bool hasAlternatingBits(int n) {
        int last = n & 1;
        for (int i = 1; i <= 31; ++i)
            if ((1ll << i) <= n) {
                if (last == (n >> i & 1))   return false;
                last = (n >> i & 1);
            }
        return true;
    }
};