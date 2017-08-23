#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N=55;
char s[N][N];
int ans=10000,n,m,d[N][N],dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};	
struct P{
	int x,y;
};
void solve(int x,int y){
	int tmp=0;
	memset(d,8,sizeof(d));
	d[x][y]=1;
	queue<P>q;
	P st;
	st.x=x,st.y=y;
	q.push(st);
	while(q.size()){
		P now=q.front(),nxt;
		q.pop();
		for(int i=0;i<4;++i){
			nxt.x=now.x+dx[i];
			nxt.y=now.y+dy[i];
			if(nxt.x>=0 && nxt.x<n && nxt.y>=0 && nxt.y<m){
				int t=d[now.x][now.y]+(s[now.x][now.y]!=s[nxt.x][nxt.y]);
				if(t<d[nxt.x][nxt.y]){
					d[nxt.x][nxt.y]=t;
					q.push(nxt);
				}
			}
		}
	}
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			if(s[i][j]=='B')
				tmp=max(tmp,d[i][j]);
	ans=min(ans,tmp);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)	scanf("%s",s[i]);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			solve(i,j);
	printf("%d\n",ans);	
	return 0;
}
