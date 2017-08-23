#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,q,w[N];
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)	w[i]=i;
	int ago=0,rev=0,tot=n;
	while(q--){
		int op,l,r;
		scanf("%d",&op);
		if(op==1){
			scanf("%d",&l);
			if(l>tot-l){
				rev^=1;
				l=tot-l;
			}
			if(rev)	for(int i=tot-l;i<tot;++i)	w[ago+2*(tot-l)-i]+=n-w[ago+i];
			else{
				ago+=l;
				for(int i=0;i<l;++i)	w[ago+i]-=w[ago-i];
			}
			tot-=l;
		}
		else{
			scanf("%d%d",&l,&r);
			if(rev){
				int t=tot-r;
				r=tot-l;
				l=t;
			}
			printf("%d\n",w[ago+r]-w[ago+l]);
		}
	}
	return 0;
}
