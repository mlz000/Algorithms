//第k远
//k-d tree 估价
//x[0],x[1]范围,x,y查询
//曼哈顿最小：max(t[p].x[0]-x,0)+max(x-t[p].x[1],0)+max(t[p].y[0]-y,0)+max(y-t[p].y[1],0);
//曼哈顿最大: max(abs(x-t[p].x[1]),abs(t[p].x[0]-x))+max(abs(y-t[p].y[1]),abs(t[p].y[0]-y));
//欧几里得最小: sqr(max(max(x-t[p].x[1],t[p].x[0]-x),0))+sqr(max(max(y-t[p].y[1],t[p].y[0]-y),0))
//欧几里得最大： max(sqr(x-t[p].x[0]),sqr(x-t[p].x[1]))+max(sqr(y-t[p].y[0]),sqr(y-t[p].y[1]))
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<LL, int> pli;
const int N = (int)1e5 + 5;
int n, m, k, d;
struct Point {
	int x[2], id;
}p[N], q;
struct Node {
	Point p;
	int mx[2], mn[2];
}a[N << 1];
struct answer {
	pli a[21];
	inline void clear() {
		for (int i = 0; i < k; ++i)	a[i] = mp(LONG_LONG_MAX, INT_MAX);
	}
	inline void update(pli x) {
		for (int i = 0; i < k; ++i) {
			if (x < a[i]) {
				for (int j = k - 1; j > i; --j)	a[j] = a[j - 1];
				a[i] = x;
				break;
			}
		}
	}
}ans;
inline bool operator < (const Point &a, const Point &b) {
	return a.x[d] < b.x[d];
}
inline LL dis(LL x, LL y) {
	return x * x + y * y;
}
int build(int rt, int l, int r, int dep) {
	int mid = l + r >> 1;
	d = dep; 
	nth_element(p + l, p + mid, p + r + 1);
	a[rt].p = p[mid];
	for (int i = 0; i < 2; ++i)	a[rt].mx[i] = a[rt].mn[i] = a[rt].p.x[i];
	if (l < mid) {
		build(ls, l, mid - 1, dep ^ 1);
		for (int i = 0; i < 2; ++i) {
			a[rt].mx[i] = max(a[rt].mx[i], a[ls].mx[i]);
			a[rt].mn[i] = min(a[rt].mn[i], a[ls].mn[i]);
		}
 	}
	if (mid < r) {
		build(rs, mid + 1, r, dep ^ 1);
		for (int i = 0; i < 2; ++i) {
			a[rt].mx[i] = max(a[rt].mx[i], a[rs].mx[i]);
			a[rt].mn[i] = min(a[rt].mn[i], a[rs].mn[i]);
		}
	}
}
void ask(int rt, int l, int r, int dep) {
	d = dep;
	ans.update(mp(-dis(q.x[0] - a[rt].p.x[0], q.x[1] - a[rt].p.x[1]), a[rt].p.id));
	if (l == r)	return ;
	int mid = l + r >> 1;
	if (q < a[rt].p) {
		if (r > mid)	ask(rs, mid + 1, r, dep ^ 1);
		if (l < mid && -dis(max(a[ls].mx[0] - q.x[0], q.x[0] - a[ls].mn[0]), max(a[ls].mx[1] - q.x[1], q.x[1] - a[ls].mn[1])) <= ans.a[k - 1].F)	ask(ls, l, mid - 1, dep ^ 1);

	}
	else {
		if (l < mid)	ask(ls, l, mid - 1, dep ^ 1);
		if (r > mid && -dis(max(a[rs].mx[0] - q.x[0], q.x[0] - a[rs].mn[0]), max(a[rs].mx[1] - q.x[1], q.x[1] - a[rs].mn[1])) <= ans.a[k - 1].F)	ask(rs, mid + 1, r, dep ^ 1);
	}

}
int main() {
	read(n);
	for (int i = 1; i <= n; ++i)	read(p[i].x[0]), read(p[i].x[1]), p[i].id = i;
	build(1, 1, n, 0);
	read(m);
	while (m--) {
		ans.clear();
		read(q.x[0]), read(q.x[1]), read(k);
		ask(1, 1, n, 0);
		printf("%d\n", ans.a[k - 1].S);
	}
	return 0;
}

