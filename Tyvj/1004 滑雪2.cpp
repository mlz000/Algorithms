#include<cstdio>  
#include<cstring>
#include<stdlib.h>
int n,m;  
int x[4]={0,0,-1,1};  
int y[4]={-1,1,0,0};  
int g[101][101],res;  
int vis[101][101];  
int dfs(int r,int c)  
{  
    if(vis[r][c]>1)  return vis[r][c];  
    int xx,yy;  
    for(int i=0;i<4;i++)  
    {  
        xx=r+x[i];  
        yy=c+y[i];  
        if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&g[r][c]>g[xx][yy])  
        {  
            int t=dfs(xx,yy)+1;  
            if(t>vis[r][c])  vis[r][c]=t;  
        }  
    }  
    return vis[r][c];  
}  
int main()  
{  
    memset(vis,0,sizeof(vis));  
    scanf("%d%d",&n,&m);  
    for(int i=1;i<=n;i++)  
      for(int j=1;j<=m;j++)  
          {  
              scanf("%d",&g[i][j]);  
              vis[i][j]=1;  
          }  
    res=0;  
    for(int i=1;i<=n;i++)  
      for(int j=1;j<=m;j++)  
      {  
          int t=dfs(i,j);  
          if(t>res)  res=t;  
      }  
    printf("%d\n",res);  
    system("pause");
    return 0;  
}  
