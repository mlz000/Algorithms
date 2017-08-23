#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=4005;
vector<long long>a;
int cnt[10],p[]={2,3,5,7,11};
int tot=2;
long long n;
void dfs(long long cur,int id){
	if(id==tot)	{a.push_back(cur);return;}
	dfs(cur,id+1);
	if(cur*p[id]<=n*n*2)	dfs(cur*p[id],id);
}
bool check(int now){
	tot=now;
	a.clear();
	dfs(1,0);
	memset(cnt,0,sizeof(cnt));
	if(a.size()<n)	return false;
	for(int i=0;i<a.size();++i)
		for(int j=0;j<tot;++j)
			if(a[i]%p[j]==0)	
				cnt[j]++;
	for(int j=0;j<tot;++j)	if(cnt[j]*2<n)	return false;
	return true;
}
int main(){
	scanf("%d",&n);
	while(!check(tot))	++tot;
	for(int i=0;i<n;++i)	printf("%I64d ",a[i]);
	return 0;
}

