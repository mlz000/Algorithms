class Solution {
public:
    int getSum(int a, int b) {
        int x = a ^ b;
        int y = a & b;
        if (!b) return a;
        return getSum(x, y << 1);
    }
};