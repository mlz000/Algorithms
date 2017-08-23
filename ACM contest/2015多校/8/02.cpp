#include <bits/stdc++.h>//Äª¶Ó
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
inline void read(int &t) {
    int f = 1;char c;
    while (c = getchar(), c < '0' || c > '9') if (c == '-')    f = -1;
    t = c - '0';
    while (c = getchar(), c >= '0' && c <= '9')    t = t * 10 + c - '0';
    t *= f;
}
const int N = 10005;
int s, n, a[N], cl[N], cr[N], len[N], st[20][N];
LL ans[N];
struct data {
	int pos, num;
	data(){}
	data(int pos, int num) : pos(pos), num(num){}
}pl[N][20], pr[N][20];
struct ask {
	int l, r, id;
}Q[N];
bool cmp(const ask &p, const ask &q) {
	return p.l / s < q.l / s || (p.l / s == q.l / s && p.r < q.r);
}
void gaol() {
	for (int i = 1; i <= n; ++i) {
		int last = 0, now = i;
		while (1) {
			int ansp = n + 1, ansn = last;
			int l = now, r = n;
			while (l <= r) {
				int mid = l + r >> 1;
				int L = mid - i + 1;
				int t = __gcd(st[len[L]][i], st[len[L]][mid - (1 << len[L]) + 1]);
				if (t != last) {
					ansp = mid;
					ansn = t;
					r = mid - 1;
				}
				else l = mid + 1;
			}
			pl[i][++cl[i]] = data(ansp, ansn);
			if (ansp > n)	break;
			now = ansp + 1;
			last = ansn;
		}
	}
}
void gaor() {
	for (int i = n; i >= 1; --i) {
		int last = 0, now = i;
		while (1) {
			int ansp = 0, ansn = last;
			int l = 1, r = now;
			while (l <= r) {
				int mid = l + r >> 1;
				int L = i - mid + 1;
				int t = __gcd(st[len[L]][mid], st[len[L]][i - (1 << len[L]) + 1]);
				if (t != last) {
					ansp = mid;
					ansn = t;
					l = mid + 1;
				}
				else r = mid - 1;
			}
			pr[i][++cr[i]] = data(ansp, ansn);
			if (ansp < 1)	break;
			now = ansp - 1;
			last = ansn;
		}
	}
}
int main() {
	int T, q;
	read(T);
	for(int i = 1, j = 1, k = -1; i <= 10000; ++i) {
		if (i == j)   len[i] = ++k, j <<= 1;
		else len[i] = k;
	}	
	while (T--) {
		scanf("%d", &n);
		s = sqrt(n);
		memset(cl, 0, sizeof(cl));
		memset(cr, 0, sizeof(cr));
		for (int i = 1; i <= n; ++i)	scanf("%d", &a[i]), st[0][i] = a[i];
		for (int i = 1; i <= len[n]; ++i)
			for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
				st[i][j] = __gcd(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
			}
		gaol();
		gaor();
		scanf("%d", &q);
		for (int i = 1; i <= q; ++i) {
			scanf("%d%d", &Q[i].l, &Q[i].r);
			Q[i].id = i;
		}
		sort(Q + 1, Q + q + 1, cmp);
		LL t = 0;
		int L, R;
		for (int i = 1; i <= q; ++i) {
			if (i == 1) {
				for (int j = Q[i].l; j <= Q[i].r; ++j) {
					for (int k = 2; k <= cl[j]; ++k) {
						if (pl[j][k - 1].pos > Q[i].r)	break;
						if (pl[j][k].pos <= Q[i].r) {
							t += (LL)(pl[j][k].pos - pl[j][k - 1].pos) * pl[j][k - 1].num;
						}
						else if (pl[j][k].pos > Q[i].r) {
							t += (LL)(Q[i].r - pl[j][k - 1].pos + 1) * pl[j][k - 1].num;
						}
					}
				}
				L = Q[i].l, R = Q[i].r;
				ans[Q[i].id] = t;
			}
			else {
				while (L > Q[i].l) {
					--L;
					for (int j = 2; j <= cl[L]; ++j) {
						if (pl[L][j - 1].pos > R)	break;
						if (pl[L][j].pos <= R) {
							t += (LL)(pl[L][j].pos - pl[L][j - 1].pos) * pl[L][j - 1].num;
						}
						else if (pl[L][j].pos > R) {
							t += (LL)(R - pl[L][j - 1].pos + 1) * pl[L][j - 1].num;
						}
					}
				}
				while (L < Q[i].l) {
					for (int j = 2; j <= cl[L]; ++j) {
						if (pl[L][j - 1].pos > R)	break;
						if (pl[L][j].pos <= R) {
							t -= (LL)(pl[L][j].pos - pl[L][j - 1].pos) * pl[L][j - 1].num;
						}
						else if (pl[L][j].pos > R) {
							t -= (LL)(R - pl[L][j - 1].pos + 1) * pl[L][j - 1].num;
						}
					}
					++L;
				}
				while (R < Q[i].r) {
					++R;
					for (int j = 2; j <= cr[R]; ++j) {
						if (pr[R][j - 1].pos < L)	break;
						if (pr[R][j].pos >= L) {
							t += (LL)(pr[R][j - 1].pos - pr[R][j].pos) * pr[R][j - 1].num;
						}
						else if (pr[R][j].pos < L) {
							t += (LL)(pr[R][j - 1].pos - L + 1) * pr[R][j - 1].num;
						}
					}
				}
				while (R > Q[i].r) {
					for (int j = 2; j <= cr[R]; ++j) {
						if (pr[R][j - 1].pos < L)	break;
						if (pr[R][j].pos >= L) {
							t -= (LL)(pr[R][j - 1].pos - pr[R][j].pos) * pr[R][j - 1].num;
						}
						else if (pr[R][j].pos < L) {
							t -= (LL)(pr[R][j - 1].pos - L + 1) * pr[R][j - 1].num;
						}
					}
					--R;
				}
				ans[Q[i].id] = t;
			}
		}
		for (int i = 1; i <= q; ++i)	cout << ans[i] << endl;
	}
	return 0;
}
