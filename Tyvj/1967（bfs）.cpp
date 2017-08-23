#include<cstdio>  //ˮBFS������ 
#include<iostream>
#include<queue> 
#include<cstring>
#include<algorithm>
#include<cmath> 
using namespace std;
const int N=1505;
const int MAX=0x3f3f3f3f; 
int v[N][N][2]; //v[i][j][0]����i,jλ���ϣ����ŵڼ������� v[][][1]������ŵڼ������� 
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0}; 
char s[N][N]; 
int sx,sy,n,m; 
struct data
{
   int x;
   int y;
   int nx;//�ڼ������� 
   int ny; 
};  
bool bfs()
{ 
   int i; 
   queue<data> q; 
   data st;
   st.x=sx;st.y=sy;st.nx=st.ny=0; 
   q.push(st); 
   v[sx][sy][0]=v[sx][sy][1]=0; 
   while(!q.empty())
   {
      data t=q.front();
      q.pop();
      data next; 
      for(i=0;i<4;++i)
      {
        next.x=t.x+dx[i];
        next.y=t.y+dy[i];
        int nmx=t.nx;
        int nmy=t.ny;
        if(next.x<0) {next.x+=n;nmx--;}//������һ������
        if(next.x>=n) {next.x-=n;nmx++;}//������һ������
        if(next.y<0) {next.y+=m;nmy--;}//������һ������
        if(next.y>=m) {next.y-=m;nmy++;}//������һ������
        if(v[next.x][next.y][0]!=MAX && v[next.x][next.y][1]!=MAX &&(v[next.x][next.y][0]!=nmx || v[next.x][next.y][1]!=nmy)) 
          return true;//�˵��Ѿ����ʹ��Ҳ���ͬһ������˵�������ߵ�����Զ
        if(s[next.x][next.y]=='.' && v[next.x][next.y][0]!=nmx && v[next.x][next.y][1]!=nmy) 
         {
            v[next.x][next.y][0]=nmx;
            v[next.x][next.y][1]=nmy;
            next.nx=nmx;
            next.ny=nmy;
            q.push(next); 
         } 
      } 
   } 
   return false; 
} 
int main()
{ 
    int i,j; 
    while(scanf("%d%d",&n,&m)!=EOF)
    { 
       memset(v,0x3f,sizeof(v)); 
       for(i=0;i<n;++i) 
       {
          scanf("%s",s[i]);  
          for(j=0;j<m;++j)
             if(s[i][j]=='S')  {sx=i;sy=j;}  
       } 
       if(bfs()) printf("Yes\n");
       else printf("No\n"); 
    } 
    return 0;
}
