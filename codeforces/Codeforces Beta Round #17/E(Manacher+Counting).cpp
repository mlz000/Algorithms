#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2e6+5,M=51123987;
char s1[N<<1],s2[N];
int n,m,p[N<<1],l[N<<1],r[N<<1];
int main(){
	scanf("%d%s",&n,s2);
	s1[m]='?',s1[++m]='#';
	for(int i=0;i<n;++i)	s1[++m]=s2[i],s1[++m]='#';
	int mx=0,id=0;
	for(int i=1;i<=m;++i){
		if(mx>i)	p[i]=min(p[2*id-i],mx-i);
		else	p[i]=1;
		for(;s1[i+p[i]]==s1[i-p[i]];p[i]++);
		if(i+p[i]>mx){
			mx=i+p[i];
			id=i;
		}
	}
	int ans=0;
	for(int i=1;i<=m;++i)	l[i-p[i]+1]++,l[i+1]--,r[i]++,r[i+p[i]]--,(ans+=p[i]/2)%=M;//²î·Ö
	ans=1ll*ans*(ans-1)/2%M;
	for(int i=1,s=0;i<=m;++i){
		l[i]+=l[i-1],r[i]+=r[i-1];
		if(i%2==0)	ans=(ans-1ll*s*l[i]%M+M)%M,(s+=r[i])%=M;
	}
	printf("%d\n",ans);
	return 0;
}

