#define pb push_back
class Solution {
public:
    set<string> tmp;
    vector<string> ans;
    void dfs(int p, int cnt, string now, string s, int l, int r) {
        if (p == s.size()) {
            if (l == 0 && r == 0 && cnt == 0) tmp.insert(now);
            return;
        }
        if (s[p] == '(') {
            if (l > 0) dfs(p + 1, cnt, now, s, l - 1, r);
            dfs(p + 1, cnt + 1, now + "(", s, l, r);
        }
        else if (s[p] == ')'){
            if (r > 0) dfs(p + 1, cnt, now, s, l, r - 1);
            if (cnt > 0) dfs(p + 1, cnt - 1, now + ")", s, l, r);
        }
        else {
            dfs(p + 1, cnt, now + s[p], s, l, r);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
         int n = s.size();
         tmp.clear(), ans.clear();
         int l = 0, r = 0;
         for (int i = 0; i < n; ++i) {
             if (s[i] == '(')   ++l;
             else if (s[i] == ')'){
                 if (l > 0) --l;
                 else ++r;
             }
         }
        dfs(0, 0, "", s, l, r);
        ans = vector<string>(tmp.begin(), tmp.end());
        return ans;
    }
};