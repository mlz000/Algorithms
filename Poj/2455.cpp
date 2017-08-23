#include<cstdio>
#include<iostream>
#include<algorithm>
#include<climits>
#include<cstring>
using namespace std;
const int N=205;
int f[N][N];
int h[N],d[N],dis[N],v[N],p[N];
int map[N][N];    
int nn,n,P,t;
int i,j,k;
bool flag;
struct data 
{
      int u;
      int v;
      int w;
}
edge[N*N];
int isap()
{
	  memset(h,0,sizeof(h));
	  memset(dis,0,sizeof(dis));
	  memset(v,0,sizeof(v));
	  memset(p,0,sizeof(p));
	  int flow=0;
      for(i=0;i<n;++i)
	   d[i]=0;
	   i=0;
	   v[0]=n;
	  int aug=INT_MAX;
	  while(dis[0]<n)
	  {
	     flag=false;
	     h[i]=aug;
	     for(j=d[i];j<n;++j)
	     {
		   if(map[i][j]>0 && dis[j]+1==dis[i])
		   {
		       flag=true;
		       d[i]=j;
		       if(map[i][j]<aug) aug=map[i][j];
               p[j]=i; 
		       i=j;
		       if(i==n-1)
		       {
			      flow+=aug;
				  for(i=n-1;i!=0;i=p[i])
				  {
				    map[p[i]][i]-=aug;
				    map[i][p[i]]+=aug;
				  }
				  aug=INT_MAX;
			   }
			   break;
		   }
		 }
	     if(flag) continue;
	     int MIN=n-1;
	     for(j=0;j<n;++j)
            if(map[i][j]>0 && dis[j]<MIN)
             {
               MIN=dis[j];
               k=j;
             }
         d[i]=k;
		 v[dis[i]]--;
		 if(v[dis[i]]==0) break;
		 dis[i]=MIN+1;
		 v[dis[i]]++;	 
	     if(i!=0) {i=p[i];aug=h[i];}
	  }  
      return flow;
}
void init(int x)
{
    memset(map,0,sizeof(map));
     for(i=1;i<=P;++i)
      if(edge[i].w<=x) 
      {
			map[edge[i].u][edge[i].v]++;
			map[edge[i].v][edge[i].u]++;
	  }
	  map[0][1]=10000;
	  map[nn][nn+1]=10000;
}
int main()
{
     int a,b,c;
     int l=0,r=0,mid,best;
     scanf("%d%d%d",&nn,&P,&t); 
	 for(i=1;i<=P;++i)
	    {
			 scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
			 if(r<edge[i].w) r=edge[i].w;
		}
	  n=nn+2;//¹²n¸öµã 
      while(l<=r)
      {
	     mid=(l+r)>>1;
	     init(mid);	  
	     int tmp=isap();	     
	     if(tmp>=t)
	     {
		   best=mid;
		   r=mid-1;
		 }
		 else l=mid+1; 
	  }
     printf("%d\n",best);
     //system("pause");
     return 0;
}
