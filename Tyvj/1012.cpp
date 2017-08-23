#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int a[2001];
int f[2001][501];
int main()
{
    int i,j,N,M;
    scanf("%d%d",&N,&M);
    for(i=1;i<=N;i++)
    scanf("%d",&a[i]);
    f[0][0]=0;
   for(i=1;i<=M;++i) f[0][i]=-10000;
   for(i=0;i<=N;++i) f[i][M+1]=-10000;
  for(i=1;i<=N;++i)
{
  for(j=M;j>=1;--j)
  {
      f[i][j]=f[i-1][j-1]+a[i];
      f[i+j][0]=max(f[i+j][0],f[i-1][j+1]);
  }
  f[i][j]=max(f[i][j],f[i-1][j]); //由于上面倒着循环的 此时j为0 
  f[i][j]=max(f[i][j],f[i-1][j+1]); 
}
   printf("%d",f[N][0]);
   system("pause");
   return 0;
}
