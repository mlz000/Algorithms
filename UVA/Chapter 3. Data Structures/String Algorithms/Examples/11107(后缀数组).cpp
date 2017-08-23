#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<stack>
#include<map>
using namespace std;
const int N=1100*110,M=1500;
struct suffixarray{
	int n,ans,sum,Mini,idx[N],c[N],s[N],t[N],t2[N],sa[N],height[N],rank[N];
	inline void init(){	
		n=0;
		memset(sa,0,sizeof(sa));
		memset(idx,0,sizeof(idx));
	}
	inline void add(int ch,int i){	
		idx[n]=i;
		s[n++]=ch;
	}
	void build(int m){
		int *x=t,*y=t2;
		for(int i=0;i<m;++i)	c[i]=0;
		for(int i=0;i<n;++i)	c[x[i]=s[i]]++;
		for(int i=1;i<m;++i)	c[i]+=c[i-1];
		for(int i=n-1;i>=0;--i)	sa[--c[x[i]]]=i;
		for(int k=1;k<=n;k<<=1){
			int p=0;
			for(int i=n-k;i<n;++i)	y[p++]=i;
			for(int i=0;i<n;++i)	if(sa[i]>=k)	y[p++]=sa[i]-k;
			for(int i=0;i<m;++i)	c[i]=0;
			for(int i=0;i<n;++i)	c[x[y[i]]]++;
			for(int i=1;i<m;++i)	c[i]+=c[i-1];
			for(int i=n-1;i>=0;--i)	sa[--c[x[y[i]]]]=y[i];
			swap(x,y);
			x[sa[0]]=0;
			p=1;
			for(int i=1;i<n;++i)
				x[sa[i]]=(y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+k]==y[sa[i]+k])?p-1:p++;
			if(p>=n)	break;
			m=p;
		}
	}
	void calc(){
		int k=0;
		for(int i=0;i<n;++i)	rank[sa[i]]=i;
		for(int i=0;i<n;++i){
			if(k)	k--;
			int j=sa[rank[i]-1];
			while(s[i+k]==s[j+k])	k++;
			height[rank[i]]=k;
		}
	}
}SA;
char s[1200];
int n,flag[1100];
bool can(int L,int R){
	memset(flag,0,sizeof(flag));
	if(R-L<=n/2)	return false;
	int cnt=0;
	for(int i=L;i<R;++i){
		int x=SA.idx[SA.sa[i]];
		if(x!=n && !flag[x])	flag[x]=true,cnt++;
	}
	return cnt>n/2;
}
void P(int L,int R){
	for(int i=L;i<R;++i)	printf("%c",SA.s[i]+'a'-1);
	printf("\n");
}
bool print(int l,int f){
	int L=0;
	for(int R=1;R<=SA.n;++R){
		if(R==SA.n || SA.height[R]<l){
			if(can(L,R)){
				if(f)	P(SA.sa[L],SA.sa[L]+l);
				else return true;
			}
			L=R;
		}
	}
	return false;
}
void work(int maxl){
	if(!print(1,0))	{printf("?\n");return;}
	int L=1,R=maxl;
	while(L<R){
		int M=L+(R-L+1)/2;
		if(print(M,0))	L=M;
		else R=M-1;
	}
	print(L,1);
}
int main(){
	int ca=0;
	while(scanf("%d",&n)&&n){
		int Max=0;
		if(ca++>0)	printf("\n");
		SA.init();
		for(int i=0;i<n;++i){
			scanf("%s",s);
			int l=strlen(s);
			Max=max(Max,l);
			for(int j=0;j<l;++j)	SA.add(s[j]-'a'+1,i);
			SA.add(100+i,n);
		}
		SA.add(0,n);
		if(n==1)	printf("%s\n",s);
		else{
			SA.build(100+n);
			SA.calc();
			work(Max);
		}
	}
	return 0;
}
