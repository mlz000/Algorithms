#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=100005;
struct data{
	int st,ed,d;
}a[N];
bool cmp(const data &p,const data &q){
	return p.st+p.d<q.st+q.d;
}
int n;
int main(){
	while(scanf("%d",&n)&&n){
		for(int i=1;i<=n;++i)	scanf("%d%d",&a[i].st,&a[i].ed),a[i].d=(a[i].ed-a[i].st)/2+1;
		sort(a+1,a+n+1,cmp);
		bool flag=true;
		int last=0;
		for(int i=1;i<=n;++i){
			last=max(last+a[i].d,a[i].st+a[i].d);
			if(last>a[i].ed)	{flag=false;break;}
		}
		if(flag)	printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
