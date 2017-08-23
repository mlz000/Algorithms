#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;
const int N=120;
int map[N][N];
int dis[N],d[N],pre[N],v[N],h[N]; 
int main()
{
        int i,j,k;
        int a,b,c; 
		int n,nn,np,nc,m;
		int aug,flow,MIN;
		bool flag;
		while(scanf("%d%d%d%d",&nn,&np,&nc,&m)!=EOF)
      {
	      for(i=1;i<=m;++i)
	       {
		      scanf("  (%d,%d)%d",&a,&b,&c);
		      map[a+2][b+2]+=c;
		   }
	       for(i=1;i<=np;++i)
	       {
		     scanf("  (%d)%d",&a,&c);
		     map[1][a+2]+=c;//1为源点 
		   }
	       for(i=1;i<=nc;++i)
	       {
		     scanf("  (%d)%d",&a,&c);
		     map[a+2][nn+2]+=c;//nn+2为汇点 
		   }
		   n=nn+2;
		   v[0]=n;
		   for(i=1;i<=n;++i)
		   d[i]=1;
		   aug=INT_MAX;
		   i=1;
		   flow=0;
		   while(dis[1]<n)
		   {
		       h[i]=aug;
		       flag=false;
		       for(j=d[i];j<=n;j++)
		       {
			      if(map[i][j]>0 && dis[j]+1==dis[i])
			      {
				     d[i]=j;//当前弧
					 flag=true;
					 if(map[i][j]<aug) aug=map[i][j];
					 pre[j]=i;//前驱
					 i=j;
					 if(i==n)
					 {
					     flow+=aug;
					  for(i=n;i!=1;i=pre[i])
					  {
					     map[pre[i]][i]-=aug;
					     map[i][pre[i]]+=aug;
					  }
					  aug=INT_MAX;
					 } 
					 break;
				  } 
			   }
		     if(flag) continue;
		     MIN=n-1;
		     for(j=1;j<=n;++j)
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
			 if(i!=1) {i=pre[i];aug=h[i];}//返回上一层，继续搜索 
		   }
		   printf("%d\n",flow); 
		          flow=0;
       memset(map,0,sizeof(map)); 
       memset(pre,0,sizeof(pre));
       memset(h,0,sizeof(h));
       memset(dis,0,sizeof(dis));
       memset(v,0,sizeof(v));
	  }         
      return 0;
} 
