#include<iostream>
#include<stdio.h> 
using namespace std;
int n,m,mid;
int a[101],b[101];
int f[101][101];
int solve()
{
	int i,j,k;
	memset(f,-1,sizeof(f));
	for(j=0;j<=m&&j*a[1]<=mid;j++)   //j有可能取不到m 
			f[1][j]=(mid-j*a[1])/b[1];
	for(i=1;i<=n;i++)
		for(j=0;j<=m;j++)
		{
			for(k=0;k*a[i]<=mid&&k<=j;k++)
				if(f[i-1][j-k]!=-1)
			{
				f[i][j]=max(f[i][j],f[i-1][j-k]+(mid-k*a[i])/b[i]);
			}
		}
	if(f[n][m]>=m) return 1;
	else return 0;
}
void read(){
	int i,j,k,l,r;
	int t;
	int maxx;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		maxx=0;
		for(i=1;i<=n;i++)
		{
		    scanf("%d%d",&a[i],&b[i]);
			maxx=max(max(maxx,a[i]),b[i]);
		}
		l=0;r=maxx*m*2;	
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(solve()) r=mid-1;
			else
				l=mid+1;
		}
		printf("%d\n",l);	
	}
}
int main()
{
	read();
	return 0;
}
