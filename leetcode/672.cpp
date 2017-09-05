class Solution {
public:
    int flipLights(int n, int m) {
        if (!n || !m)   return 1;
        if (n == 1) return 2;
        if (n == 2) {
            if (m == 1) return 3;
            return 4;
        }
        if (m == 1) return 4;
        return m == 2 ? 7 : 8;
    }
};