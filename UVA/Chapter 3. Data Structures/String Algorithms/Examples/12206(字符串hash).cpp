#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
const int N=40005;
char s[N];
int m,l,pos,rank[N];
unsigned long long hash[N],h[N],p[N];
bool cmp(const int &a,const int &b){
	return h[a]<h[b] || (h[a]==h[b] && a<b);
}
bool check(int L){
	pos=-1;
	for(int i=0;i<l-L+1;++i){
		rank[i]=i;
		h[i]=hash[i]-hash[i+L]*p[L];
	}
	sort(rank,rank+l-L+1,cmp);
	int cnt=0;
	for(int i=0;i<l-L+1;++i){
		if(i==0 || h[rank[i]]!=h[rank[i-1]])	cnt=0;
		if(++cnt>=m)	pos=max(pos,rank[i]);
	}
	return pos>=0;
}
int main(){
	while(scanf("%d",&m)&&m){
		scanf("%s",s);
		l=strlen(s);
		hash[l]=0,p[0]=1;
		for(int i=l-1;i>=0;--i)	hash[i]=hash[i+1]*131+(s[i]-'a');
		for(int i=1;i<=l;++i)	p[i]=p[i-1]*131;
		if(!check(1))	printf("none\n");
		else{
			int L=1,R=l+1;
			while(L<R){
				int M=L+(R-L+1)/2;
				if(check(M))	L=M;
				else R=M-1;
			}
			check(L);
			printf("%d %d\n",L,pos);
		}
	}
	return 0;
}
