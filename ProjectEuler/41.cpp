#include<iostream>//7652413
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int prim[50000000],num[15];
bool v[10000005];
bool check(int x){
	memset(num,0,sizeof(num));
	int now=0;
	bool flag=true;
	while(x){
		num[++now]=x%10;
		x/=10;
	}
	sort(num+1,num+now+1);
	for(int i=1;i<=now;++i)	if(num[i]!=i)	{flag=false;break;}
	return flag;
}
int main(){
	int tot=0;
	for(int i=2;i<=1e7;++i){
		if(!v[i])	prim[++tot]=i;
		for(int j=1;j<=tot;++j){
			if(i*prim[j]>1e7)	break;
			v[i*prim[j]]=true;
			if(i%prim[j]==0)	break;
		}
	}
	int ans;
	for(int i=1e7;;i--){
		if(!v[i] && check(i))	{ans=i;break;}
	}
	printf("%d\n",ans);
	return 0;
}
