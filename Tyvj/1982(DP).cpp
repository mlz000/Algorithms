#include<cstdio> 
#include<iostream>
#include<algorithm>
#include<queue> 
#include<cstring> 
using namespace std; 
const int N=100;
int at[N],de[N],f[N][N][N]; 
int main()
{ 
      int i,j,k,x,y,n,a,b; 
      scanf("%d%d%d",&n,&a,&b);
      for(i=1;i<=a;++i)
       scanf("%d",&at[i]);
      for(i=1;i<=b;++i)
       scanf("%d",&de[i]);
      sort(&at[1],&at[a+1]);
      sort(&de[1],&de[b+1]);
      memset(f,0x3f,sizeof(f));
      f[0][0][0]=0; 
      for(i=1;i<=n;++i)
       for(j=1;j<=a && a-j>=n-i;++j)
        for(k=1;k<=b && b-k>=n-i;++k)
        {
          f[i][j][k]=min(f[i][j][k],min(f[i][j-1][k],f[i][j][k-1]));//不选当前武器或防具 
          for(x=i-1;x<=j-1;++x)
           for(y=i-1;y<=k-1;++y)
            f[i][j][k]=min(f[i][j][k],f[i-1][x][y]+(at[j]-de[k])*(at[j]-de[k])); 
        }   
      printf("%d",f[n][a][b]);  
      //system("pause");  
      return 0; 
} 

