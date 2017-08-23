#include<cstdio>
#include<set>
#include<map>
#include<queue>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=55;
int n,ca,Max,status,a[N];
map<int,int> g;
set<int> ans;
struct data{
	int sta;
	set<int> b;
};
void init(){
	for(int i=0;i<n;++i)	scanf("%d",&a[i]);
	sort(a,a+n);
	n=unique(a,a+n)-a;
	g.clear();ans.clear();ans.insert(0);
	for(int i=0;i<n;++i)	g[a[i]]=i+1,ans.insert(a[i]);
	status=(1<<n)-1;
	Max=a[n-1];
}
bool check(int x,data cur){
    if (cur.b.find(x) != cur.b.end() || x<0 || x>Max) return false;  
    return true;  

}
void add(int x,data cur,queue<data> &Q){
	data tmp=cur;
	tmp.b.insert(x);
	for(set<int>::iterator it=cur.b.begin();it!=cur.b.end();++it){
		int num=abs(x-*it);
		if(g[num])	tmp.sta|=(1<<(g[num]-1));
	}
	if(tmp.sta!=cur.sta)	Q.push(tmp);
}
void bfs2(int num,data cur,queue<data> &Q){
	for(int i=0;i<n;++i){
		if(cur.sta&(1<<i))	continue;
		if(check(num-a[i],cur))	add(num-a[i],cur,Q);
		if(check(num+a[i],cur))	add(num+a[i],cur,Q);
	}
}
void bfs(){
	data tmp;
	tmp.sta=0,tmp.b.insert(0);
	queue<data> Q;
	Q.push(tmp);
	while(Q.size()){
		data now=Q.front();
		Q.pop();
		if(now.sta==status){
			if(now.b.size()<ans.size() || now.b.size()==ans.size() && *now.b.rbegin()<*ans.rbegin()){
				ans=now.b;
			}
			return ;
		}
		for(set<int>::iterator it=now.b.begin();it!=now.b.end();++it)	bfs2(*it,now,Q);	
	}
}
void print(){
	printf("Case %d:\n",ca);
	printf("%d\n",ans.size());
	for(set<int>::iterator it=ans.begin();it!=ans.end();++it)	printf("%d ",*it);
	printf("\n");
}
int main(){
	while(scanf("%d",&n)&&n){
		++ca;
		init();
		bfs();
		print();
	}
	return 0;
}
