int c[32];
class Solution {
public:
    bool check(int p, vector<int>& a) {
        for (int i = 0; i <= 31; ++i) {
            if ((a[p] >> i & 1) && c[i]) {
                return false;
            }
        }
        return true;
    }
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 1;
        int l = 0, r = -1;
        while (l < nums.size()) {
            while (r + 1 < nums.size() && check(r + 1, nums)) {
                for (int i = 0; i <= 31; ++i) {
                    if (nums[r + 1] >> i & 1) {
                        c[i] = 1;
                    }
                }
                ++r;
                ans = max(ans, r - l + 1);
            }
            for (int i = 0; i <= 31; ++i) {
                if (nums[l] >> i & 1) {
                    c[i] = 0;
                }
            }
            ++l;
        }
        return ans;
    }
};
