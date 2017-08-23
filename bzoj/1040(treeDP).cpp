#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
const int N=1000005;
int node,root,t,a[N],h[N];
long long f[N][2];
bool flag;
vector<pair<int,int> >g[N];
void dfs(int u,int pre)
{
      h[u]=1;
      for(int i=0;i<g[u].size();++i)
      {
            int v=g[u][i].first;
            if(v==pre)  continue;
            if(h[v])
            {
                  node=u;root=v;t=g[u][i].second;
                  continue;
            }
            dfs(v,u);
      }
}
void dp(int u,int pre)
{
      f[u][0]=f[u][1]=0;
      for(int i=0;i<g[u].size();++i)
      {
            int v=g[u][i].first;
            if(g[u][i].second==t || v==pre)     continue;
            dp(v,u);
            f[u][0]+=max(f[v][0],f[v][1]);
            f[u][1]+=f[v][0];
      }
      f[u][1]+=a[u];
      if(u==root && !flag)    f[u][1]=0;
      if(u==node && flag)     f[u][1]=0;
}
int main()
{
     int x,n;scanf("%d",&n);
     for(int i=1;i<=n;++i)
     {
         scanf("%d",&a[i]);
         scanf("%d",&x);
         g[i].push_back(make_pair(x,i));
         g[x].push_back(make_pair(i,i));
     }
     long long ans=0ll;
     for(int i=1;i<=n;++i)
     if(!h[i])
     {
            node=0;dfs(i,0);
            flag=true;dp(root,0);
            long long tmp=max(f[root][0],f[root][1]);
            flag=false;dp(root,0);
            tmp=max(tmp,max(f[root][0],f[root][1]));
            ans+=tmp;
     }
     printf("%lld",ans);
     return 0;
}
