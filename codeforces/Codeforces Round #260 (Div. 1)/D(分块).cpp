#include<bits/stdc++.h>
using namespace std;
const int N=100005;
deque<int>a[350];
int n,q,s,ans,c[350][N];
inline void deal(int &x){x=(x+ans-1)%n+1;}
int main(){
	scanf("%d",&n);
	s=sqrt(n);
	for(int i=1,x;i<=n;++i){
		scanf("%d",&x);
		a[(i-1)/s+1].push_back(x);
		c[(i-1)/s+1][x]++;
	}
	scanf("%d",&q);
	int op,l,r,x;
	while(q--){
		scanf("%d%d%d",&op,&l,&r);
		deal(l),deal(r);
		if(l>r)	swap(l,r);
		int fl=(l-1)/s+1,fr=(r-1)/s+1;
		if(op==1){
			if(fl==fr){
				int p=(r-1)%s;
				x=a[fl][p];
				a[fl].erase(a[fl].begin()+p);
				a[fl].insert(a[fl].begin()+(l-1)%s,x);
			}
			else{
				for(int i=fl;i<fr;++i){
					x=a[i].back(),a[i].pop_back(),--c[i][x];
					a[i+1].push_front(x),c[i+1][x]++;
				}
				int p=(r-1)%s+1;
				x=a[fr][p];
				a[fr].erase(a[fr].begin()+p);
				--c[fr][x];
				a[fl].insert(a[fl].begin()+(l-1)%s,x);
				++c[fl][x];
			}
		}
		else{
			scanf("%d",&x);
			deal(x);
			ans=0;
			if(fl==fr)	for(int i=(l-1)%s;i<=(r-1)%s;++i)	ans+=(a[fl][i]==x);
			else{
				for(int i=(l-1)%s;i<s;++i)	ans+=(a[fl][i]==x);
				for(int i=fl+1;i<fr;++i)	ans+=c[i][x];
				for(int i=0;i<=(r-1)%s;++i)	ans+=(a[fr][i]==x);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
