#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int m,a[5],dp[N][5];
char s[N];
int main(){
	scanf("%s",s+1);
	scanf("%d",&m);
	for(int i=1;s[i];++i)
		for(int j=0;j<3;++j)
			dp[i][j]=dp[i-1][j]+(s[i]==j+'x'?1:0);
	while(m--){
		int l,r;
		scanf("%d%d",&l,&r);
		for(int j=0;j<3;++j)	a[j]=dp[r][j]-dp[l-1][j];
		sort(a,a+3);
		if(r-l<2 || a[2]-a[0]<=1)	puts("YES");
		else puts("NO");
	}
	return 0;
}
