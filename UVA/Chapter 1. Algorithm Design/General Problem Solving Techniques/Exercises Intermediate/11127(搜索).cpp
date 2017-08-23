#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N=40;
int n,ca;
char s[N];
bool judge(int x,int d){
	int y=(1<<d)-1;
	int a=x&y;
	x>>=d;
	int b=x&y;
	x>>=d;
	int c=x&y;
	return a==b && b==c;
}
int dfs(int x,int now){
	int k=now/3,t=n-now-1;
	for(int i=1;i<=k;++i)	if(judge(x>>(t+1),i))	return 0;
	if(now==n)	return 1;
	else if(s[now]=='0')	return dfs(x,now+1);
	else if(s[now]=='1')	return dfs(x+(1<<t),now+1);
	else return dfs(x,now+1)+dfs(x+(1<<t),now+1);
}
int main(){
	while(scanf("%d",&n)&&n){
		scanf("%s",s);
		ca++;
		printf("Case %d: %d\n",ca,dfs(0,0));
	}
	return 0;
}
