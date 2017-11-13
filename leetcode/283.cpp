class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int n = a.size();
        int last = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i]) {
                swap(a[i], a[last++]);
            }
        }
    }
};