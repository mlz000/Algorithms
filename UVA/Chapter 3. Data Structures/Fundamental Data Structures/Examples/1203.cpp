#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
struct data{
	int n,p,t;
	bool operator < (const data &a) const {
		return t>a.t || (t==a.t && n>a.n);
	}
};
int main(){
	priority_queue<data> PQ;
	char s[20];
	while(scanf("%s",s)&&s[0]!='#'){
		data tmp;
		scanf("%d%d",&tmp.n,&tmp.p);
		tmp.t=tmp.p;
		PQ.push(tmp);
	}
	int m;
	scanf("%d",&m);
	while(m--){
		data r=PQ.top();
		PQ.pop();
		printf("%d\n",r.n);
		r.t+=r.p;
		PQ.push(r);
	}
	return 0;
}
