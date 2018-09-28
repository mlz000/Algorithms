class Solution {
public:
    vector<pair<int, char>> a;
    int cnt[26], pos[26];
    string rearrangeString(string s, int k) {
        if (k == 0) return s;
        for (auto c: s) ++cnt[c - 'a'];
        for (int i = 0; i < 26; ++i)    pos[i] = -k;
        string ans = "";
        for (int i = 0; i < s.size(); ++i) {
           int mxc = 0, mxp;
           for (int j = 0; j < 26; ++j) 
               if (cnt[j] > mxc && pos[j] <= i - k) {
                   mxc = cnt[j];
                   mxp = j;
               }
            if (mxc == 0)   return "";
            ans += 'a' + mxp;
            --cnt[mxp];
            pos[mxp] = i;
        }
        return ans;
    }
};