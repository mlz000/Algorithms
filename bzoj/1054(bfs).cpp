#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int dx[5]={0,1,0,-1,0};
int dy[5]={0,0,1,0,-1};
int f[1<<16][5][5],g[5][5],ans[1<<16]; 
bool v[1<<16];
char s[6];
int main()
{
      int i,j,S=0,T=0;
      for(i=1;i<=4;++i)
      {
          scanf("%s",s+1);
          for(j=1;j<=4;++j)   f[1][i][j]=s[j]-'0',S=(S<<1)+f[1][i][j];
      }
      v[S]=true;
      for(i=1;i<=4;++i)
      {
          scanf("%s",s+1);
          for(j=1;j<=4;++j)   T=(T<<1)+s[j]-'0';
      }
      int l=1,r=2;
      if(S==T)    {printf("0");return 0;}
      while(l<r)
      {
           for(int x=1;x<=4;++x)
            for(int y=1;y<=4;++y)
            if(f[l][x][y])
            {
                  for(i=1;i<=4;++i)
                   if(x+dx[i]>=1 && x+dx[i]<=4 && y+dy[i]>=1 && y+dy[i]<=4 && f[l][x+dx[i]][y+dy[i]]==0)
                   {
                        for(int xx=1;xx<=4;++xx)
                         for(int yy=1;yy<=4;++yy)
                          g[xx][yy]=f[l][xx][yy];
                         g[x][y]=0,g[x+dx[i]][y+dy[i]]=1;
                        int tmp=0;
                        for(int xx=1;xx<=4;++xx)
                         for(int yy=1;yy<=4;++yy)
                         tmp=(tmp<<1)+g[xx][yy];
                         if(tmp==T) {printf("%d",ans[l]+1);return 0;}  
                         if(!v[tmp])
                         {
                              v[tmp]=true;
                              ++r;
                            for(int xx=1;xx<=4;++xx)
                              for(int yy=1;yy<=4;++yy)
                              f[r][xx][yy]=g[xx][yy];
                            ans[r]=ans[l]+1;  
                         }
                   }
            } 
            ++l;
      }
      return 0;
}
