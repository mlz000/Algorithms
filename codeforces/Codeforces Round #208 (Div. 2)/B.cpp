#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int N=100005;
string s[N],s1,s2;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)	cin>>s[i],s1+="<3"+s[i];
	s1+="<3";
	int l1=s1.length();
	cin>>s2;
	int l2=s2.length();
	int j=0;
	for(int i=0;i<l2;++i)
	{
		if(s2[i]==s1[j])	++j;
	}
	if(j!=l1)	printf("no");
	else printf("yes");
	return 0;
}

