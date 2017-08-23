 #include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int num[100001];
struct
{
    int l;
    int r;
    int sum;
}node[400000];
int build_tree(int root,int l,int r);
int answer(int root,int a,int b);
int main()
{
       int i,a,b,m,n;
       scanf("%d%d",&m,&n);
       for(i=1;i<=m;++i)
       {
         scanf("%d",&num[i]);
       }
       build_tree(1,1,m);
       for(i=1;i<=n;++i)
       {
            scanf("%d%d",&a,&b);
            printf("%d ",answer(1,a,b));
       }
       //system("pause");
       return 0;
}
int answer(int root,int a,int b)
{
    int x=999999999;
    int y=999999999;
    int l=node[root].l;
    int r=node[root].r;
    int mid=(l+r)>>1;
    if((l>=a&&r<=b)||l==r) return node[root].sum; 
    if(mid>=a)   x=answer(root*2,a,b);
    if(mid+1<=b) y=answer(root*2+1,a,b);
    return min(x,y);
} 
int build_tree(int root,int l,int r)
{
        if(l==r)
        {
             node[root].sum=num[l];
             return node[root].sum;
        }
        int mid=(l+r)>>1;
        node[root].l=l;
        node[root].r=r;
        return node[root].sum=min(
          build_tree(root*2,l,mid),
          build_tree(root*2+1,mid+1,r));
}
