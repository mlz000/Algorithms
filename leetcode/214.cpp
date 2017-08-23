const int N = 1e5 + 5;
class Solution {
public:
	int nxt[N];
    string shortestPalindrome(string s) {
        string ss = s;
        reverse(ss.begin(), ss.end());
		string t = s + "?" + ss;
		int n = t.size();
		int i = 0, j = -1;
		nxt[0] = -1;
		while (i < n) {
			if (j == -1 || t[j] == t[i])	nxt[++i] = ++j;
			else j = nxt[j];
		}
		return ss.substr(0, s.size() - nxt[n - 1] - 1) + s;
    }
};