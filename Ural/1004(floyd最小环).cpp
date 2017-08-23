#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=105,INF=100000000;
int g[N][N],dis[N][N],path[N][N],c[N][N];
void dfs(int x,int y)
{
     int tmp=path[x][y];
     if(path[x][tmp])   dfs(x,tmp);
     printf("%d ",tmp);
     if(path[tmp][y])   dfs(tmp,y);
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m))
    {
        if(n==-1) break;
        int x,y,z;
        for(int i=1;i<=n;++i)
         for(int j=1;j<=n;++j)
          g[i][j]=INF;
        for(int i=1;i<=m;++i)
        {
           scanf("%d%d%d",&x,&y,&z);
           g[x][y]=g[y][x]=min(g[x][y],z);     
        }
        memcpy(dis,g,sizeof(dis));
        memset(c,0,sizeof(c));
        memset(path,0,sizeof(path));
        int ans=INF;
        int p,q,l;
        for(int k=1;k<=n;++k)
        {
         for(int i=1;i<=n;++i)
         if(g[k][i]!=INF)
         {
            for(int j=i+1;j<=n;++j)
             if(g[k][j]!=INF && dis[i][j]+g[i][k]+g[k][j]<ans)  
             {
                ans=dis[i][j]+g[i][k]+g[k][j];             
                p=i,q=j,l=k;
                memcpy(path,c,sizeof(path));
             }    
         }
         for(int i=1;i<=n;++i)
          for(int j=i+1;j<=n;++j)
          if(dis[i][k]+dis[k][j]<dis[i][j]) 
          {
             dis[i][j]=dis[j][i]=dis[i][k]+dis[k][j];
             c[i][j]=c[j][i]=k;                               
          }                                 
        }
        if(ans==INF)      printf("No solution.\n"); 
        else 
        {
             printf("%d %d ",l,p);
             if(path[p][q]) dfs(p,q);
             printf("%d\n",q);      
        }
    }
    return 0;
} 
