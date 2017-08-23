#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
bool v[1005],map[1005][1005];
int n,m,l[1005];
bool can(int u)
{
    for(int i=0;i<n;++i)
    {
        if(!v[i] && map[u][i])
        {
            v[i]=true;
            if(!l[i] || can(l[i]))
            {
                l[i]=u;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int i,j,a,b;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d",&a,&b);
        map[i][a]=true;
        map[i][b]=true;
    }
    int ans=0;
    for(int i=1;i<=m;++i)
    {
        memset(v,false,sizeof(v));
        if(can(i))  ++ans;
        else break;
    }
    printf("%d\n",ans);
    return 0;
}
