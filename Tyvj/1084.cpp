#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N=26;
int a[N][N],f1[N][N],f2[N][N];
int main()
{
	int i,j,n,m;
	int x,y;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	 for(j=1;j<=i;++j)
	  scanf("%d",&a[i][j]);
	scanf("%d%d",&x,&y);
	for(i=1;i<=x;++i)
	 for(j=1;j<=i;++j)
	  f1[i][j]=max(f1[i-1][j],f1[i-1][j-1])+a[i][j];
    for(i=n;i>=x;--i)
	 for(j=1;j<=i;++j)
	  f2[i][j]=max(f2[i+1][j],f2[i+1][j+1])+a[i][j];
	printf("%d\n",f1[x][y]+f2[x][y]-a[x][y]);
	//system("pause");
	return 0;	    
}
