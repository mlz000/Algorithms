#define pb push_back
class Solution {
public:
    int compress(vector<char>& s) {
        int n = s.size();
        int ans = 0, now = 0;
        char last = s[0];
        vector<char> s2;
        for (int i = 0; i < n; ++i) {   
            if (s[i] != last) {
                s2.pb(last);
                ++ans;
                if (now != 1) {
                    vector<char> tmp;
                    int t = now;
                    while (t)   ++ans, tmp.pb(t % 10 + '0'), t /= 10;
                    for (int j = tmp.size() - 1; j >= 0; --j)   s2.pb(tmp[j]);
                    
                }
                last = s[i];
                now = 1;
            }
            else {
                ++now;
            }
        }
        s2.pb(last);
        ++ans;
        if (now != 1) {
                    vector<char> tmp;
                    int t = now;
                    while (t)   ++ans, tmp.pb(t % 10 + '0'), t /= 10;
                    for (int j = tmp.size() - 1; j >= 0; --j)   s2.pb(tmp[j]);
        }
        s = s2;
        return ans;
    }
};