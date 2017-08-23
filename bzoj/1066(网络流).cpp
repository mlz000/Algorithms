#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<climits> 
using namespace std;
const int N=25,M=N*N*2;
int S,T,tot,ans,h[M],d[M],dis[M],map[M][M],p[M],v[M];
char s[N];
bool can[N][N];
int Isap()
{
    int flow=0,i=0,j,k,aug=INT_MAX;
    bool flag;
    v[0]=tot;
    while(dis[0]<tot)
    {
        flag=false;
        h[i]=aug;
        for(j=d[i];j<tot;++j)
        {
            if(map[i][j]>0 && dis[j]+1==dis[i])
            {
                flag=true;
                d[i]=j;
                if(map[i][j]<aug)   aug=map[i][j];
                p[j]=i;
                i=j;
                if(i==T)
                {
                    flow+=aug;
                    for(i=T;i!=S;i=p[i])
                    {
                        map[p[i]][i]-=aug;
                        map[i][p[i]]+=aug;
                    }
                    aug=INT_MAX;
                }
                break;
            }
        }
        if(flag)    continue;
        int MIN=tot-1;
        for(j=0;j<tot;++j)  if(map[i][j]>0 && dis[j]<MIN)  k=j,MIN=dis[j];
        d[i]=k;
        v[dis[i]]--;
        if(!v[dis[i]]) break;
        dis[i]=MIN+1;   //gap
        v[dis[i]]++;  
        if(i!=0)  i=p[i],aug=h[i];
    }
    return flow;
}
int main()
{
    int n,m,d,i,j,k,l;
    scanf("%d%d%d",&n,&m,&d);
    int cnt=0;
    S=0;T=n*m*2+1;tot=T+1;
    for(i=1;i<=n;++i)
    {
      scanf("%s",s+1); 
      for(j=1;j<=m;++j) 
       if(s[j]-'0'>0) 
       {
          can[i][j]=true;
          map[(i-1)*2*m+j][(i*2-1)*m+j]=s[j]-'0';
          if(i<=d || j<=d || n-i+1<=d || m-j+1<=d)   map[(i*2-1)*m+j][T]=1000000;
       }
    }
    for(i=1;i<=n;++i)
    {
        scanf("%s",s+1);
        for(j=1;j<=m;++j)   if(s[j]=='L')   map[S][(i-1)*2*m+j]=1,++ans; 
    }
    for(i=1;i<=n;++i)
     for(j=1;j<=m;++j)  
     if(can[i][j])
      for(k=1;k<=n;++k) 
        for(l=1;l<=m;++l) 
         {
            if(i==k && j==l) continue;   
            {
              if(can[k][l]) 
              if(abs(i-k)+abs(j-l)<=d)   map[(i*2-1)*m+j][(k-1)*2*m+l]=1000000; 
            }
         }
    ans=ans-Isap();
    printf("%d",ans);
    return 0;
}
