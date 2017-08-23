#include <iostream>
#include <string.h>
#include <stdio.h>
 
using namespace std;
typedef long long LL;
const int N = 10000005;
 
bool vis[N];
int p[N];
int cnt;
int g[N],u[N],sum[N];
 
void Init()
{
    memset(vis,0,sizeof(vis));
    u[1] = 1;
    cnt = 0;
    for(int i=2;i<N;i++)
    {
        if(!vis[i])
        {
            p[cnt++] = i;
            u[i] = -1;
            g[i] = 1;
        }
        for(int j=0;j<cnt&&i*p[j]<N;j++)
        {
            vis[i*p[j]] = 1;
            if(i%p[j])
            {
                u[i*p[j]] = -u[i];
                g[i*p[j]] = u[i] - g[i];
            }
            else
            {
                u[i*p[j]] = 0;
                g[i*p[j]] = u[i];
                break;
            }
        }
    }
    sum[0] = 0;
    for(int i=1;i<N;i++)
        sum[i] = sum[i-1] + g[i];
}
 
int main()
{
    Init();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        LL n,m;
        cin>>n>>m;
        if(n > m) swap(n,m);
        LL ans = 0;
        for(int i=1,last;i<=n;i=last+1)
        {
            last = min(n/(n/i),m/(m/i));
            ans += (n/i)*(m/i)*(sum[last]-sum[i-1]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
