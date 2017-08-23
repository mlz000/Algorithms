#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
	int n,i,j,x[1006],a,b;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",x+i);
	a=b=0;
	for(i=1;i<n;i++)
	{
		a=b=0;
		for(j=i+2;j<=n;j++) 
			if (x[j]>x[i] && x[j]>x[i+1] || x[j]<x[i] && x[j]<x[i+1]) a++;
			  else b++;
		if(a!=0 && b!=0) break;
	}
	if(a!=0 && b!=0) printf("yes\n");
	   else printf("no\n");
	return 0;
}
