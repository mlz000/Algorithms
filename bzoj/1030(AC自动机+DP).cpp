#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int N=65,M=110,MOD=10007;
char s[M];
bool g[N*M];
int n,m,son[N*M][26],p[N*M],f[2][M][N*M];
int main()
{
      int i,j,k,l,root,n,m;
      int tot=0;
      scanf("%d%d",&n,&m);
      for(i=1;i<=n;++i)
      {
          scanf("%s",s);
          root=0;
          for(j=0;s[j];++j)   
          {
            if(!son[root][s[j]-'A'])      son[root][s[j]-'A']=++tot;
            root=son[root][s[j]-'A'];
          }
          g[root]=true;
      } 
      queue<int> q;
      for(i=0;i<26;++i) if(son[0][i])    q.push(son[0][i]); 
      while(q.size())
      {
          int x=q.front();q.pop();
          for(i=0;i<26;++i)
          {
            int u=son[x][i],v=p[x];
            for(;v && !son[v][i];v=p[v]);
            if(son[x][i])
            {
                  p[u]=son[v][i];
                  q.push(u);
                  g[u]|=g[p[u]];
            }
            else son[x][i]=son[v][i];
          }  
      }
      f[0][0][0]=1;
      for(i=0;i<2;++i)
       for(j=0;j<m;++j)
        for(k=0;k<=tot;++k)
         for(l=0;l<26;++l)
         if(f[i][j][k])
         {
             (f[i|g[son[k][l]]][j+1][son[k][l]] += f[i][j][k]) %= MOD;
         }
      int ans=0;
      for(i=0;i<=tot;++i)
      ans=(ans+f[1][m][i])%MOD;
      printf("%d",ans);   
      return 0;
}
