#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int M=205,MOD=1000000007;
typedef long long ll;
ll c[M][M],ans[100][M],stk[100];
inline ll pw(ll x,ll y)
{
      ll t=1ll;
      for(;y;y>>=1)
      {
            if(y&1)    t=(t*x)%MOD;
            x=(x*x)%MOD;       
      }
      return t;
}
int main()
{
      int top=0,i,j,k,n,m;
      c[0][0]=1;
      for(i=1;i<=200;++i)
      {
            c[i][0]=1;
            for(j=1;j<=200;++j)     c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
      }
      scanf("%d%d",&n,&m);
      for(i=0;i<=m;++i) ans[1][i]=m;
      while(n)
      {
            stk[++top]=n;
            if(n&1)  n--;
            else n>>=1;   
      } 
      reverse(stk+1,stk+top+1);
      for(i=2;i<=top;++i)
      {
            for(j=0;j<=m;++j) ans[i][j]=ans[i-1][j];
            if(stk[i]==stk[i-1]+1)
            {
                 for(j=0;j<=m;++j)  ans[i][j]=(ans[i][j]+(pw(stk[i],j)*pw(m,stk[i]))%MOD)%MOD;
                 continue;   
            }
            for(j=0;j<=m;++j)
             for(k=0;k<=j;++k)
             {
                   ll tmp=pw(m,stk[i-1]);
                   tmp=(tmp*c[j][k])%MOD;
                   tmp=(tmp*pw(stk[i-1],j-k))%MOD;
                   tmp=(tmp*ans[i-1][k])%MOD;
                   ans[i][j]=(ans[i][j]+tmp)%MOD;
             }
      }
      printf("%lld",ans[top][m]);
	return 0;
}
