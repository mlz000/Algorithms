#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=300;
long long f[N][N/2];
int main()
{
        int i,j,n;
         for(i=1;i<=250;++i)
          for(j=i;j>=i/2;--j)
            f[i][j]=1;//将i分为最大为j的数，当j>i/2时只有本身一种 
         for(i=2;i<=250;++i)
	       for(j=i/2;j>=1;--j)
	       {
               if(i-2*j==0) f[i][j]++;
		       else f[i][j]=f[i-j*2][j]+f[i][j+1];
		   }
       while(scanf("%d",&n)&&n)
       { 
	       printf("%d %I64d\n",n,f[n][1]);
	   }
        //system("pause");
        return 0;
}
