#include<cstdio>//Çø¼ädp
#include<string.h>
#include<iostream>
#include<algorithm>
#define abs(a,b) (a>b)?(a-b):(b-a)
using namespace std;
int _t[100];
int a[2004],f[1010][1010];
int main()
{
      int i,j,l,k,n,m; 
	  scanf("%d",&n);
	  for(i=1;i<=n;++i)
		scanf("%d",&a[i]); 
		  for(i=1;i<=n;++i)
		   f[i][i]=a[i];
	for(l=1;l<=n-1;++l) 
	  for(i=1;i<=n-l;++i)
    {
         j=i+l;	
		 f[i][j]=(abs(a[i],a[j]))*(j-i+1);		
	    for(k=i;k<=j-1;++k)
      {
	    f[i][j]=max(f[i][k]+f[k+1][j],f[i][j]);
	  }
	}
	  printf("%d",f[1][n]);
	  //system("pause");
	  return 0;
}
