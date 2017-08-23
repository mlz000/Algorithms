#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	x=max(x,y);
	int z=7-x;
	if(z==6)	printf("1/1");
	else 
	{
		int t1=__gcd(z,6);
		printf("%d/%d\n",z/t1,6/t1);
	}
	return 0;
}
