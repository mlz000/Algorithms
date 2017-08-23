#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N=305,MOD=1000000000;
typedef long long LL;
char s[N];
int f[N][N];
int dp(int i,int j){
	if(i==j)	return 1;
	if(f[i][j]>=0)	return f[i][j];
	if(s[i]!=s[j])	return 0;
	f[i][j]=0;
	for(int k=i+2;k<=j;++k)
		if(s[i]==s[k])
			f[i][j]=(f[i][j]+(LL)dp(i+1,k-1)*(LL)dp(k,j))%MOD;
	return f[i][j];
}
int main(){
	while(scanf("%s",s)!=EOF){
		memset(f,-1,sizeof(f));
		printf("%d\n",dp(0,strlen(s)-1));
	}
	return 0;
}

