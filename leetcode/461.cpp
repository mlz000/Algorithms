class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        for (int i = 31; i >= 0; --i) 
            ans += ((x >> i & 1) ^ (y >> i & 1));
        return ans;
    }
};