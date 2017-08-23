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
const int N = 1e6 + 5, M = 19930726;
int n;
LL k;
char S[N];
vector<pair<int, int> > b;
LL P(LL x, LL y) {
	LL t = 1ll;
	for (; y; y >>= 1) {
		if (y & 1)	t = t * x % M;
		x = x * x % M;
	}
	return t;
}
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
	void add(int c) {
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
	}
	void gao() {
		for (int i = p - 1; i >= 2; --i) {
			cnt[fail[i]] += cnt[i];
			if (len[i] & 1)	b.pb(mp(len[i], cnt[i]));
		}
	}
}a;
int main() {
	a.init();
	cin >> n >> k;
	scanf("%s", S);
	int l = strlen(S);
	for (int i = 0; i < l; ++i)	a.add(S[i] - 'a');
	a.gao();
	sort(b.begin(), b.end());
	reverse(b.begin(), b.end());
	LL ans = 1ll;
	for (int i = 0; i < b.size(); ++i) {
		if (!k)	break;
		if (k - b[i].S >= 0)	ans = ans * P(b[i].F, b[i].S) % M, k -= b[i].S;
		else ans = ans * P(b[i].F, k) % M, k = 0;
	}
	if (k)	puts("-1");
	else cout << ans << endl;
	return 0;
}
