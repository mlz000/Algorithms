#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int N=25;
int n,a[N];
char s[N<<1];
map<int,int>mp;
int main(){
	while(scanf("%d",&n)==1){
		for(int i=0;i<n;++i){
			scanf("%s",s);
			a[i]=0;
			for(int j=0;s[j]!='\0';j++)	a[i]^=(1<<(s[j]-'A'));
		}
		mp.clear();
		int n1=n/2,n2=n-n1;
		for(int i=0;i<(1<<n1);++i){
			int x=0;
			for(int j=0;j<n1;++j)	if(i&(1<<j))	x^=a[j];
			if(!mp.count(x) || __builtin_popcount(mp[x])<__builtin_popcount(i))	mp[x]=i;
		}
		int ans=0;
		for(int i=0;i<(1<<n2);++i){
			int x=0;
			for(int j=0;j<n2;++j)	if(i&(1<<j))	x^=a[n1+j];
			if(mp.count(x) && __builtin_popcount(ans)<__builtin_popcount(mp[x])+__builtin_popcount(i))	ans=(i<<n1)^mp[x];
		}
		printf("%d\n",__builtin_popcount(ans));
		for(int i=0;i<n;++i)	if(ans&(1<<i))	printf("%d ",i+1);
		printf("\n");
	}
	return 0;
}
	
