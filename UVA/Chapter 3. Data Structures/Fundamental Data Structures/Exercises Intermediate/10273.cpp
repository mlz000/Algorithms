#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=1005;
int n,m,T,cnt,last,a[N][15],t[N];
bool v[N];
int main(){
	scanf("%d",&T);
	while(T--){
		memset(v,false,sizeof(v));
		cnt=last=0;
		int lcm=1;
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d",&t[i]);
			lcm=lcm*t[i]/__gcd(lcm,t[i]);
			for(int j=1;j<=t[i];++j)	scanf("%d",&a[i][j]);
		}
		for(int i=1;i<=lcm*2;++i){
			if(cnt==n)	break;
			int Min=10000;
			int Mini=-1;	
			for(int j=1;j<=n;++j){	
				if(v[j])	continue;
				if(a[j][((i-1)%t[j])+1]<Min)	Min=a[j][((i-1)%t[j])+1],Mini=j;
				else if(a[j][((i-1)%t[j])+1]==Min)	Mini=-1;
			}
			if(Mini!=-1)	v[Mini]=true,cnt++,last=i;
		}
		printf("%d %d\n",n-cnt,last);
	}
	return 0;
}
		
