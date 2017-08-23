#include<cstdio>
#include<iostream> 
#include<climits>
#include<queue> 
#include<cstring> 
#include<algorithm> 
#include<cmath> 
using namespace std;
const int N=1005,M=30;
int pos,c[M],g[N][N],dis[N][M],h[N]; 
bool v[N][M]; 
int n,m; 
struct data
{
  int x;//²ãÊý
  int y;//ÊÖ±úÎ»ÖÃ 
}; 
int ABS(int p) {if(p<0) return -p;else return p;} 
void spfa()
{
    int i; 
    queue<data> q;
    memset(dis,0x3f,sizeof(dis)); 
    data s;s.x=1;s.y=pos;
    q.push(s); 
    dis[1][pos]=0;
    v[1][pos]=true; 
    while(q.size())
    {
      data now=q.front();
      q.pop(); 
      v[now.x][now.y]=false;
      for(i=1;i<=m;++i)
      {
        if(now.x+c[i]>=1 && now.x+c[i]<=n && dis[now.x+c[i]][i]>dis[now.x][now.y]+ABS(now.y-i)+ABS(c[i])*2)
         {
            dis[now.x+c[i]][i]= dis[now.x][now.y]+ABS(now.y-i)+ABS(c[i])*2;
            if(!v[now.x+c[i]][i]) 
            {
             v[now.x+c[i]][i]=true;
             s.x=now.x+c[i];
             s.y=i;
             q.push(s); 
            } 
         } 
      } 
    }    
} 
int main()
{ 
      scanf("%d%d",&n,&m);
      int i; 
      memset(g,0x3f,sizeof(g)); 
      for(i=1;i<=m;++i)
       {
         scanf("%d",&c[i]);
         if(c[i]==0) pos=i;
       }
      spfa(); 
      int ans=INT_MAX; 
      for(i=1;i<=m;++i)
       ans=min(ans,dis[n][i]);
      if(ans==0x3f3f3f3f) printf("-1");
      else printf("%d",ans);  
    //  system("pause"); 
      return 0;
}
