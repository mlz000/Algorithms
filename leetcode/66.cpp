class Solution {
public:
    vector<int> plusOne(vector<int>& a) {
        int c = 1;
        for (int i = a.size() - 1; i >= 0 && c; --i) {
            c = ((++a[i]) %= 10) == 0;
        }
        if (c)  a.insert(a.begin(), 1);
        return a;
    }
};