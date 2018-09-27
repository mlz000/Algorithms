class Solution {
public:
    int minEatingSpeed(vector<int>& a, int H) {
        int n = a.size();
        int ans;
        int l = 1, r = 1e9;
        while (l <= r) {
            int mid = l + r >> 1;
            long long now = 0;
            for (auto x: a) {
                now += x / mid + (x % mid != 0);
            }
            if (now <= H) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};
