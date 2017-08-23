#define pb push_back
class Solution {
public:
    string multiply(string s1, string s2) {
        vector<int> a, b, c;
        reverse(s1.begin(), s1.end()), reverse(s2.begin(), s2.end());
        for (auto s : s1)   a.pb(s - '0');
        for (auto s : s2)   b.pb(s - '0');
        int l1 = s1.size(), l2 = s2.size();
        c.resize(l1 + l2 + 1);
        for (int i = 0; i < l1; ++i)
            for (int j = 0, k = i + j; j < l2; ++j, ++k) {
                int now = c[k] + a[i] * b[j];
                c[k] = now % 10;
                c[k + 1] += now / 10;
            }
        string ans = "";
        bool ok = 0;
        for (int i = l1 + l2 - 1; i >= 1; --i) {
            if (c[i] != 0) ok = 1;
            else if (!ok)   continue;
            ans += c[i] + '0';
        }
        ans += c[0] + '0';
        return ans;
    }
};