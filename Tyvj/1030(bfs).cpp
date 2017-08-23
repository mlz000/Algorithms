#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
const int N=105;
using namespace std;
char map[N][N];
bool v[N][N];
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1}; 
int x,y,ans;
int i,j;
struct data
{
	int x;
	int y;
	int num;
};
void bfs(data s)
{
	queue <data> q;
	data now,next;
	q.push(s);
	v[s.x][s.y]=false;
	while(!q.empty())
	{
	   now=q.front();
	   q.pop();
	    for(i=0;i<8;++i)
	   {
	      next=now;
	      next.x=now.x+dx[i];
	      next.y=now.y+dy[i];
	      if(next.x>=0 && next.x<y && next.y>=0 && next.y<x && v[next.x][next.y])
	      {
		     next.num=now.num+1;
		     q.push(next);
		     v[next.x][next.y]=false;
		     if(ans<next.num) ans=next.num;
		  }
	   }
	}
}
int main()
{
	  memset(v,true,sizeof(v));
      data s;
      scanf("%d%d%d%d",&x,&y,&s.y,&s.x);
      s.x--;s.y--;s.num=0;ans=0;
      for(i=y-1;i>=0;--i)
       scanf("%s",map[i]);
       for(i=0;i<y;++i)
        for(j=0;j<x;++j)
         if(map[i][j]=='*') v[i][j]=false;
         bfs(s);
         printf("%d\n",ans);
         system("pause");
         return 0;
}
