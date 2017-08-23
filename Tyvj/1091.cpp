#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#define abs(a,b) (a>b)?(a-b):(b-a) 
using namespace std;
const int M=1010;
int a[M];
long long f[M][M];
int main()
{
     int i,j,k,n;
	 long long ans;
     scanf("%d",&n);
     for(i=1;i<=n;++i)
       scanf("%d",&a[i]);
	 for(i=1;i<=n;++i)
	 f[i][0]=1;
	 for(i=1;i<=n;++i)
	 {
		for(j=1;j<=i-1;j++)
	    {
		  k=abs(a[j],a[i]);
		  f[i][k]=f[j][k]+f[i][k];
		  if(k!=0) f[i][k]++;		  
		}
	 } 
	 for(i=1;i<=n;++i)
	  for(j=0;j<=1000;j++)
	   ans=ans+f[i][j];

	 printf("%d",ans);
	 system("pause");
	 return 0;
     
}
