#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue> 
#include<cstring>
using namespace std;
const int N=1000005;
char s[N];
int main()
{
	int i,l,n,sum=0;
	scanf("%s",s);
	l=strlen(s);
	for(i=0;i<l;++i)
	 sum+=s[i]-'0';
	if(sum%3==0) printf("King will win.");
	else 
    {
		printf("MaoLaoDa will win.\n");
		printf("%d",sum%3);
	}
	//system("pause"); 
	return 0;
} 
