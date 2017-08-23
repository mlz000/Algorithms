#include<cstdio>
#include<limits.h>
#include<iostream>
#include<algorithm>
using namespace std;
int num[50001];
struct
{
    int l;
    int r;
    int MIN;
    int MAX;
}node[500000];
int build_tree1(int root,int l,int r);
int build_tree2(int root,int l,int r);
int askmax(int root,int a,int b);
int askmin(int root,int a,int b);
int change(int root,int a,int b);
int main()
{
       int i,p,a,b,n;
       scanf("%d%d",&n,&p);
       for(i=1;i<=n;++i)
       {
         scanf("%d",&num[i]);
       }
       build_tree1(1,1,n);
       build_tree2(1,1,n);
       for(i=1;i<=p;++i)
       {
            scanf("%d%d",&a,&b);
            if(a==0) a=1; 
            printf("%d ", askmax(1,a,b));
            printf("%d\n",askmin(1,a,b));
       }
       //system("pause");
       return 0;
}
int askmin(int root,int a,int b)
{
    int x=INT_MAX;
    int y=INT_MAX;
    int l=node[root].l;
    int r=node[root].r;
    int mid=(l+r)>>1;
    if((l>=a&&r<=b)||l==r) return node[root].MIN; 
    if(mid>=a)   x=askmin(root*2,a,b);
    if(mid+1<=b) y=askmin(root*2+1,a,b);
    return min(x,y);
}
int askmax(int root,int a,int b)
{
    int x=-1;
    int y=-1;
    int l=node[root].l;
    int r=node[root].r;
    int mid=(l+r)>>1;
    if((l>=a&&r<=b)||l==r) return node[root].MAX; 
    if(mid>=a)   x=askmax(root*2,a,b);
    if(mid+1<=b) y=askmax(root*2+1,a,b);
    return max(x,y);
} 
int build_tree1(int root,int l,int r)
{
        if(l==r)
        {
             node[root].MIN=num[l];
             return num[l];
        }
        int mid=(l+r)>>1;
        node[root].l=l;
        node[root].r=r;
        return node[root].MIN=min(
          build_tree1(root*2,l,mid),
          build_tree1(root*2+1,mid+1,r));
}
int build_tree2(int root,int l,int r)
{
        if(l==r)
        {
             node[root].MAX=num[l];
             return num[l];
        }
        int mid=(l+r)>>1;
        node[root].l=l;
        node[root].r=r;
        return node[root].MAX=max(
          build_tree2(root*2,l,mid),
          build_tree2(root*2+1,mid+1,r));
}

