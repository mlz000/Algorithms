#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn=11,pp=20140518;
typedef long long matrix[maxn][maxn];
matrix a,b,c,d;
long long mi[maxn],fac[maxn];
int i,j,k,m,ww,zz;
long long ans,n;

void mov(matrix a,matrix b) {
  for (int i=1;i<=m;i++)
    for (int j=1;j<=m;j++)
      a[i][j]=b[i][j];
}

void mul(matrix a,matrix b,matrix c) {
  for (int i=1;i<=m;i++)
    for (int j=1;j<=m;j++)
      c[i][j]=0;
  for (int i=1;i<=m;i++)
    for (int j=1;j<=m;j++)
      for (k=1;k<=m;k++)
        c[i][j]=(c[i][j]+a[i][k]*b[k][j])%pp;
}

void work(long long n) {
  int i,j,k;
  if (!n) {
    for (i=1;i<=m;i++)
      for (j=1;j<=m;j++)
        c[i][j]=(i==j);
    return;
  }
  work(n>>1);
  mov(a,c);mov(b,c);mul(a,b,c);
  if (n & 1) {
    mov(a,c);mov(b,d);
    mul(a,b,c);
  }
}

int main() {
  scanf("%d",&ww);
  for (zz=1;zz<=ww;zz++) {
    scanf("%lld%d",&n,&m);
    memset(d,0,sizeof(d));
    for (i=1;i<=m;i++) d[i][1]=1;
    for (i=2;i<=m;i++) {
      d[i-1][i]=m+2-i;
      for (j=i;j<=m;j++) d[j][i]++;
    }
    printf("Case #%d: ",zz);
    if (n<=m) {
      ans=1;
      for (i=1;i<=n;i++) ans=ans*(m+1)%pp;
      cout<<ans<<endl;
    }
    else {
      work(n-m);
      mi[0]=fac[0]=1;
      for (i=1;i<=m+1;i++) {
        mi[i]=mi[i-1]*(m+1)%pp;
        fac[i]=fac[i-1]*i%pp;
      }
      memset(a,0,sizeof(a));
      a[1][m]=fac[m+1];
      for (i=m-1;i>=1;i--) {
        a[1][i]=1;
        for (j=1;j<=i;j++) a[1][i]=a[1][i]*(m+2-j)%pp;
        a[1][i]=a[1][i]*mi[m-i-1]%pp*i%pp;
      }
      mov(b,c);
      mul(a,b,c);
      ans=0;
      for (i=1;i<=m;i++) ans=(ans+c[1][i])%pp;
      cout<<ans<<endl;
    }
  }
  //system("pause");
  return 0;
}
