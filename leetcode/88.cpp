class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        int i = m - 1, j = n - 1, now = m + n - 1;
        while (j >= 0) {
            a[now--] = (i >= 0 && a[i] > b[j]) ? a[i--] : b[j--];
        }
    }
};