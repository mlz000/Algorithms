class Solution {
public:
    string dfs(string s, int &p) {
        string now = "";
        while (p < s.size() && s[p] != ']') {
            if (isdigit(s[p])) {
                int cnt = 0;
                while (p < s.size() && isdigit(s[p]))  {
                    cnt = cnt * 10 + s[p++] - '0';
                }
                ++p;
                string t = dfs(s, p);
                ++p;
                while (cnt--)   now += t;
            }
            else now += s[p++];
        }
        return now;
    }
    string decodeString(string s) {
        int i = 0;
        return dfs(s, i);
    }
};