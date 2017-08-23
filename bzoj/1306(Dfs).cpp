#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=10;
int s[N],c[N],n,ans;
void dfs(int x,int y){
	if(x==n){
		++ans;
		return ;
	}
	if(y==n){
		if(s[x]-c[x]==3){
			c[x]+=3;
			if(c[y]<=s[y] && c[y]+3*(n-x-1)>=s[y])
				dfs(x+1,x+2);
			c[x]-=3;
		}
		else if(s[x]-c[x]==1){
			++c[x],++c[y];
			if(c[y]<=s[y] && c[y]+3*(n-x-1)>=s[y])
				dfs(x+1,x+2);
			--c[x],--c[y];
		}
		else if(s[x]==c[x]){
			c[y]+=3;
			if(c[y]<=s[y] && c[y]+3*(n-x-1)>=s[y])
				dfs(x+1,x+2);
			c[y]-=3;
		}
	}
	else 
	{
		c[x]+=3;
		if(c[x]<=s[x] && c[y]<=s[y] && c[x]+3*(n-x)>=s[x] && c[y]+3*(n-x-1)>=s[y])	
			dfs(x,y+1);
		c[x]-=2,c[y]++;
		if(c[x]<=s[x] && c[y]<=s[y] && c[x]+3*(n-x)>=s[x] && c[y]+3*(n-x-1)>=s[y])	
			dfs(x,y+1);
		--c[x],c[y]+=2;
		if(c[x]<=s[x] && c[y]<=s[y] && c[x]+3*(n-x)>=s[x] && c[y]+3*(n-x-1)>=s[y])	
			dfs(x,y+1);
		c[y]-=3;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)	scanf("%d",&s[i]);
	dfs(1,2);
	printf("%d\n",ans);
	return 0;
}

