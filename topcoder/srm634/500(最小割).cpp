#include <bits/stdc++.h>//ans = sum - mincut
using namespace std;
#define sz(x)	x.size() 
#define mp make_pair
#define X first
#define Y second
typedef pair<int, int> pii;
typedef long long LL;
const int N = 500;
const LL inf = 1e14;
int tot, to[N * N], nxt[N * N], head[N << 1],  cur[N << 1], pre[N << 1], dis[N * N], sum[N << 1];
long long cap[N * N];
LL det(pii a, pii b, pii c) {
	return (b.X - a.X) * (c.Y - a.Y) - (b.Y - a.Y) * (c.X - a.X);
}
bool inter(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3) {
	pii a, b, c, d;
	a = mp(x0, y0), b = mp(x1, y1), c = mp(x2, y2), d = mp(x3, y3);
	return max(x0, x1) >= min(x2, x3) && max(x2, x3) >= min(x0, x1) && max(
			y0, y1) >= min(y2, y3) && max(y2, y3) >= min(y0, y1) &&
			det(a, b, c) * det(a, b, d) <= 0 && det(c, d, a) * det(c, d, b) <= 0;
}
long long isap(int st, int ed) {
	int n = ed + 1;
	memset(dis, 0, sizeof(dis));
	memset(sum, 0, sizeof(sum));
	memset(pre, -1, sizeof(pre));
	sum[0] = n;
	for (int i = st; i <= ed; ++i)	cur[i] = head[i];
	int u = pre[st] = st;
	long long flow = 0ll, aug = -1;
	bool ok;
	while (dis[st] < n) {
		ok = 0;
		for (int &i = cur[u]; ~i; i = nxt[i]) {
			int v = to[i];
			if (cap[i] && dis[u] == dis[v] + 1) {
				ok = 1;
				pre[v] = u;
				u = v;
				aug = (aug == -1) ? cap[i] : min(aug, cap[i]);
				if (v == ed) {
					flow += aug;
					for (u = pre[v]; v != st; v = u, u = pre[u]) {
						cap[cur[u]] -= aug;
						cap[cur[u] ^ 1] += aug;
					}
					aug = -1;
				}
				break;
			}
		}
		if (ok)	continue;
		int Min = n;
		for (int i = head[u]; ~i; i = nxt[i]) {
			int v = to[i];
			if (cap[i] && dis[v] < Min) {
				cur[u] = i;
				Min = dis[v];
			}
		}
		if (--sum[dis[u]] == 0)	break;
		dis[u] = Min + 1;
		++sum[dis[u]];
		u = pre[u];
	}
	return flow;
}
void add(int u, int v,long long w) {
	cap[tot] = w, to[tot] = v, nxt[tot] = head[u], head[u] = tot++;
	cap[tot] = 0, to[tot] = u, nxt[tot] = head[v], head[v] = tot++;
}
class SegmentDrawing {
    public:
	int maxScore(vector <int> x, vector <int> y, vector <int> redScore, vector <int> blueScore) {
		memset(head, -1, sizeof(head));
		int n = sz(x), m = sz(redScore);
		int S = 0, T =  m << 1 | 1;
		long long ans = 0ll;	
		for (int i = 0; i < m; ++i) {
			int x0 = x[i / n], y0 = y[i / n], x1 = x[i % n], y1 = y[i % n];
			if (i / n >= i % n)	continue;
			ans += redScore[i] + blueScore[i];
			add(S, i + 1, redScore[i]);
			add(i + m + 1, T, blueScore[i]);
			add(i + 1, i + m + 1, inf);
			for (int j = 0; j < m; ++j) {
				int x2 = x[j / n], y2 = y[j / n], x3 = x[j % n], y3 = y[j % n];
				if (j / n >= j % n || j == i)	continue;
				if (inter(x0, y0, x1, y1, x2, y2, x3, y3))	add(i + 1, j + m + 1, inf);
			}
		}
		return ans - isap(S, T);
	}
};	 



