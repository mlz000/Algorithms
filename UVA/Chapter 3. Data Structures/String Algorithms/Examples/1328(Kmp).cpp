#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N=1e6+5;
int ca,n,p[N];
char s[N];
int main(){
	while(scanf("%d",&n)&&n){
		ca++;
		printf("Test case #%d\n",ca);
		scanf("%s",s+1);
		int l=strlen(s+1);
		int j=0;
		p[0]=0;
		for(int i=2;i<=l;++i){
			while(j && s[j+1]!=s[i])	j=p[j];
			if(s[j+1]==s[i])	j++;
			p[i]=j;
		}
		for(int i=2;i<=l;++i)
			if(p[i] && i%(i-p[i])==0)	printf("%d %d\n",i,i/(i-p[i]));
		printf("\n");
	}
	return 0;
}
	
