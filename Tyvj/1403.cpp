#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int M=100001;
int f[40001];
struct data
{
    int a;
    int b;
    int v;
}edge[M];
bool cmp(const data &a,const data &b)
{
	return a.v<b.v;
}
int find(int p)
{
	if(f[p]==p) return f[p];
	else return f[p]=find(f[p]);
}
int main()
{
   int i,n,m;
   scanf("%d%d",&n,&m);
   for(i=1;i<=m;i++)
   scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].v);
   sort(&edge[1],&edge[m+1],cmp);
   for(i=1;i<=2*n;i++)
   f[i]=i;
   for(i=m;i>=1;i--)
   {
      int fa=find(edge[i].a);
      int fb=find(edge[i].b);
      if(fa==fb) {printf("%d",edge[i].v);return 0;}
      int x=find(edge[i].a+n);
      int y=find(edge[i].b+n);
      f[fa]=y;
      f[fb]=x;
   }
   printf("0");
   //system("pause");
   return  0;
}
