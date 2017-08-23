#include<cstdio>//Orz clj STLË®¹ýsplay
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<set>
using namespace std;
const int N=500000,inf=~0u>>2;
int n,l[N][2],cnt[N];
struct qset
{
	multiset<int> S;
	typedef set<int>::iterator it;
	int MIN;
	qset(){MIN=inf;}
	void ins(int x)
	{
		it j=S.insert(x);
		if(j!=S.begin())	MIN=min(MIN,x-*(--j)),++j;
		++j;
		if(j!=S.end())	MIN=min(MIN,*(j)-x);
	}
}all;
struct state
{
	bool in;
	int i,x,val;
	state(bool _in,int _val,int _i=0,int _x=0):
	in(_in),val(_val),i(_i),x(_x){}
	bool legal()	const{return in||x==cnt[i];}
	bool operator <(const state &o) const{return val>o.val;}
};
priority_queue<state> Q;
void ins(int i,int x)
{
	all.ins(x);
	Q.push(state(true,abs(x-l[i][1])));
	l[i][1]=x,cnt[i]++;
	if(i!=n-1)	Q.push(state(false,abs(l[i+1][0]-x),i,cnt[i]));
}
int get()
{
	while(!Q.top().legal())	Q.pop();
	return Q.top().val;
}
int main()
{
	char s[20];
	int m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)	scanf("%d",&l[i][0]),l[i][1]=l[i][0],all.ins(l[i][0]),cnt[i]=1;
	for(int i=0;i<n-1;++i)	Q.push(state(false,abs(l[i+1][0]-l[i][0]),i,1));
	while(m--)
	{
		int x,pos;
		scanf("%s",s);
		if(s[0]=='I')	scanf("%d%d",&pos,&x),ins(pos-1,x);
		else if(s[4]=='G')	printf("%d\n",get());
		else printf("%d\n",all.MIN);
	}
	return 0;
}
