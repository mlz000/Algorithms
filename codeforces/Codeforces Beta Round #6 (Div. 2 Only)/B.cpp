#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=305;
char s[N][N];
int a[N];
int main()
{
	int n,m;
	char c;
	cin>>n>>m>>c;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>s[i][j];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(s[i][j]==c)	a[s[i+1][j]]=a[s[i-1][j]]=a[s[i][j+1]]=a[s[i][j-1]]=1;
	int ans=0;
	for(int i='A';i<='Z';++i)	if(i!=c) ans+=a[i];
	printf("%d",ans);
	return 0;
}

