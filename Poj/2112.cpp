#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
const int K=35,C=205;
int d[K+C][K+C],map[K+C][K+C];
int a[K+C],p[K+C];
int i,j,f,n;
int k,c,m;
int EK()
{
    int ans=0;
    queue<int>q;
    while(1)
    {
        memset(p,0,sizeof(p));
        memset(a,0,sizeof(a));
        a[0]=9999999;
        q.push(0);
        while(!q.empty())    
        {
            int t=q.front();
            q.pop();
            for(i=0;i<=n;++i)
            {
                if(!a[i] && map[t][i]>0)
                {
                  p[i]=t;
                  a[i]=min(a[t],map[t][i]);
                  q.push(i);
                }
            } 
        }
        if(a[n]==0) break;
        ans+=a[n];
        for(i=n;i!=0;i=p[i])
        {
           map[p[i]][i]-=a[n];
           map[i][p[i]]+=a[n];
        }
    }
    return ans;
}
void build(int x)
{
     memset(map,0,sizeof(map));
	 for(i=k+1;i<=n-1;++i)
      for(j=1;j<=k;++j)
       if(d[i][j]<=x) map[i][j]=1;
     for(i=1;i<=k;++i)
      map[i][n]=m;
     for(i=k+1;i<=n-1;++i)
      map[0][i]=1; 
}
int main()
{
      int l,r,mid,best,tmp;
      scanf("%d%d%d",&k,&c,&m);
      for(i=1;i<=k+c;++i)
       for(j=1;j<=k+c;++j)
        {
            scanf("%d",&d[i][j]);
            if(d[i][j]==0) d[i][j]=9999999;
        }
      for(i=1;i<=k+c;++i)
       for(j=1;j<=k+c;++j)
        for(f=1;f<=k+c;++f)
         if(d[j][i]+d[i][f]<d[j][f])
             d[j][f]=d[j][i]+d[i][f];
        l=0,r=10000,best=-1;
        n=k+c+1;
        while(l<=r)
        {
           mid=(l+r)>>1;
           build(mid);
           tmp=EK();
           if(tmp>=c)
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
