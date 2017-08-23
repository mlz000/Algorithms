#include <cstring>	//分块
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
const int N=100005;
int n,m,block,a[N],next[N],step[N];
void update(int l,int r){
	for(int i=r-1;i>=l;--i){
		if(i+a[i]<r)	next[i]=next[i+a[i]],step[i]=step[i+a[i]]+1;//记录到下一块的位置和步数
		else next[i]=i,step[i]=0;
	}
}
void init(){
	block=(int)(sqrt(n)+0.5);
	for(int l=1,r=l+block;l<=n;l=r,r=min(n+1,l+block))	update(l,r);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)	scanf("%d",&a[i]);
	init();
	while(m--){
		int x,y,c;
		scanf("%d",&c);
		if(!c){
			scanf("%d%d",&x,&y);
			a[x]=y;
			int l=x/block*block,r=min(n+1,l+block);
			update(l,r);
		}
		else {
			scanf("%d",&x);
			int last,ans=0;
			for(int i=x;i<=n;){
				if(next[i]==i)	++ans,last=i,i=i+a[i];
				else ans+=step[i],i=next[i];
			}
			printf("%d %d\n",last,ans);
		}
	}
	return 0;
}
