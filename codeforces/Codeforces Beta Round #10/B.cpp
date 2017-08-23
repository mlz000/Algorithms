#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,k;
bool v[105][105];
bool check(int i,int j,int x)
{
	for(int p=j;p<=j+x-1;++p)	if(v[i][p])	return false;
	return true;
}
int calc(int i,int j,int x)
{
	int tmp=0;
	for(int p=j;p<=x+j-1;++p)
	tmp+=fabs(i-(k+1)/2)+fabs(p-(k+1)/2);
	return tmp;
}
int main()
{
	scanf("%d%d",&n,&k);
	while(n--)
	{
		bool flag=false;
		int x;
		scanf("%d",&x);
		int MIN=100000000;
		int ansx,ansy;
		for(int i=1;i<=k;++i)
		{
			for(int j=1;j<=k;++j)
			{
				if(j+x-1>k)	break;
				{
					if(!check(i,j,x))	continue;
					int val=calc(i,j,x);flag=true;
					if(val<MIN)
					{
						MIN=val;
						ansx=i,ansy=j;
					}
				}
			}
		}
		if(!flag)	printf("-1\n");
		else 
		{
			printf("%d %d %d\n",ansx,ansy,ansy+x-1);
			for(int j=ansy;j<=ansy+x-1;++j)	v[ansx][j]=true;	
		}
	}
	return 0;
}

