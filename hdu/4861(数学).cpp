#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	long long k,p;
	while(~scanf("%I64d%I64d",&k,&p)){
		if((k/(p-1))&1)	puts("YES");
		else puts("NO");
	}
	return 0;
}
