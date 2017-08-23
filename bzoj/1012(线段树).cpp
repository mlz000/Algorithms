#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=200005;
int be,en,last,n,m,tot,MOD;
struct data
{
   int l;
   int r;
   int maxn;
}t[N*4];
void build(int l,int r,int root)
{
    t[root].l=l;
	t[root].r=r;
	if(l>=r) return ;
	int mid=(l+r)>>1;
	build(l,mid,root*2);
	build(mid+1,r,root*2+1);  
}
void change(int root)
{
   if(t[root].l==t[root].r) {t[root].maxn=n;return;}
   int mid=(t[root].l+t[root].r)>>1;
   if(en<=mid) change(root<<1);
   else change(root*2+1);
   t[root].maxn=max(t[root<<1].maxn,t[root*2+1].maxn);
}
int ask(int root)
{
    int ans=0;
	if(be<=t[root].l && t[root].r<=en) return t[root].maxn;
    int mid=(t[root].l+t[root].r)>>1;
    if(mid>=be) ans=max(ans,ask(root<<1));
    if(mid<en)  ans=max(ans,ask(root*2+1));
    return ans;
}
int main()
{
     int i;
	 char s[10];
	 scanf("%d%d\n",&m,&MOD);
     build(1,m,1);
     for(i=1;i<=m;++i)
     {
	   scanf("%s%d",&s,&n);
	   if(s[0]=='A')
	   {
	     n=(n+last)%MOD;
	     en=++tot;
	     change(1);
	   }
	   if(s[0]=='Q')
	   {
	     be=tot-n+1;
	     en=tot;
	     last=ask(1);
	     printf("%d\n",last);
	   }
	 }
	 return 0;
}
