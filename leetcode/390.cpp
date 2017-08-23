class Solution {
public:
    int gao(int n, int left) {
        if (n <= 2) return left ? n : 1;
        else return 2 * gao(n / 2, !left) - ((n & 1) == 0 && !left);
    }
    int lastRemaining(int n) {
        return gao(n, 1);
    }
};