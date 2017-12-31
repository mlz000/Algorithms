class Solution {
public:
    int reachNumber(int target) {
        int sum = 0, ans = 0;
        target = abs(target);
        for (int i = 1; ; ++i) {
            ++ans;
            sum += i;
            if (sum >= target) {
                if ((sum - target) % 2 == 0)    break;
                else {
                    ans += (i & 1) ? 2 : 1;
                    break;
                }
            }
        }
        return ans;
    }
};