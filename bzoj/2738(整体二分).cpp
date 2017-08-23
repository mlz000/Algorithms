#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define F first
#define S second
const int N = 505, M = 60005;
inline void read(int &t) {
    int f = 1;char c;
    while (c = getchar(), c < '0' || c > '9') if (c == '-') f = -1;
    t = c - '0';
    while (c = getchar(), c >= '0' && c <= '9') t = t * 10 + c - '0';
    t *= f;
}
int now, n, m, p, ans[M], cnt[M];
struct node {
    int x, y, num;
}a[N * N];
struct data {
    int p, x1, y1, x2, y2, k, num, cur;
}q[M], q1[M], q2[M];
struct BIT {
    int c[N][N];
    void add(int x, int y, int w) {
        for (int i = x; i <= n; i += i & -i)
            for (int j = y; j <= n; j += j & -j)
                c[i][j] += w;
    }
    int sum(int x, int y) {
        int t = 0;
        for (int i = x; i; i -= i & -i)
            for (int j = y; j; j -= j & -j)
                t += c[i][j];
        return t;
    }
}b;
bool cmp(const node &p, const node &q) {
    return p.num < q.num;
}
void solve(int l, int r, int x, int y) {
    if (x > y)   return;
    if (l == r) {
        for (int i = x; i <= y; ++i) ans[q[i].num] = l;
        return ;
    }
    int mid = l + r >> 1;
    while (a[now + 1].num <= mid && now + 1 <= p) {
        ++now;
        b.add(a[now].x, a[now].y, 1);
    }
    while (a[now].num > mid && now) {
        b.add(a[now].x, a[now].y, -1);  
        --now;
    }
    int t1 = 0, t2 = 0;
    for (int i = x; i <= y; ++i) {
        if (b.sum(q[i].x2, q[i].y2) - b.sum(q[i].x2, q[i].y1 - 1) - b.sum(q[i].x1 - 1, q[i].y2) + b.sum(q[i].x1 - 1, q[i].y1 - 1) >= q[i].k) {
            q1[++t1] = q[i];
        }
        else q2[++t2] = q[i];
    }
    copy(q1 + 1, q1 + t1 + 1, &q[x]);
    copy(q2 + 1, q2 + t2 + 1, &q[x + t1]);
    solve(l, mid, x, x + t1 - 1);
    solve(mid + 1, r, x + t1, y);
}
int main() {
    read(n), read(m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            read(a[++p].num);
            a[p].x = i, a[p].y = j;
        }
    sort(a + 1, a + p + 1, cmp);
    for (int i = 1; i <= m; ++i) {
        read(q[i].x1), read(q[i].y1), read(q[i].x2), read(q[i].y2), read(q[i].k);
        q[i].num = i;   
    }
    solve(0, (int)1e9, 1, m); 
    for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
    return 0;
}
