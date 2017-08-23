#include<cstdio> 
#include<climits> 
#include<queue>
#include<iostream>
#include<string> 
#include<cstring>
#include<algorithm>
using namespace std;
const int N=105;
char map[N][N];
int a[N][N];
int dx[8]={2,2,1,1,-1,-1,-2,-2};
int dy[8]={1,-1,2,-2,-2,2,-1,1};
bool v[N][N];
int m,n,ans;
struct data 
{
  int x;
  int y;
  int num;
};
void bfs(data s)
{
   int i;
   data now,next;
   queue<data> q;
   q.push(s);
   v[s.x][s.y]=true;
   while(!q.empty())
   {
      now=q.front();
      q.pop();
      for(i=0;i<8;++i)
      {
	    next=now;
	    next.x=now.x+dx[i];
		next.y=now.y+dy[i];
		if(next.x>=1 && next.x<=m && next.y>=1 &&next.y<=n && !v[next.x][next.y]) 
		{
			v[next.x][next.y]=true;
			next.num=now.num+1;
			q.push(next);
			if(a[next.x][next.y]==1) ans=next.num;
		}
	  }
   }
}
int main()
{
	memset(a,-1,sizeof(a));
	data s;
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;++i)
	 scanf("%s",map[i]);
	for(i=0;i<m;++i)
	 for(j=0;j<n;++j)
     {
	        if(map[i][j]=='*') a[i+1][j+1]=0;//ÕÏ°­ 
		    if(map[i][j]=='H') a[i+1][j+1]=1;//²Ý 
	        if(map[i][j]=='K') {s.x=i+1;s.y=j+1;a[i+1][j+1]=2;}//Âí 
	 }
     bfs(s);
	printf("%d\n",ans);
	return 0; 
}
