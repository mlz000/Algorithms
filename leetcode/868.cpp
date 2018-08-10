class Solution {
public:
    int binaryGap(int N) {
        int ans = 0;
        int last = -1;
        for (int i = 0; i < 32; ++i) {
            int x = (N  >> i) & 1;
            if (x) {
                if (last != -1) {
                    ans = max(ans, i - last);
                }
                last = i;
            }
        }
        return ans;
    }
};
