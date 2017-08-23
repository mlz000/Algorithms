#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXN 100010
int W, vh, N;
struct Gate
{
    int x, y;
}g[MAXN];
void input()
{
    scanf("%d%d%d", &W, &vh, &N);
    for(int i = 0; i < N; i ++) scanf("%d%d", &g[i].x, &g[i].y);
}
int can(int v)
{
    double x1 = g[0].x, x2 = g[0].x + W;
    for(int i = 1; i < N; i ++)
    {
        double d = vh * (double)(g[i].y - g[i - 1].y) / v;
        x1 -= d, x2 += d;
        x1 = std::max(x1, (double)g[i].x), x2 = std::min(x2, (double)g[i].x + W);
        if(x1 > x2 + 1e-10) return 0;
    }
    return 1;
}
void process()
{
    int min = 0, max = 1000010, mid;
    for(;;)
    {
        mid = (max - min) / 2 + min;
        if(mid == min) break;
        if(can(mid)) min = mid;
        else max = mid;
    }
    int s, ans = 0;
    scanf("%d", &s);
    for(int i = 0; i < s; i ++)
    {
        int t;
        scanf("%d", &t);
        if(t <= mid) ans = std::max(t, ans);
    }
    if(ans == 0) printf("IMPOSSIBLE\n");
    else printf("%d\n", ans);
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t --)
    {
        input();
        process();
    }
    return 0;
}

