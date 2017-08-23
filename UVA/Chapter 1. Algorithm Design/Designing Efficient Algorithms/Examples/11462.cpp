#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n,x,a[101];
int main(){
	while(scanf("%d",&n)&&n){
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;++i)	scanf("%d",&x),a[x]++;
		bool first=true;
		for(int i=1;i<=100;++i){
			if(!a[i])	continue;
			for(int j=1;j<=a[i];++j){
				if(first)	printf("%d",i),first=false;
				else printf(" %d",i);
			}
		}
		printf("\n");		
	}
	return 0;
}
