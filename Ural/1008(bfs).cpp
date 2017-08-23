#include<algorithm>
#include<iostream> 
#include<cstring>
#include<string>
#include<cstdio>
#include<queue>
using namespace std;
const int N=100;
struct data
{
  int x;
  int y;
  data(int a=0,int b=0){x=a;y=b;}
}a[N];
char s[6]="RTLB",s1[105][10];
bool v[N][N];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int map[300];
int n,x,y;
bool cmp(data a,data b)
{
	if(a.x==b.x)
		return a.y<b.y;
	return a.x<b.x;
}
void bfs1()
{
     queue<data> q;
     data tmp=a[1];
     q.push(tmp);
     v[tmp.x][tmp.y]=false;
     int now=0;
     while(q.size())
     {
          int X=q.front().x;
          int Y=q.front().y;
          q.pop();
          ++now;
          for(int i=0;i<4;++i)
          {
              int xx=X+dx[i];
              int yy=Y+dy[i];
              if(xx>0 && xx<=10 && yy>0 && yy<=10 && v[xx][yy])
              {
                 v[xx][yy]=false;
                 q.push(data(xx,yy));
                 printf("%c",s[i]);
              }
          }
          if(now<n)  printf(",\n");
          else printf(".\n");                
     }
}
void bfs2()
{
     queue<data> q;
     q.push(data(n,y));
     v[n][y]=true;
     int now=1;
     while(q.size())
     {
        int X=q.front().x;
        int Y=q.front().y;
        q.pop(); 
        a[now].x=X,a[now].y=Y;
        for(int i=0;i<strlen(s1[now])-1;++i)
        {
           int j=map[s1[now][i]];
           int xx=X+dx[j];
           int yy=Y+dy[j];
           if(xx>0 && xx<=10 && yy>0 && yy<=10 &&!v[xx][yy])
           {
               v[xx][yy]=true;  
               q.push(data(xx,yy));      
           }
        }
        ++now;
     }
}
int main()
{
    char c;
    map[s[0]]=0;map[s[1]]=1;map[s[2]]=2;map[s[3]]=3;
    scanf("%d%c",&n,&c);
    if(c=='\n')
    {
       for(int i=1;i<=n;++i)    
       {
          if(i==1)  
          {
             scanf("%d%d",&x,&y);
             a[i].x=x,a[i].y=y;
             v[x][y]=true;
          }
          else 
          {
              scanf("%d%d",&x,&y);
              v[x][y]=true;
          } 
       }
       printf("%d %d\n",a[1].x,a[1].y); 
       bfs1();
    }
    else 
    {
       scanf("%d",&y);
       int i=1;
       while(scanf("%s",s1[i]),s1[i][0]!='.') ++i;
       printf("%d\n",i);
       int tot=i;
       bfs2();
       sort(&a[1],&a[tot+1],cmp); 
       for(int i=1;i<=tot;++i)  printf("%d %d\n",a[i].x,a[i].y);                
    }
    return 0;
} 
