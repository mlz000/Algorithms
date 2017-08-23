#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int a[101]; 
int f[101][101];
int main()
{
    int i,j,k,n,MAX;
    scanf("%d",&n); 
    for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    for(i=1;i<n;i++)
     f[i][i+1]=0;
    for(i=n-2;i>=1;i--)
     for(j=i+2;j<=n;j++)
  {
     MAX=0x7ffff;                   
     for(k=i+1;k<=j-1;k++)
    {
       if(f[i][k]+f[k][j]+a[i]*a[k]*a[j]<MAX) MAX=f[i][k]+f[k][j]+a[i]*a[k]*a[j];
       f[i][j]=MAX;
    }
  } 
    printf("%d",f[1][n]);
    //system("pause");
    return 0;
} 
