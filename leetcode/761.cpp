class Solution {
public:
    bool ok(string s) {
        int cnt = 0;
        for (auto c : s) {
            if (c == '1')   ++cnt;
            else {
                --cnt;
                if (cnt < 0)    return 0;
            }
        }
        return cnt == 0;
    }
    string makeLargestSpecial(string S) {
        int n = S.size();
        for (int i = n - 2; i >= 0; --i) {
            string now = S;
            for (int j = i + 1; j < n; ++j)
                for (int k = j + 1; k <= n; ++k) {
                    string a = S.substr(i, j - i), b = S.substr(j, k - j);
                    if (ok(a) && ok(b)) {
                        string x = a + b, y = b + a;
                        if (y > x) {
                            if (S.substr(0, i) + y + S.substr(k) > now) now = S.substr(0, i) + y + S.substr(k), cout << now << endl;
                        }
                    }
                }
            S = now;
        }
        return S;
    }
};