#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <algorithm>
using namespace std;
const int N=17;
int ca,n,p[N],cover[1<<N],f[1<<N];
int main(){
	while(scanf("%d",&n)&&n){
		ca++;
		for(int i=0;i<n;++i){
			int m,x;
			scanf("%d",&m);
			p[i]=1<<i;
			while(m--)	scanf("%d",&x),p[i]|=(1<<x);
		}
		for(int i=0;i<(1<<n);++i){
			cover[i]=0;
			for(int j=0;j<n;++j)
				if(i&(1<<j))	cover[i]|=p[j];
		}
		f[0]=0;
		int all=(1<<n)-1;
		for(int s=1;s<(1<<n);++s){
			f[s]=0;
			for(int s0=s;s0;s0=(s0-1)&s)
				if(cover[s0]==all)	f[s]=max(f[s],f[s^s0]+1);
		}
		printf("Case %d: %d\n",ca,f[all]);
	}
	return 0;
}

