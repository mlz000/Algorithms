#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=205;
int n,g[N][N],l[N*N];
bool v[N*N];
bool can(int u)
{
      int i;
      for(i=1;i<=n;++i)
       if(!v[i] && g[u][i])
       {
            v[i]=true;
            if(!l[i] || can(l[i]))
            {
                 l[i]=u;
                 return true; 
            }
       }
      return false; 
}
int main()
{
      int T,i,j;
      scanf("%d",&T);
      while(T--)
      {
            scanf("%d",&n);
            for(i=1;i<=n;++i)
             for(j=1;j<=n;++j)      scanf("%d",&g[i][j]);
             memset(l,0,sizeof(l));
            for(i=1;i<=n;++i)
            {
                  memset(v,false,sizeof(v));
                  if(!can(i)) break;
            } 
            if(i<=n)    printf("No\n");
            else printf("Yes\n");      
      }
	return 0;
}
