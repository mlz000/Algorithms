#include<cstdio>
#include<cmath> 
#include<cstring> 
#include<iostream>
#include<algorithm> 
using namespace std;
const int N=1005,M=53; 
int f[N][M][M]; 
int a[N]; 
int main()
{
    int i,j,k,l,r,n; 
    memset(f,0x3f,sizeof(f)); 
    scanf("%d%d%d",&l,&r,&n);
    f[0][l][r]=0; 
    for(i=1;i<=n;++i)
     scanf("%d",&a[i]);
    for(i=0;i<n;++i)
     for(j=4;j<=51;++j)
      for(k=0;k<=47;++k) 
      {
        if(f[i][j][k]==0x3f3f3f3f) continue; 
        for(l=a[i+1];l<=a[i+1]+8 && l<=51;++l)
         f[i+1][l][k]=min(f[i+1][l][k],f[i][j][k]+(int)sqrt((double)abs(l-j)*1.000)); 
        for(l=a[i+1];l>=a[i+1]-8 && l>=0;--l)
         f[i+1][j][l]=min(f[i+1][j][l],f[i][j][k]+(int)sqrt((double)abs(l-k)*1.000)); 
      }  
    int ans=10000000;  
    for(j=4;j<=51;++j)
     for(k=0;k<=47;++k)
      ans=min(ans,f[n][j][k]);  
    printf("%d",ans);
    //system("pause");  
    return 0; 
} 
