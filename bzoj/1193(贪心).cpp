#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N=20;
const int dx[8]={2,1,-1,-2,-2,-1,1,2};
const int dy[8]={1,2,2,1,-1,-2,-2,-1};
bool v[N][N];
struct data
{
	int x,y,ans;
	data(int X=0,int Y=0,int Ans=0)
	{
		x=X,y=Y,ans=Ans;
	}
};
data st;
void bfs()
{
	queue<data> q;
	v[st.x][st.y]=true;
	q.push(st);
	while(q.size())
	{
		data now=q.front();
		q.pop();
		for(int i=0;i<8;++i)
		{
			int x=abs(now.x+dx[i]);
			int y=abs(now.y+dy[i]);
			if(x<=10 && y<=10 && !v[x][y])
			{
				data next=data(x,y,now.ans+1);
				v[next.x][next.y]=true;
				q.push(next);
				if(x==0 && y==0)	printf("%d\n",next.ans);
			}
		}
	}
}
int main()
{
	data ed;
	scanf("%d%d%d%d",&st.x,&st.y,&ed.x,&ed.y);
	st=data(abs(st.x-ed.x),abs(st.y-ed.y),0);
	while(st.x>=10 || st.y>=10)
	{
		if(st.x>st.y)	st=data(abs(st.x-2),abs(st.y-1),st.ans+1);
		else st=data(abs(st.x-1),abs(st.y-2),st.ans+1);
	}
	bfs();
	return 0;
}
