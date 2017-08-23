#include<cstdio>
#include<queue>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1005;
int data[N][N];
int dis[N];
bool v[N];
int n;
void spfa()
{
       queue<int>q;
       memset(v,false,sizeof(v));
       memset(dis,-1,sizeof(dis));
       q.push(1);
       dis[1]=0;
       while(!q.empty())
       {
	     int x=q.front();
	     v[x]=false;
	     int i;
	     q.pop();
	     for(i=1;i<=n;++i)
	     {
		    if(dis[x]+data[x][i]>dis[i]) 
		    {
				dis[i]=dis[x]+data[x][i];
		        if(!v[i])
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
     int i,j;
     scanf("%d",&n);
     int a,b,c;
     for(i=1;i<=n;++i)
      for(j=1;j<=n;++j)
       data[i][j]=-999999;
     for(i=1;i<n;++i)
      {
		  scanf("%d%d%d",&a,&b,&c);
          if(b==0 && c==0) data[a][n]=1;
          if(b!=0 && c==0) data[a][b]=data[a][n]=1;
          if(b==0 && c!=0) data[a][c]=data[a][n]=1;
          if(b!=0 && c!=0) data[a][b]=data[a][c]=1;
	  }
	  spfa();
	  printf("%d",dis[n]);
	  return 0;

}
