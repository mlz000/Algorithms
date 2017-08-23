#include <algorithm>
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
const int N=5005;
char s[N][N];
int sum[N],a[N],n,m;
int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<=n;i++) scanf("%s",s[i]);
	int MAX=0;
	for(int j=0;j<m;++j){
		for(int i=0;i<m;++i)	sum[i]=0;
		for(int i=0;i<n;++i){
			if(s[i][j]=='0')	a[i]=0;
			else ++a[i];
			sum[a[i]]++;
		}
		for(int i=m;i>=0;--i){
			sum[i]+=sum[i+1];
			MAX=max(MAX,sum[i]*i);
		}
	}
	printf("%d\n",MAX);
	return 0;
}
