#include<iostream>//插头Dp
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=15,INF=100000000;
int n,m,a[N][N],dp[N][N][60000];//3^10
// 插头编号：0表示无插头，1表示和数字2连通，2表示和数字3连通
struct state{
	int up[N];// up[i](0<=i<m)表示第i列处轮廓线上方的插头编号
	int left;// 当前格（即下一个要放置的方格）左侧的插头
	int encode(){
		int key=left;
		for(int i=0;i<m;++i)	key=key*3+up[i];
		return key;
	}
    // 在(row,col)处放一个新方格。UDLR分别为该方格上下左右四个边界上的插头编号
    // 产生的新状态存放在T里，成功返回true，失败返回false
	bool next(int row,int col,int U,int D,int L,int R,state &t){
		if(row==n-1 && D)	return false;
		if(col==m-1 && R)	return false;
		bool mustleft=(col>0 && left);
		bool mustup=(row>0 && up[col]);
		if((mustleft && L!=left) || (!mustleft && L))	return false;
		if((mustup && U!=up[col]) || (!mustup && U))	return false;
		if(mustleft && mustup && left!=up[col])	return false;
		for(int i=0;i<m;++i)	t.up[i]=up[i];
		t.up[col]=D;
		t.left=R;
		return true;
	}
};
int calc(int row,int col,state s){
	if(col==m)	{col=0;row++;}
	if(row==n)	return 0;
	int key=s.encode();
	int &tmp=dp[row][col][key];
	if(tmp>=0)	return tmp;
	tmp=INF;
	state t;
	if(a[row][col]<=1){
		if(s.next(row,col,0,0,0,0,t))	tmp=min(tmp,calc(row,col+1,t));// 整个格子里都不连线
		if(!a[row][col])	
			for(int i=1;i<=2;++i){
					if(s.next(row,col,i,i,0,0,t))	tmp=min(tmp,calc(row,col+1,t)+2);
					if(s.next(row,col,i,0,i,0,t))	tmp=min(tmp,calc(row,col+1,t)+2);
					if(s.next(row,col,i,0,0,i,t))	tmp=min(tmp,calc(row,col+1,t)+2);
					if(s.next(row,col,0,i,i,0,t))	tmp=min(tmp,calc(row,col+1,t)+2);
					if(s.next(row,col,0,i,0,i,t))	tmp=min(tmp,calc(row,col+1,t)+2);
					if(s.next(row,col,0,0,i,i,t))	tmp=min(tmp,calc(row,col+1,t)+2);
			}
	}
	else{
		int i=a[row][col]-1;
		if(s.next(row,col,i,0,0,0,t))	tmp=min(tmp,calc(row,col+1,t)+1);
		if(s.next(row,col,0,i,0,0,t))	tmp=min(tmp,calc(row,col+1,t)+1);
		if(s.next(row,col,0,0,i,0,t))	tmp=min(tmp,calc(row,col+1,t)+1);
		if(s.next(row,col,0,0,0,i,t))	tmp=min(tmp,calc(row,col+1,t)+1);
	}
	return tmp;
}
int main(){
	while(scanf("%d%D",&n,&m)&&n&&m){
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				scanf("%d",&a[i][j]);
		state s;
		memset(&s,0,sizeof(s));
		memset(dp,-1,sizeof(dp));
		int ans=calc(0,0,s);
		if(ans==INF)	ans=0;
		printf("%d\n",ans/2);
	}
	return 0;
}
