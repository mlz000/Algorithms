#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int buf[10];
int next(int n,int k){
	if(!k)	return 0;
	long long tmp=(long long)k*k;
	int L=0;
	while(tmp>0)	buf[L++]=tmp%10,tmp/=10;
	if(n>L)	n=L;
	int t=0;
	for(int i=0;i<n;++i)	t=t*10+buf[--L];
	return t;
}
int main(){
	int T,n,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		int ans=k;
		int k1=k,k2=k;
		do{
			k1=next(n,k1);
			k2=next(n,k2);//floydÅÐÈ¦
			ans=max(ans,k2);
			k2=next(n,k2);
			ans=max(ans,k2);
		}while(k1!=k2);
		printf("%d\n",ans);
	}
	return 0;
}

