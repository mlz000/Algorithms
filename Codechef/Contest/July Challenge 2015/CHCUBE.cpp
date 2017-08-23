#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
map<string, int > mp;
int main() {
	int T;
	read(T);
	while (T--) {
		string s[6];
		for (int i = 0; i < 6; ++i)	cin >> s[i];
		if ((s[0] == s[2] && s[2] == s[4]) || (s[0] == s[3] && s[3] == s[4]) || (s[1] == s[2] && s[2] == s[4]) || (s[1] == s[3] && s[3] == s[4]) || (s[0] == s[2] && s[2] == s[5]) || (s[0] == s[3] && s[3] == s[5]) || (s[1] == s[2] && s[2] == s[5]) || (s[1] == s[3] && s[3] == s[5]))	puts("YES");
		else puts("NO");
	}
	return 0;
}
