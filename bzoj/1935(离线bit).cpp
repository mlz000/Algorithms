#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ls (rt << 1)
#define rs (rt << 1 | 1)
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
const int N = 500005;
pair<int, int> a[N];
int n, m, b[N << 2], ans[N], c[N];
struct data {
	int p, x, y, yy, id;
	data(){}
	data(int p, int x, int y, int yy, int id) : p(p), x(x), y(y), yy(yy), id(id){}
}q[N << 1];
bool cmp(const data &a, const data &b) {
	return a.x < b.x;
}
void add(int p) {
	for (; p <= b[0]; p += p & -p)	++c[p];
}
int sum(int p) {
	int t = 0;
	for (; p; p -= p & -p)	t += c[p];
	return t;
}
int main() {
	read(n), read(m);
	for (int i = 0; i < n; ++i) {
		read(a[i].F), read(a[i].S);
		b[++b[0]] = a[i].S;
	}
	sort(a, a + n);
	for (int i = 0; i < m; ++i) {
		int x1, x2, y1, y2;
		read(x1), read(y1), read(x2), read(y2);
		q[i] = data(-1, x1 - 1, y1 - 1, y2, i);
		q[i + m] = data(1, x2, y1 - 1, y2, i);
		b[++b[0]] = y1 - 1;
		b[++b[0]] = y2;
	}
	sort(q, q + m + m, cmp);
	sort(b + 1, b + b[0] + 1);
	b[0] = unique(b + 1, b + b[0] + 1) - b - 1;
	for (int i = 0, j = 0; i < m * 2; ++i) {
		for (; j < n && a[j].F <= q[i].x; ++j)	add(lower_bound(b + 1, b + b[0] + 1, a[j].S) - b); 
		ans[q[i].id] -= q[i].p * sum(lower_bound(b + 1, b + b[0] + 1, q[i].y) - b);
		ans[q[i].id] += q[i].p * sum(lower_bound(b + 1, b + b[0] + 1, q[i].yy) - b);
	}
	for (int i = 0; i < m; ++i)	printf("%d\n", ans[i]);
	return 0;
}
