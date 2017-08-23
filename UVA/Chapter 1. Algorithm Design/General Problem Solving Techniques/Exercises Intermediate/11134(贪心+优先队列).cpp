#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int N=5005;
struct data{
	int l,r,id;
	friend bool operator<(const data &p,const data &q){
		if(p.l==q.l)	return p.r>q.r;
		return p.l>q.l;
	}
}a[N],b[N];
int n,ans[N][2];
bool check(data x[],int pos){
	priority_queue<data> q;
	for(int i=1;i<=n;++i)	q.push(x[i]);
	int Max=0;
	while(q.size()){
		data tmp=q.top();
		q.pop();
		if(tmp.r<Max)	return false;
		if(tmp.l<Max){
			tmp.l=Max;
			q.push(tmp);
			continue;
		}
		int cur=max(Max,tmp.l);	
		ans[tmp.id][pos]=cur;
		Max=cur+1;
	}
	return true;
}
int main(){
	while(scanf("%d",&n)&&n){
		for(int i=1;i<=n;++i)	scanf("%d%d%d%d",&a[i].l,&b[i].l,&a[i].r,&b[i].r),a[i].id=b[i].id=i;
		if(check(a,0) && check(b,1)){
			for(int i=1;i<=n;++i)	printf("%d %d\n",ans[i][0],ans[i][1]);
		}
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}
