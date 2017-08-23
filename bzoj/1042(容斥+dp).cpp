#include<cstdio>//Èİ³âÔ­Àí+±³°ü 
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=100005;
int c[5],d[5],tot,s;
long long f[N];
long long F(int x)      
{
      if(x>=0)   return f[x];
      return 0;
}
int main()
{
      int i,j,k;
      long long ans;            
      f[0]=1;
      for(i=1;i<=4;++i) 
      {
            scanf("%d",&c[i]);
            for(j=c[i];j<=100000;++j)    f[j]+=f[j-c[i]];  
      }
      scanf("%d",tot);
      while(tot--)
      {
            for(i=1;i<=4;++i) scanf("%d",&d[i]),d[i]=(d[i]+1)*c[i];
            scanf("%d",&s);
            ans=F(s);
            for(i=1;i<=4;++i) ans-=F(s-d[i]);
            for(i=1;i<=4;++i)
             for(j=i+1;j<=4;++j)
              ans+=F(s-d[i]-d[j]);
            for(i=1;i<=4;++i)
             for(j=i+1;j<=4;++j)
              for(k=j+1;k<=4;++k)
               ans-=F(s-d[i]-d[j]-d[k]);
            ans+=F(s-d[1]-d[2]-d[3]-d[4]);
            cout<<ans<<endl;          
      }
      return 0;
}
