#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<queue>
#include<climits>
using namespace std;
const int M=405;
int map[M][M];
int f[M],d[M];
int now[M],dis[M],p[M],h[M],v[M];
int i,j,n,k;
int N,F,D,fi,di;
int flow;
bool flag;
void ISAP()
{
	flow=0;
    int aug;
    for(i=0;i<n;++i)
     now[i]=0;
     i=0;
     aug=INT_MAX;
     while(dis[i]<n)
     {
         h[i]=aug;
         flag=false;
         for(j=d[i];j<n;++j)
         {
             if(map[i][j]>0 && dis[j]+1==dis[i])
             {
                flag=true;
                now[i]=j;
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
                break;//找到允许弧，退出查找
             }
         }
         if(flag) continue;
         int MIN=n-1;//无允许弧，重标号
         for(j=0;j<n;++j)
          if(map[i][j]>0 && dis[j]<MIN) {k=j;MIN=dis[j];}
         now[i]=k;
         v[dis[i]]--;
         if(v[dis[i]]==0) break;
         dis[i]=MIN+1;
         v[dis[i]]++;
         if(i!=0){i=p[i];aug=h[i];}
     }
}
int main()
{
       while(scanf("%d%d%d",&N,&F,&D)!=EOF)
      {
		 memset(map,0,sizeof(map));	
		 memset(dis,0,sizeof(dis));
		 memset(p,0,sizeof(p));
		 memset(h,0,sizeof(h));
		 memset(v,0,sizeof(v));
			 n=N+N+F+D+2;
       for(i=1;i<=N;++i)
       {
            scanf("%d%d",&fi,&di);
            for(j=1;j<=fi;++j)
            {
				 scanf("%d",&f[j]);
				 map[f[j]][F+D+i]=1;//食物到牛连容量1的边 
			} 
			map[F+D+i][F+D+N+i]=1;//牛牛连 
			for(j=1;j<=di;++j)
             {
				scanf("%d",&d[j]);
			    map[i+F+D+N][d[j]+F]=1;//牛到饮料 
			 }  
       }
       for(i=1;i<=F;++i)
        map[0][i]=1;
       for(i=F+1;i<=F+D;++i)
	   map[i][n-1]=1; 
	    ISAP();
        printf("%d\n",flow);
	  }
        return 0;
}
