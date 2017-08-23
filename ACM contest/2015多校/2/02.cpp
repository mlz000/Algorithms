#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
inline void read(int &t) {
    int f = 1;char c;
    while (c = getchar(), c < '0' || c > '9') if (c == '-') f = -1;
    t = c - '0';
    while (c = getchar(), c >= '0' && c <= '9') t = t * 10 + c - '0';
    t *= f;
}
int main() {
    int n, m, x, y;
    while (scanf("%d%d%d%d", &n, &m, &x, &y) != EOF) {
        int ans = min(n + 1, m + 1) / 2;
        if ((n == m) && ((LL)(n * m) & 1) && (x == (n + 1) / 2) && (y == (m + 1) / 2))    --ans;
        else {
            if (x != 1)    ans = max(ans, min(x - 1, min(y, m - y + 1)));
            if (x != n)    ans = max(ans, min(n - x, min(y, m - y + 1)));
            if (y != 1)    ans = max(ans, min(y - 1, min(x, n - x + 1)));
            if (y != m)    ans = max(ans, min(m - y, min(x, n - x + 1)));
        }
        cout << ans << endl;
    }
    return 0;
}
