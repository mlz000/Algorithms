#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=505;
int a[N],b[N],f[N][N],path[N][N],c[N];
int main()
{
	int n1,n2;
	scanf("%d",&n1);
	for(int i=1;i<=n1;++i)	scanf("%d",&a[i]);
	scanf("%d",&n2);
	for(int i=1;i<=n2;++i)	scanf("%d",&b[i]);
	int ans=0,ansi,ansj;
	int i,j;
	for(i=1;i<=n1;++i)
	{
		int maxj=0;
		int MAX=0;
		for(j=1;j<=n2;++j)
		{
			f[i][j]=f[i-1][j];
			path[i][j]=-1;
			if(b[j]<a[i])
			{
				if(f[i-1][j]>MAX)
				{
					MAX=f[i-1][j];
					maxj=j;
				}
			}
			else if(b[j]==a[i])
			{
				f[i][j]=MAX+1;
				path[i][j]=maxj;
			}
			if(f[i][j]>ans)
	    	{
				ansi=i,ansj=j;
				ans=f[i][j];
		    }
		}
	}
	printf("%d\n",ans);
	int now=ans;
	while(now)
	{
		if(path[ansi][ansj]!=-1)	c[now--]=b[ansj],ansj=path[ansi][ansj];
		ansi--;
	}
	for(int i=1;i<=ans;++i)	printf("%d ",c[i]);
	return 0;
}



