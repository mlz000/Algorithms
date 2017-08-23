#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int dx[]={-1,1,0,0,-1,-1,1,1};
int dy[]={0,0,1,-1,1,-1,1,-1};
int ans,path[10][10];
bool v[10][10];
char s[8][5]={"L","R","U","D","LU","LD","RU","RD"};
struct data
{
	int x,y,w;
}a[100],st,ed;
bool judge(int x,int y)
{
	return (x>=1 && x<=8 && y>=1 && y<=8);
}
void bfs()
{
	queue<data> q;
	q.push(st);
	v[st.x][st.y]=true;
	while(q.size())
	{
		data now=q.front();
		q.pop();
		data next;
		for(int i=0;i<8;++i)
		{
			next.x=now.x+dx[i];
			next.y=now.y+dy[i];
			if(!v[next.x][next.y] && judge(next.x,next.y))
			{
				v[next.x][next.y]=true;
				next.w=now.w+1;
				q.push(next);
				path[next.x][next.y]=i;//direction
				if(next.x==ed.x && next.y==ed.y){ans=next.w;return ;}
			}
		}
	}
}
void print(int x,int y)
{
	if(x==st.x && y==st.y)	return ;
	print(x-dx[path[x][y]],y-dy[path[x][y]]);
	printf("%s\n",s[path[x][y]]);
}
int main()
{
	char s1[5],s2[5];
	scanf("%s",s1);
	st.x=s1[0]-'a'+1;
	st.y=s1[1]-'0';
	st.w=0;
	scanf("%s",s2);
	ed.x=s2[0]-'a'+1;
	ed.y=s2[1]-'0';
	bfs();
	printf("%d\n",ans);
	print(ed.x,ed.y);
	return 0;
}
