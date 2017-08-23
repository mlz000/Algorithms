#include<cstdio>
#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
const int M=1005,N=105;
int map[N][N];
int num[M],v[N],pre[N],p[M],dis[N],d[N],h[N];
int main()
{
     int i,j,k,m,n,nn;
     int a,b,c;
     int flow=0,aug,min;
     bool flag;
     scanf("%d%d",&m,&n);
        for(i=1;i<=m;++i) 
        {
           scanf("%d",&c);
           num[i]+=c;
        }
        for(i=1;i<=n;++i)
        {
           scanf("%d",&nn);
           for(j=1;j<=nn;++j)
           {
              scanf("%d",&a);
              if(p[a]==0) 
              map[0][i]+=num[a];
              else map[p[a]][i]=INT_MAX-10000;
              p[a]=i;
           }
           scanf("%d",&c);
           map[i][n+1]+=c;
        }
         n=n+2; 
         v[0]=n;
         for(i=0;i<n;++i)
          d[i]=0;
          i=0;    
          aug=INT_MAX;
         while(dis[0]<n)
         {
             h[i]=aug;   
             flag=false;
             for(j=d[i];j<n;++j)
             {
                 if(map[i][j]>0 && dis[j]+1==dis[i])
                   {
                        d[i]=j;
                        flag=true;
                        if(map[i][j]<aug) aug=map[i][j];
                        pre[j]=i;
                        i=j;
                        if(i==n-1)
                        {
                            flow+=aug;
                            for(i=n-1;i!=0;i=pre[i])
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
             min=n-1;
             for(j=0;j<n;++j)
              if(map[i][j]>0 && dis[j]<min) 
              {
                 min=dis[j];
                 k=j;
              } 
              d[i]=k;
              v[dis[i]]--;
              if(v[dis[i]]==0) break;
              dis[i]=min+1;
              v[dis[i]]++;
              if(i!=0) {i=pre[i];aug=h[i];}
         }        
         printf("%d\n",flow);
         //system("pause"); 
         return 0;    
} 
