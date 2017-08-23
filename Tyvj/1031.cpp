#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int N=2505;
int data[N][N];
long long dis[N];
int t,c,ts,te;
int i;
bool v[N];
void spfa(int v0)
{
    queue<int>q;
    q.push(v0);
    memset(dis,63,sizeof(dis));
    for(i=1;i<=t;++i)
     dis[i]=data[v0][i];
     dis[v0]=0;
    while(!q.empty())
    {
      int x=q.front();
      v[x]=false;
      q.pop();
      for(i=1;i<=t;++i)
      {
         if(dis[x]+data[x][i]<=dis[i])
         {
            dis[i]=dis[x]+data[x][i];
            if(v[i]==false)
            {
              v[i]=true;
              q.push(i);
            }
         }
      }
    }
}
int main()
{
      scanf("%d%d%d%d",&t,&c,&ts,&te);
      int a,b,d;
      memset(data,63,sizeof(data));
      for(i=1;i<=c;++i)
      {
        scanf("%d%d%d",&a,&b,&d);
        data[a][b]=min(d,data[a][b]);
        data[b][a]=min(d,data[b][a]);
      }
     spfa(ts);
     cout<<dis[te]<<endl;
    // system("pause");
     return 0;
}
