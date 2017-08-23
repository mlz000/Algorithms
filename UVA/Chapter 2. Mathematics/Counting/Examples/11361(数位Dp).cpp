#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int T,a,b,k,L,f[11][101][101],num[11],p[11];
int dp(int l,int m1,int m2,int e){
	if(l==0)	return (m1==0)&&(m2==0);
	if(!e && f[l][m1][m2]!=-1)	return f[l][m1][m2];
	int u=(e?num[l]:9);
	int tmp=0;
	for(int i=0;i<=u;++i)	tmp+=dp(l-1,(m1+i)%k,(m2+i*p[l-1])%k,e&&(i==num[l]));
	return f[l][m1][m2]=tmp;
}
int work(int x){
	memset(f,-1,sizeof(f));
	L=0;
	while(x!=0){
		num[++L]=x%10;
		x/=10;
	}
	return dp(L,0,0,1);
}
int main(){
	scanf("%d",&T);
	for(int i=0,x=1;i<=10;++i,x*=10)	p[i]=x;	
	while(T--){
		cin>>a>>b>>k;
		if(k>=100)	{printf("0\n");continue;}
		printf("%d\n",work(b)-work(a-1));
	}
	return 0;
}
		
