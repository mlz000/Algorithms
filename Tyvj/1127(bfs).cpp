#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int M=55,N=85;
char a[M][N];
int b[M][N];
int m,n,ans;
bool v[M][N];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
struct data
{
   int x;
   int y;
};
void bfs(int x,int y)
{
    int i;  
    queue<data> q;
    data s,now,next; 
    s.x=x;s.y=y;
    q.push(s);
    while(!q.empty())
    {
	   now=q.front();
	   q.pop();	
      for(i=0;i<4;++i)
     {
	   next.x=now.x+dx[i];
	   next.y=now.y+dy[i];
	   if(next.x>=1 && next.x<=m && next.y>=1 && next.y<=n && !v[next.x][next.y] && b[next.x][next.y]!=0)
	   {
	     v[next.x][next.y]=true;
	     b[next.x][next.y]=0;
	     q.push(next);
	   }
	 }  
	}
	ans++;
}
int main()
{
   int i,j;
   scanf("%d%d",&m,&n);
   for(i=1;i<=m;++i)
    scanf("%s",a[i]);
   for(i=1;i<=m;++i)
    for(j=0;j<n;++j)
     b[i][j+1]=a[i][j]-'0'; 
    for(i=1;i<=m;++i)
     for(j=1;j<=n;++j)
      if(b[i][j]>=1 && b[i][j]<=9) bfs(i,j);
    printf("%d",ans);
    return 0;
}

