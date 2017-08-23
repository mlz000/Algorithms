#include<cstdio>//A*算法 
#include<climits>
#include<iostream>
#include<algorithm>
#include<queue> 
#include<cstring>
using namespace std;
const int N=1005,M=100005;
int dis[N],head1[N],head2[N],next1[M],next2[M],len1[M],len2[M],to1[M],to2[M];
int n,m,s,t,k;
bool v[N];
struct node1
{
   int to;
   int len;
};
bool operator<(const node1&a ,const node1&b) {return a.len>b.len;};//优先队列
struct node2
{
    int to;
    int g;
    int h;
    int f;
};
bool operator<(const node2&a ,const node2&b) {return a.f>b.f;};//A*
priority_queue<node1> q1;
priority_queue<node2> q2; 
void dij()
{
    int i;
	for(i=1;i<=n;++i)
     dis[i]=INT_MAX;
    dis[t]=0; 
    node1 tmp;
    tmp.to=t;
    tmp.len=0;
    q1.push(tmp);
    while(!q1.empty())
    {
	     tmp=q1.top();
	     q1.pop();
	     if(v[tmp.to]) continue;
	      v[tmp.to]=true;
	     for(int e=head1[tmp.to];e!=-1;e=next1[e])
		 {
		    if(dis[tmp.to]+len1[e]<dis[to1[e]])
		    {
			   dis[to1[e]]=dis[tmp.to]+len1[e];
			   node1 tmp2;
			   tmp2.to=to1[e];
			   tmp2.len=dis[to1[e]];
			   q1.push(tmp2); 
			}
		 } 
	}
}
int Astar()
{
    int cnt[N];
    memset(cnt,0,sizeof(cnt));
    node2 tmp;
    tmp.to=s;tmp.g=0;tmp.h=dis[s];tmp.f=tmp.g+tmp.h;
    q2.push(tmp);
	while(!q2.empty())
	{
	   node2 tmp=q2.top();
	   q2.pop();
	   cnt[tmp.to]++; 
	   if(cnt[t]==k) return tmp.f;
	   if(cnt[tmp.to]>k) continue;//出队大于k次，无意义
	   for(int e=head2[tmp.to];e!=-1;e=next2[e])
	   {
	       node2 tmp2;
	       tmp2.g=tmp.g+len2[e];
	       tmp2.h=dis[to2[e]];
	       tmp2.f=tmp2.g+tmp2.h;
	       tmp2.to=to2[e];
	       q2.push(tmp2);
	   } 
	}  
	return -1;
}
int main()
{
	int i,ss,tt,l;
	scanf("%d%d",&n,&m);
	int num1=0;
	int num2=0;
	memset(head1,-1,sizeof(head1));
	memset(head2,-1,sizeof(head2));
	for(i=0;i<m;++i)
	{
	  scanf("%d%d%d",&ss,&tt,&l);
	  len1[num1]=l;to1[num1]=ss;next1[num1]=head1[tt];head1[tt]=num1++;//图反向求估价函数 
	  len2[num2]=l;to2[num2]=tt;next2[num2]=head2[ss];head2[ss]=num2++;
	}
	scanf("%d%d%d",&s,&t,&k);
	dij();
	if(s==t) k++;
	printf("%d",Astar());
//	system("pause"); 
	return 0;
} 
