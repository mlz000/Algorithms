#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
const int N=65;
int g[N],st[N],f[25][25][25];
bool v[N];
int dfs(int x)
{
    v[x]=true;
    if(v[g[x]]) return 1;
    else return dfs(g[x])+1;
}
int mul(int x,int k,int p)
{
    int tmp=1;
    for(;k;k>>=1,x=x*x%p)
    if(k&1) tmp=tmp*x%p;
    return tmp;
}
int main()
{
    int sr,sb,sg,m,p;
    int ans=0;
    int i,j,a,b,c,n;
    scanf("%d%d%d%d%d",&sr,&sb,&sg,&m,&p);
    n=sr+sb+sg;
    for(i=1;i<=m+1;++i)
    {
        if(i==m+1)  {for(j=1;j<=n;++j) g[j]=j;}
        else {for(j=1;j<=n;++j)   scanf("%d",&g[j]);}
        memset(st,0,sizeof(st));
        memset(v,false,sizeof(v));
        memset(f,0,sizeof(f));
        for(j=1;j<=n;++j)
         if(!v[j]) st[++st[0]]=dfs(j);
        f[0][0][0]=1; 
        for(j=1;j<=st[0];++j)
        {
            for(a=sr;a>=0;--a)
             for(b=sb;b>=0;--b)
              for(c=sg;c>=0;--c)
              {
                if(a>=st[j]) f[a][b][c]=(f[a][b][c]+f[a-st[j]][b][c])%p;
                if(b>=st[j]) f[a][b][c]=(f[a][b][c]+f[a][b-st[j]][c])%p;
                if(c>=st[j]) f[a][b][c]=(f[a][b][c]+f[a][b][c-st[j]])%p;
              }
        } 
        ans=(ans+f[sr][sb][sg])%p; 
    } 
    ans=ans*mul(m+1,p-2,p)%p;//ÄæÔª 
    printf("%d",ans);
    return 0;
}
