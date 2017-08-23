#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char s[10];
int n,f[1<<24];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%s",s);
		int x=0;
		for(int j=0;j<3;++j)	x|=(1<<(s[j]-'a'));
		++f[x];
	}
	for(int j=0;j<24;++j)
		for(int i=0;i<(1<<24);++i){
			if((i>>j)&1)
				f[i]+=f[i^(1<<j)];
		}
	int ans=0;
	for(int i=0;i<(1<<24);++i)	ans^=(n-f[i])*(n-f[i]);
	printf("%d\n",ans);
	return 0;
}
