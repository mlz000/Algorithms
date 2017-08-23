#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int N=1005;
bool v[N][N];
struct data
{
   int x;
   int y;
   int num;
};
int a,b,x,y,n,ans;
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
void bfs(data s)
{
    int i;  
    queue<data> q;
    data now,next; 
    q.push(s);
    while(!q.empty())
    {
	   now=q.front();
	   q.pop();	
      for(i=0;i<4;++i)
     {
	   next.x=now.x+dx[i];
	   next.y=now.y+dy[i];
	   if(next.x>=1 && next.x<=a && next.y>=1 && next.y<=b && !v[next.x][next.y] && now.num<n)
	   {
	     v[next.x][next.y]=true;
	     next.num=now.num+1;
	     ans++;
	     q.push(next);
	   }
	 }  
	}
}
int main()
{
    scanf("%d%d%d%d%d",&a,&b,&x,&y,&n);
    data s;
    s.x=x;s.y=y;
    bfs(s);
    printf("%d",ans);
    return 0;
}

