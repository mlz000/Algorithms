#include <bits/stdc++.h>
using namespace std;
const int N = 50005;
char s[N], s1[N], s2[N];
vector<int> pos[N * 11];
map<int, int> ans[N * 11] ;
int get(char *s) {
	int t = 0;
	int l = strlen(s);
	for (int i = 0; i < l; ++i)	t = t * 27 + s[i] - 'a' + 1;
	return t;
}
int main() {
	int q;
	scanf("%s%d", s, &q);
	int l = strlen(s);
	for (int i = 0; i < l; ++i) {
		int h = 0;
		for (int j = 0; j < 4 && i + j < l; ++j) {
			h = h * 27 + s[i + j] - 'a' + 1;
			pos[h].push_back(i);
		}
	}
	while (q--) {
		scanf("%s%s", s1, s2);
		int h1 = get(s1), h2 = get(s2);
		int l1 = strlen(s1), l2 = strlen(s2);
		if (ans[h1].count(h2)) {
			printf("%d\n", ans[h1][h2]);
			continue;
		}
		if (!pos[h1].size() || !pos[h2].size()) {
			puts("-1");
			continue;
		}
		else {
			int t = INT_MAX;
			int p1 = 0, p2 = 0;
			while (p1 < pos[h1].size() && p2 < pos[h2].size()) {
				t = min(t, max(pos[h1][p1] + l1, pos[h2][p2] + l2) - min(pos[h1][p1], pos[h2][p2]));
				if (pos[h1][p1] < pos[h2][p2])	++p1;	
				else ++p2;
			}
			ans[h1][h2] = ans[h2][h1] = t;
			printf("%d\n", t);
		}
	}
	return 0;
}
