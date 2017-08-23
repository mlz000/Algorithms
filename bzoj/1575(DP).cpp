#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn=101,inf=2000000000;
int f[maxn][maxn],a[maxn];
int t,tmp,i,j,k,l,m,n;
bool flag;
int main() {
  cin>>n>>m;
  for (i=1;i<=n;i++) cin>>a[i];
  for (i=1;i<=n;i++)
    for (j=1;j<=i-1;j++)
      f[i][1]+=2*abs(a[i]-a[j]);
  for (i=2;i<=n;i++)
    for (j=2;j<=i;j++) {
      f[i][j]=inf;
      for (k=1;k<=i-1;k++) {
        tmp=0;
        for (l=k+1;l<=i-1;l++) tmp+=abs(2*a[l]-a[k]-a[i]);
        f[i][j]=min(f[k][j-1]+tmp,f[i][j]);
      }
    }
  for (k=1;k<=n;k++) {
    flag=false;t=inf;
    for (i=1;i<=n;i++) {
      tmp=0;
      for (j=i+1;j<=n;j++)
        tmp+=2*abs(a[i]-a[j]);
      if (f[i][k]+tmp<=m) {
        flag=true;
        t=min(t,f[i][k]+tmp);
      }
    }
    if (flag) {cout<<k<<' '<<t<<endl;break;}
  }
  return 0;
}
