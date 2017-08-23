#include<cstdio> //first hungary question
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=50005;
int map[105][105];
struct data
{
    int v;
    int next;
}edge[N];
int head[N];
int n,m,cnt;
bool used[N];
int li[N];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void add(int u,int v)
{
    edge[cnt].v=v;
    edge[cnt].next=head[u];
    head[u]=cnt++; 
}
bool can(int t)
{
    for(int p=head[t];p!=-1;p=edge[p].next)
    {
	   int v=edge[p].v;
	   if(!used[v])
	   {
		  used[v]=true; 
	     if(!li[v] || can(li[v]))
	     {
		   li[v]=t;
		   return true;
		 }
	   }
	}
    return false;
}
int MAX()
{
     int ans=0;
     int i;
     memset(li,0,sizeof(li));
     for(i=1;i<=n*n;++i)
     {
	   memset(used,false,sizeof(used));	 
	  if(can(i)) ans++;
	 }
	 return ans;
}
int main()
{
      memset(head,-1,sizeof(head));
      int i,j,k;
      scanf("%d%d",&n,&m);
      int x,y;
      memset(map,true,sizeof(map));
      for(i=1;i<=m;++i)
       {
	     scanf("%d%d",&x,&y);
	     map[x][y]=false;
	   }
	  int num1,num2;
      for(i=1;i<=n;++i)
       for(j=1;j<=n;++j)
        if(map[i][j])
       {
	     num1=(i-1)*n+j;
	     for(k=0;k<4;++k)
	     {
		   int a=i+dx[k];
		   int b=j+dy[k];
		   if(a>=1 && a<=n && b>=1 && b<=n && map[a][b])
		   {
			   num2=(a-1)*n+b;
		       add(num1,num2);
		   }
		 }
	   }
	   printf("%d\n",MAX()/2);
	   return 0;
}
