#include<cstdio> 
#include<iostream>
#include<algorithm>
#include<queue> 
#include<cstring> 
using namespace std; 
const int N=1005;
int map[N][N],dis[N]; 
bool v[N]; 
int n,p,k; 
bool spfa(int w)
{
    int i; 
    queue<int> q; 
    q.push(1);
    memset(v,false,sizeof(v)); 
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0; 
    while(q.size())
    {
      int x=q.front(); 
      q.pop(); 
      v[x]=false; 
      for(i=1;i<=n;++i)
      {
        bool flag=false; 
        if(map[x][i]) 
        {
          if(map[x][i]<=w)
          {
            if(dis[x]<dis[i]) {dis[i]=dis[x];flag=true;} 
          } 
          else 
          {
            if(dis[x]+1<dis[i]) {dis[i]=dis[x]+1;flag=true;} 
          } 
          if(flag && !v[i])
          {
            q.push(i);
            v[i]=true; 
          } 
        } 
      } 
    } 
    return dis[n]<=k; 
} 
int main()
{ 
      int i,l,r,a,b,c;  
      scanf("%d%d%d",&n,&p,&k); 
      l=r=0; 
      for(i=1;i<=p;++i) 
      {
        scanf("%d%d%d",&a,&b,&c);
        map[a][b]=map[b][a]=c; 
        r=max(r,c); 
      } 
      if(!spfa(r)) {printf("-1");return 0;} 
      while(l<=r)
      {
        if(l==r) break; 
        int mid=(l+r+1)>>1;
        if(spfa(mid)) r=mid;
        else l=mid+1; 
      } 
      printf("%d",r); 
      system("pause");  
      return 0; 
} 

