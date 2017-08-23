#include<iostream>
#include<stack> 
#include<cstdio> 
#include<cstring> 
#include<climits> 
#include<cmath> 
#include<algorithm>
using namespace std; 
const int N=1005;
int a[N][N]; 
int main()
{
     int i,j,n; 
     scanf("%d",&n);     
     double ans=0.0; 
     long long tot=n*(n+1)/2;//平方为所有可能 
     for(i=1;i<=n;++i)
      for(j=1;j<=n;++j) 
       {
         scanf("%d",&a[i][j]); 
         ans+=(double)(a[i][j])*(double)(n-i+1)/(double)(tot)*(double)(n-j+1)/(double)(tot)*(double)(i*j); 
       } 
	 printf("%.lf",trunc(ans)); 
     //system("pause"); 
     return 0;
}

