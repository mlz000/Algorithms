#include<cstdio>//treap的第一道题！orz大谷神！T_T  
#include<algorithm>
#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;
const int N=100005;
int tot,root,ans;
struct tree
{
   int l,r,weight,size;
   long long v,fix;
}a[N];
void rot_l(int &x)
{
    int y=a[x].r;
    a[x].r=a[y].l;
    a[y].l=x;
    a[y].size=a[x].size;
    a[x].size=a[a[x].l].size+a[a[x].r].size+a[x].weight;
    x=y;
}
void rot_r(int &x)
{
    int y=a[x].l;
    a[x].l=a[y].r;
    a[y].r=x;
    a[y].size=a[x].size;
    a[x].size=a[a[x].l].size+a[a[x].r].size+a[x].weight;
    x=y;  
}
void insert(int &p,long long v)
{
   if(!p) {p=++tot;a[p].v=v;a[p].weight=1;a[p].size=1;a[p].fix=rand()*rand();return;}
   a[p].size++;
   if(v<a[p].v) 
   {
        insert(a[p].l,v);
        if(a[a[p].l].fix<a[p].fix) rot_r(p);
   } 
   else if(v>a[p].v)
   {
        insert(a[p].r,v);
        if(a[a[p].r].fix<a[p].fix) rot_l(p);
   }
   else {a[p].weight++;}
}
int remove(int &x,long long v)
{
    int tmp;
    if(!x) return 0;
    if(a[x].v<v) 
    {
        tmp=a[a[x].l].size+a[x].weight;
        x=a[x].r;
        return (tmp+remove(x,v));
    }
    else
    {
            tmp=remove(a[x].l,v);
            a[x].size-=tmp;
            return tmp;
    }
}
long long findkth(int p,int k)
{
     if(k<=a[a[p].l].size) return findkth(a[p].l,k);
     else if(k>a[a[p].l].size+a[p].weight) 
     return findkth(a[p].r,k-(a[a[p].l].size+a[p].weight));
     else return a[p].v;
}
int main()
{
      int i,n;
      long long delta=0ll;
      long long MIN;
      scanf("%d%lld",&n,&MIN);
     // srand(time(0)); 
      for(i=1;i<=n;++i)
      {
        char s[100];
        long long x;
        scanf("%s%lld",s,&x);
        if(s[0]=='I')
        {
          if(x>=MIN) insert(root,x-delta);
        } 
        else if(s[0]=='A') delta+=x;
        else if(s[0]=='S') 
        {
                  delta-=x;
                  ans+=remove(root,MIN-delta);
        }
        else if(s[0]=='F') 
        {
                  if(x>a[root].size) printf("-1\n");
                  else printf("%lld\n",findkth(root,a[root].size-x+1)+delta);
        }
      }
      printf("%d",ans);
      //system("pause");
      return 0;
}
