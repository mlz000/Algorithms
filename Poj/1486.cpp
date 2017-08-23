#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 35;
bool g[N][N], v[N];
int n, m, l[N];
struct node {
    int x1, x2, y1, y2;
}p[N];
bool can (int u) {
    for (int i = 0; i < n; ++i){
        if (!v[i] && g[u][i]) {
            v[i] = 1;
            if(l[i] == -1 || can(l[i])) {
                l[i] = u;
                return 1;
            }
        }
    }
    return 0;
}
int solve() {
    int ans = 0;
    memset(l, -1, sizeof(l));
    for(int i = 0; i < n; i++) {
        memset(v, 0, sizeof(v));
        ans += can(i);
    }
    return ans;
}
int main() {
    int cas = 0;
    while(scanf("%d", &n) != EOF && n) {
        if(cas)	puts("");
        printf("Heap %d\n", ++cas);
        for(int i = 0; i < n; i++)	scanf("%d%d%d%d", &p[i].x1, &p[i].x2, &p[i].y1, &p[i].y2);
        memset(g, 0, sizeof(g));
        int x, y;
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &x, &y);
            for(int j = 0; j < n; j++)
                if(x > p[j].x1 && x < p[j].x2 && y > p[j].y1 && y < p[j].y2)	g[i][j] = 1;
        }
        solve();
        int flag = 0;
        for(int i = 0; i < n; i++) {
            int t = l[i];
            l[i] = -1;
            g[t][i] = 0;
            memset(v, 0, sizeof(v));
            if(!can(t)) {
                if(flag) printf(" ");
                printf("(%c,%d)", 'A' + i, t + 1);
                flag = 1;
                l[i] = t;
            }
            g[t][i] = 1;
        }
        if(!flag) printf("none\n");
        else puts("");
    }
    return 0;
}

