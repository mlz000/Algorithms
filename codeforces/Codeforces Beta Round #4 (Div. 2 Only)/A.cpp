#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
const int N=100005;
int main()
{
	int w;
	scanf("%d",&w);
	if((w%2==0) && w>2)	printf("YES\n");
	else printf("NO\n");
	return 0;
}

