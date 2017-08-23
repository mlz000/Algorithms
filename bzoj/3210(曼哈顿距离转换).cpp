/*x＊ = x + y,y＊ = x 每 y,|x1 每 x2| + |y1 每 y2| = max{|x1∩ 每 x2∩|,|y1∩ 每 y2∩|}
|x1 每 x2| + |y1 每 y2| =
max{x1 每 x2,x2 每 x1} + max{y1 每 y2,y2 每 y1}
= max{x1 每 x2 + y1 每 y2,x2 每 x1 +y1 每 y2,x1 每 x2 + y2 每 y1,x2 每 x1 + y2 每 y1}
= max{|(x1 + y1)  - (x2 +y2)|,|(x1 每 y1) 每 (x2 每 y2)|}
=max{|x1∩ 每 x2∩|,|y1∩-y2∩|
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<climits>
#include<cmath>
using namespace std;
const int N=100005;
double x[N],y[N];
int n,a[N],b[N],d[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,-1},{-1,1}};
long long calc(int X,int Y)
{
      long long tmp=0ll;
      for(int i=1;i<=n;++i)
      tmp+=max(abs(X-a[i]),abs(Y-b[i]));
      return tmp;
}
int main()
{
      scanf("%d",&n);
      for(int i=1;i<=n;++i) 
      {
            scanf("%d%d",&a[i],&b[i]);
            x[i]=0.5*a[i]+0.5*b[i];
            y[i]=0.5*a[i]-0.5*b[i];
      }
      sort(&x[1],&x[n+1]),sort(&y[1],&y[n+1]);
      double mx=x[(n+1)/2],my=y[(n+1)/2];
      double mx2=mx+my,my2=mx-my;
      long long ans=calc(trunc(mx2),trunc(my2));
      for(int i=0;i<8;++i)
      ans=min(ans,calc(trunc(mx2+d[i][0]),trunc(my2+d[i][1])));
      printf("%lld",ans);
      return 0;
}
