#include<cstdio>
#include<iostream>
#include<string> 
#include<algorithm>
using namespace std;
const int N=30;
int a[N][N];
bool f[N][N][100]; 
int main()
{
	int i,j,n,k; 
    scanf("%d",&n);
	for(i=1;i<=n;++i)
	 for(j=1;j<=i;++j)
	  {
		scanf("%d",&a[i][j]);
	    a[i][j]=a[i][j]%100; 
	  } 
	  f[1][1][a[1][1]]=true; 
	 for(i=2;i<=n;++i)
	  for(j=1;j<=i;++j)
	   for(k=0;k<=99;++k) 
	  {
	    if(f[i-1][j-1][k]) f[i][j][(k+a[i][j])%100]=true;
		if(f[i-1][j][k]) f[i][j][(k+a[i][j])%100]=true;
	  }  
	  int ans; 
	  bool flag=false; 
		 for(k=99;k>=0;--k)
		{
		  for(i=1;i<=n;++i) 
	        {
				if(f[n][i][k]) {flag=true;ans=k;break;}
			} 
	     if(flag) break;
	    } 
	  printf("%d",ans);
	  //system("pause") ;
	  return 0; 
} 
