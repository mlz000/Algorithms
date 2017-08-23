#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long LL;
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		priority_queue<LL,vector<LL>,greater<LL> >q;
		for(int i=1,x,y;i<=n;++i){
			cin>>x>>y;
			q.push(x);
		}
		LL ans=0ll;
		for(int i=1;i<n;++i){
			LL t1=q.top();
			q.pop();
			LL t2=q.top();
			q.pop();
			ans+=t1+t2;
			q.push(t1+t2);
		}
		cout<<ans<<endl;
	}
	return 0;
}
