#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
int x[105],y[105];
int main()
{
	int n;
	int sum1=0,sum2=0,cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&x[i],&y[i]);
		sum1+=x[i];
		sum2+=y[i];
		if(((x[i]&1) && !(y[i]&1))||((y[i]&1) && !(x[i]&1))) ++cnt;
	}
	if((sum1+sum2)%2==1)	printf("-1");
	else 
	{
		if(sum1%2==0 && sum2%2==0)	printf("0");
		else
		{
			if(cnt>0)	printf("1");
			else printf("-1");
		}
	}
	return 0;
}
