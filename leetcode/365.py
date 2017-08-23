class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x == 0 && y == 0)   return z == 0;
        int c = __gcd(x, y);
        return (z % c) == 0 and z <= x + y;
    }
};