class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, bool> G;
        while (!G[n]) {
            G[n] = true;
            if (n == 1) return true;
            int t = 0;
            while (n) t += (n % 10) * (n % 10), n /= 10;
            n = t;
        }
        return false;
    }
};