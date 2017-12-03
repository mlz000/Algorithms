class Solution {
public:
    string multiply(string a, string b) {
        vector<int> c(a.size() + b.size() + 2, 0);
        reverse(a.begin(), a.end()), reverse(b.begin(), b.end());
        for (int i = 0; i < a.size(); ++i)
            for (int j = 0; j < b.size(); ++j) {
                c[i + j] += (a[i] - '0') * (b[j] - '0');
                c[i + j + 1] += c[i + j] / 10;
                c[i + j] %= 10;
            }
        int p = a.size() + b.size() - 1;
        while (c[p] == 0 && p >= 1) --p;
        c.resize(p + 1);
        reverse(c.begin(), c.end());
        string ans = "";
        for (auto& x : c)   ans += to_string(x);
        return ans;
    }
};