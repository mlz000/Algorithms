#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
const int N=100005;
using namespace std;
int T,c,n,x[N],y[N],w[N],d[N],ori[N],tot[N],sumw[N],q[N];
int calc(int x){
	return d[x]-tot[x+1]+ori[x+1];
}
int main(){
	scanf("%d",&T);
	while(T--){
		memset(d,0,sizeof(d));
		scanf("%d%d",&c,&n);
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",&x[i],&y[i],&w[i]);
			ori[i]=abs(x[i])+abs(y[i]);
			sumw[i]=sumw[i-1]+w[i];
			tot[i]=tot[i-1]+abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
		}
		int h=1,r=1;
		for(int i=1;i<=n;++i){
			while(h<=r && sumw[i]-sumw[q[h]]>c)	h++;
			d[i]=calc(q[h])+tot[i]+ori[i];
			while(h<=r && calc(i)<=calc(q[r]))	r--;
			q[++r]=i;
		}
		printf("%d\n",d[n]);
		if(T)	printf("\n");
	}
	return 0;
}
