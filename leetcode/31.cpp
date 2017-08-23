class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n = a.size(), i;
        for (i = n - 2; i >= 0; --i) {
            if (a[i] < a[i + 1]) {
                int j;
                for (j = n - 1; j > i; --j)
                    if (a[j] > a[i])    break;
                swap(a[i], a[j]);
                printf("%d %d\n", a[i], a[j]);
                break;
            }
        }
        reverse(a.begin() + i + 1, a.end());
    }
};