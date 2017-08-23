#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
struct node
{
       int x,y,step;
};
char map[205][205];
int n,m;
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};
bool visit[205][205];
int ans;
void bfs(node s)
{
     queue <node> Q;
     node now,next;
     Q.push(s);
    visit[s.x][s.y]=1;
     while(!Q.empty())
     {
       now=Q.front();
       Q.pop();
       for(int i=0;i<8;i++)
       {
           next=now;
          next.x=now.x+dx[i];
          next.y=now.y+dy[i];
          if(next.x>=0&&next.x<m&&next.y>=0&&next.y<n&&!visit[next.x][next.y]&&map[next.x][next.y]!='*')
          {
              next.step=now.step+1;
              Q.push(next);
              visit[next.x][next.y]=1;
              if(ans<next.step) ans=next.step;
          }
       }
     }
     printf("%d\n",ans);
     return ;
}
int main()
{
    memset(visit,0,sizeof(visit));
    node s;
    scanf("%d %d %d %d",&n,&m,&s.y,&s.x);
    s.x--,s.y--;
    s.step=0;ans=0;
    for(int i=m-1;i>=0;i--)
      scanf("%s",map[i]);
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(map[i][j]=='*') visit[i][j]=1;
    bfs(s);
    return 0;
}
