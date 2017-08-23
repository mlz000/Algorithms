#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=52;
int a[N],b[N],h[N];
long long f[N][N];
bool link[N][N];
char s[N][N];
int main()
{
	int i,j,k,n,r;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	scanf("%d",&b[i]);
	for(i=1;i<=n;++i)
	scanf("%d",&a[i]);
	for(i=1;i<=n;++i)
	scanf("%d",&h[i]);
	for(i=0;i<n;++i)
	 for(j=0;j<n;++j)
	 {
		 scanf("%c",&s[i][j]);
		 if(s[i][j]=='Y') link[i+1][j+1]=true;
	     else link[i+1][j+1]=false;
	 }
	 scanf("%d",&r);
	 for(i=1;i<=n;++i)
	  
	 system("pause");
	 return 0;
}
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
