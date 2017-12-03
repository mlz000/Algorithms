class Solution {
public:
    int search(vector<int>& a, int target) {
        int n = a.size();
        int ans = -1, l = 0, r = n - 1;
        while (l <= r) {
            int m = l + r >> 1;
            if (a[m] == target) return m;
            if (a[m] > target) {
                if (a[0] <= target || a[0] > a[m])    r = m - 1;
                else l = m + 1;
            }
            else {
                if (a[0] <= a[m] || (a[0] > target))    l = m + 1;
                else r = m - 1;
            }
        }
        return -1;
    }
};