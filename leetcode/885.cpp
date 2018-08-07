class Solution {
public:
    int numRescueBoats(vector<int>& a, int limit) {
        int ans = 0;
        sort(a.begin(), a.end());
        int l = 0, r = a.size() - 1;
        while (l <= r) {
            if (l == r) {
                ++ans;
                ++l;
            }
            else if (a[l] + a[r] <= limit) {
                ++l, --r;
                ++ans;
            }
            else {
                --r;
                ++ans;
            }
        }
        return ans;
    }
};
