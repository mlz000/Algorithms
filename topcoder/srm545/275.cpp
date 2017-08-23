#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
const int M = 26;
string ans;
struct StrIIRec {
	string dfs(int n, int minInv, string minStr, set<char> S) {
		if (minInv > (n - 1) * n / 2)	return "";
		if (n == 1)	return string(1, *S.begin());
		int cnt = 0;
		if (!minStr.size())	minStr = "a";
		for (set<char>:: iterator it = S.begin(); it != S.end(); it++) {
			if (*it >= minStr[0]) {
				set<char> f = S;
				f.erase(*it);
				string t;
				if (*it == minStr[0])	t = dfs(n - 1, minInv - cnt, string(minStr, 1), f);
				else t = dfs(n - 1, minInv - cnt, "", f);
				if (t.size())	return *it + t;
			}
			++cnt;
		}
		return "";
	}
    string recovstr(int n, int minInv, string minStr) {
  		set<char> S;
		for (int i = 0; i < 26; ++i)	S.insert('a' + i);
		string ans = dfs(n, minInv, minStr, S);
		return ans;
	}
};
