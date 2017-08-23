#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=105;
int n,m;
bool alp[30];
char s[N][N];
bool check(int x){
	int lx=N,ly=N,rx=-1,ry=-1;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(s[i][j]==x+'A'){
				lx=min(lx,i);
				ly=min(ly,j);
				rx=max(rx,i);
				ry=max(ry,j);
			}
		}
	}
    if(lx==N||ly==N||rx==-1||ry==-1||rx-lx<2||ry-ly<2)	return false;
	for(int j=ly;j<=ry;++j)	if(s[lx][j]!=x+'A' || s[rx][j]!=x+'A')	return false;
	for(int i=lx;i<=rx;++i)	if(s[i][ly]!=x+'A' || s[i][ry]!=x+'A')	return false;
	for(int i=lx+1;i<=rx-1;++i){
		for(int j=ly+1;j<=ry-1;++j){
			if(s[i][j]!='.')	return false;
		}
	}
	return true;
}
void solve(){
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			if(s[i][j]!='.')	alp[s[i][j]-'A']=true;
	for(int i=0;i<26;++i)
		if(alp[i] && check(i))	printf("%c",i+'A');
}		
void init(){
	memset(alp,0,sizeof(alp));
	memset(s,0,sizeof(s));
	for(int i=0;i<n;++i)	scanf("%s",s[i]);
}
int main(){
	while(scanf("%d%d",&n,&m)&&n&&m){
		init();
		solve();
		printf("\n");
	}
	return 0;
}
