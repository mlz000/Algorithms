#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10;
ll p[N][3];
ll dis(ll x,ll y,ll z){
	return x*x+y*y+z*z;
}
bool ok(int m){
	ll a[N];
	int cnt=-1;
	for(int i=0;i<8;++i)
		if(i!=m)	a[++cnt]=dis(p[m][0]-p[i][0],p[m][1]-p[i][1],p[m][2]-p[i][2]);
	sort(a,a+7);
	if(a[0]==0 || a[0]!=a[1] || a[0]!=a[2] || a[3]!=a[4] || a[3]!=a[5] || a[0]*2!=a[3] || a[0]*3!=a[6])	return false;	
	return true;
}
bool check(){
	for(int i=0;i<8;++i)
		if(!ok(i))	return false;
	puts("YES");
	for(int i=0;i<8;++i){
		for(int j=0;j<3;++j)	printf("%I64d ",p[i][j]);
		puts("");
	}
	return true;
}
bool dfs(int m){
	if(m==8)	return check();
	sort(p[m],p[m]+3);
	do{
		if(dfs(m+1))	return true;
	}while(next_permutation(p[m],p[m]+3));
	return false;
}
int main(){
	for(int i=0;i<8;++i)	
		for(int j=0;j<3;++j)
			scanf("%I64d",&p[i][j]);
	if(!dfs(0))	puts("NO");
	return 0;
}
