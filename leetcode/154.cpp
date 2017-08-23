class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size();
        int l = 0, r = n - 1, ans = a[0];
        while (l < r) {
            int m = l + r >> 1;
            if (a[m] < a[r])    r = m;
            else if (a[m] > a[r])   l = m + 1;
            else --r;
        }
        return a[l];
    }
};