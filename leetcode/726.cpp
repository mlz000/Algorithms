class Solution {
public:
    map<string, int> G;
    map<string, int> dfs(string s, int &i) {
        string now = "";
        int cnt = 0;
        map<string, int> ans, tmp;
        for (;i < s.size(); ++i) {
            if((s[i] >= 'a' && s[i] <= 'z')) {
                now += s[i];
            }
            else if (isdigit(s[i])) {
                cnt = cnt * 10 + s[i] - '0';
            }
            else {
                if (now.size()) {
                    cnt = max(1, cnt);
                    ans[now] += cnt;
                    now = ""; 
                    cnt = 0;
                }
                else{
                    for (auto& it : tmp)    ans[it.first] += it.second * cnt;
                    cnt = 0;
                }
                if (s[i] == '(')    tmp = dfs(s, ++i);
                else if (s[i] == ')')    return ans;
                else if (s[i] != '?')    now += s[i];
            }
        }
        return ans;
    }
    string countOfAtoms(string s) {
        int i = 0;
        s += '?';
        map<string, int> ans = dfs(s, i);
        string res = "";
        for (auto& it : ans) {
            res += it.first;
            if (it.second != 1) res += to_string(it.second);
        }
        return res;
        
    }
};