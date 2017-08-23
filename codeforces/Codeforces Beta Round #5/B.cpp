#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int N=1005;
char s[N][N];
int ans,l[N],n,r;
int main()
{
	while (gets(s[n]))
	{
		l[n]=strlen(s[n]);
		if (l[n]>ans) ans=l[n];
		n++;
	}
	for (int i=0; i<ans+2; i++) printf("*"); puts("");
	for (int i=0; i<n; i++)
	{
		printf("*");
		int c=(ans-l[i])/2;
		if ((ans-l[i])&1) c+=r, r^=1;
		for (int j=0;j<c;j++) printf(" ");
		printf("%s",s[i]);
		for (int j=0;j<ans-l[i]-c;j++) printf(" ");
		puts("*");
	}
	for (int i=0; i<ans+2; i++) printf("*"); puts("");
	return 0;
}

