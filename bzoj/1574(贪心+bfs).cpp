#include<cstdio>//贪心 将报号的点和其所有连接点都当做损坏点,bfs求出1能到达点数ans,答案为n-ans 
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int N=30005;
vector<int>g[N];
bool v[N],vis[N];
int main()
{
      int i,j,n,c,p;
      scanf("%d%d%d",&n,&c,&p);
      for(i=1;i<=c;++i)
      {
            int a,b;
            scanf("%d%d",&a,&b);
            if(a==b)    continue;
            g[a].push_back(b);
            g[b].push_back(a);
      }
      for(i=1;i<=p;++i) 
      {
            int x;
            scanf("%d",&x);
            v[x]=true;
            for(j=0;j<g[x].size();++j)    v[g[x][j]]=true;
      }
      queue<int> q;
      q.push(1);
      int ans=1;
      while(q.size())
      {
            int x=q.front();
            q.pop();
            vis[x]=true;
            for(i=0;i<g[x].size();++i)
            {
                  if(!v[g[x][i]] && !vis[g[x][i]])    
                  {
                        vis[g[x][i]]=true;
                        q.push(g[x][i]);
                        ans++;
                  }
            }
      }
      printf("%d",n-ans);
      return 0;
}
