class Solution {
public: 
    int n;
    vector<int> b, c, ans;
    void add(int x) {
        while (x <= n) {
            ++c[x];
            x += x & -x;
        }
    }
    int ask(int x) {
        int t = 0;
        while (x) {
            t += c[x];
            x -= x & -x;
        }
        return t;
    }
    vector<int> countSmaller(vector<int> a) {
        n = a.size();
        b = a;
        sort(b.begin(), b.end());
        c.resize(n + 1);
        for (int i = 0; i < n; ++i) a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
        for (int i = n - 1; i >= 0; --i) {
            ans.push_back(ask(a[i] - 1));
            add(a[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};