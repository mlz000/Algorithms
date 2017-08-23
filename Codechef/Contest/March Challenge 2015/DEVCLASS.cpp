#include <bits/stdc++.h>
using namespace std;
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
#define pb push_back
const int N = 1000005;
char s[N];
vector<int>b, g;
int main() {
	int T;
	read(T);
	while (T--) {
		b.clear(), g.clear();
		int X;
		read(X);
		scanf("%s", s);
		int l = strlen(s), x = 0, y = 0;
		for (int i = 0; i < l; ++i) {
			if (s[i] == 'B')	++x;
			else ++y;
		}
		if (abs(x - y) >= 2) {
			puts("-1");
			continue;
		}
		long long ans = 0;
		if (X == 0) {
			if (x > y) {
				for (int i = 0; i < l; i += 2) if (s[i] == 'G')	++ans;
			}
			else if (x < y) {
				for (int i = 0; i < l; i += 2) if (s[i] == 'B')	++ans;
			}
			else {
				int cnt1 = 0, cnt2 = 0;
				for (int i = 0; i < l; i += 2) {
					if (s[i] == 'B')	cnt1++;
					if (s[i] == 'G')	cnt2++;
				}	
				ans = min(l / 2 - cnt1, l / 2 - cnt2);
			}
		}
		else {
			if (x >= y) {
				for (int i = 0; i < l; ++i) {
					if ((i & 1) && s[i] == 'B')	b.pb(i);
					if (!(i & 1) && s[i] == 'G')	g.pb(i);
				}
			}
			else {
				for (int i = 0; i < l; ++i) {
					if (!(i & 1) && s[i] == 'B')	b.pb(i);
					if ((i & 1) && s[i] == 'G')	g.pb(i);
				}				
			}
			long long ans2 = 0;
			if (!b.size()) {
				puts("0");
				continue;
			}
			for (int i = 0; i < b.size(); ++i) {
				ans += abs(b[i] - g[i]);
			}
			if (x == y) {
				b.clear(), g.clear();
				for (int i = 0; i < l; ++i) {
					if (!(i & 1) && s[i] == 'B')	b.pb(i);
					if ((i & 1) && s[i] == 'G')	g.pb(i);
				}	
				if (b.size())	{
					for (int i = 0; i < b.size(); ++i) {
						ans2 += abs(b[i] - g[i]);
					}
					ans = min(ans, ans2);
				}
				else ans = 0;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
