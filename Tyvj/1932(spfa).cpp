#include <cstdio>
#include <iostream> 
#include <cstring>
#include <cstdlib>
#include <queue> 
#include <algorithm>
using namespace std;
const __int64 MOD = (1LL << 31) - 1;
const int mi = 199311170;
const int N=1005; 
bool v[N];
int map[N][N],dis[N],list[N];
int i,j,n,m; 
void init()
{
   for(i=1;i<=n;++i)
    for(j=1;j<=n;++j)
     map[i][j]=map[j][i]=mi;
   for(i=1;i<=n;++i)
    map[i][i]=0;   
} 
void spfa()
{
        queue<int>q; 
        q.push(1);
        for(i=2;i<=n;++i) dis[i]=mi; 
        while(!q.empty())
        {
           int x=q.front();
           v[x]=false;
           q.pop(); 
           for(i=1;i<=n;++i)
            {
              if(dis[x]+map[x][i]<dis[i]) 
              {
                dis[i]=dis[x]+map[x][i];
                if(!v[i])
                {
                  v[i]=true;
                  q.push(i); 
                }  
              } 
            } 
        } 
} 
bool cmp(const int &p,const int &q)
{
  return dis[p]<dis[q]; 
} 
int main()
{
       scanf("%d%d",&n,&m);
       init();
       int a,b,c; 
       for(i=1;i<=m;++i)
       {
         scanf("%d%d%d",&a,&b,&c); 
         map[a][b]=map[b][a]=min(map[a][b],c); 
       }
       spfa(); 
       for(i=1;i<=n;++i)
        list[i]=i;
       sort(&list[1],&list[n+1],cmp); 
       long long ans=1; 
       for(i=2;i<=n;++i)
       {
          int t=0; 
         for(j=1;j<i;++j)
        {
           if(dis[list[j]]+map[list[j]][list[i]]==dis[list[i]]) t++;  
        }  
        ans=(ans*t)%MOD; 
       }
       cout<<ans;
       return 0; 
       
}  
