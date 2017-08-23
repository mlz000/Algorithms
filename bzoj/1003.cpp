#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<climits>
using namespace std;
const int N=105,M=25;
const int MAX=999999; 
int data[M][M],cost[N][N];
bool s[M][N];
int f[N]; 
int n,m,k,e,d;
int dis[M];
bool can[M],v[M];
void spfa(int o,int p)
{
     int l; 
	 memset(v,false,sizeof(v)); 
	 queue<int>q;
	 q.push(1);
	 for(l=2;l<=m;++l)
	  dis[l]=MAX;
	  dis[1]=0;
		  while(!q.empty())
		  {
		    int x=q.front();
		    v[x]=false;
		    q.pop();
		    for(l=1;l<=m;++l)
		    {
			  if(can[l] && dis[x]+data[x][l]<dis[l])
			  {
					dis[l]=dis[x]+data[x][l];
			        if(v[l]==false)
			         {
					    v[l]=true;
					    q.push(l);
					 }
			  }
			}
		  } 
	cost[o][p]=dis[m];
} 
int main()
{ 
      scanf("%d %d %d %d",&n,&m,&k,&e);
      int p,a,b,c;
      int i,j,l;
      for(i=1;i<=m;++i)
       for(j=1;j<=m;++j)
        data[i][j]=MAX;
      for(i=1;i<=e;++i)
       {
	     scanf("%d%d%d",&a,&b,&c);
	     data[a][b]=c;
	     data[b][a]=c;
	   }
       scanf("%d",&d);
       memset(s,true,sizeof(s));
       for(i=1;i<=d;++i)
       {
	     scanf("%d%d%d",&p,&a,&b);
	     for(j=a;j<=b;++j)
	      s[p][j]=false;
	   }
	for(i=1;i<=n;++i)
     {
	   memset(can,true,sizeof(can));
	   for(j=i;j<=n;++j)
       {
	      for(l=1;l<=m;++l)
		     if(!s[l][j]) can[l]=false;
		  spfa(i,j);  
       }
	 }
	  for (i=1;i<=n;i++) f[i]=MAX;
	  f[0]=-k;
      for(i=1;i<=n;++i)
       for(j=0;j<=i-1;++j)
       {
	      f[i]=min(f[i],f[j]+cost[j+1][i]*(i-j)+k); 
	   }
	   printf("%d",f[n]);
	   //system("pause");
	   return 0;
}
