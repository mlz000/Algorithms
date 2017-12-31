class Solution {
public:
    int g[7][7][7];
    bool pyramidTransition(string s, vector<string>& allowed) {
        int n = s.size();
        vector<int> a(n, 0), b(n, 0);
        for (int i = 0; i < n; ++i) a[i] = 1 << (s[i] - 'A');
        for (auto t : allowed) g[t[0] - 'A'][t[1] - 'A'][t[2] - 'A'] = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) 
                if (!a[j])  return 0;
            for (int j = 0; j < i; ++j) {
                b[j] = 0;
                for (int x = 0; x < 7; ++x) {
                    if (!(a[j] >> x & 1))   continue;
                    for (int y = 0; y < 7; ++y) {
                        if (!(a[j + 1] >> y & 1))   continue;
                        for (int z = 0; z < 7; ++z)
                            if (g[x][y][z]) b[j] |= 1 << z;
                    }
                }
            }
            swap(a, b);
        }   
        return 1;
    }
};