#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define F first
#define S second
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
const int N = 1e5 + 5;
int ans, len[N];
char S[N];
struct Pal_tree {
	int nxt[N][26], fail[N], cnt[N], num[N], len[N], s[N], last, n, p;
	int insert(int l) {
		for (int i = 0; i < 26; ++i)	nxt[p][i] = 0;
		cnt[p] = num[p] = 0;
		len[p] = l;
		return p++;
	}
	void init() {
		p = last = n = 0;
		insert(0), insert(-1);
		s[n] = -1, fail[0] = 1;
	}
	inline int get_fail(int x) {
		while (s[n - len[x] - 1] != s[n])	x = fail[x];
		return x;
	}
	int add(int c) {
		s[++n] = c;
		int cur = get_fail(last);
		if (!nxt[cur][c]) {
			int now = insert(len[cur] + 2);
			fail[now] = nxt[get_fail(fail[cur])][c];
			nxt[cur][c] = now;
			num[now] = num[fail[now]] + 1;
		}
		last = nxt[cur][c];
		++cnt[last];
		return last;
	}
	void gao() {
		LL t = 0ll;
		for (int i = p - 1; i >= 0; --i)	cnt[fail[i]] += cnt[i];
	}
}a;
int main() {
	a.init();
	scanf("%s", S);
	int l = strlen(S);
	for (int i = 0; i < l; ++i) {
		len[i] = a.len[a.add(S[i] - 'a')];
		if (i - len[i] >= 0)	ans = max(ans, len[i] + len[i - len[i]]);
	}
	printf("%d\n", ans);
	return 0;
}

