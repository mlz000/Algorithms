#include<iostream>
#include<stack> 
#include<cstdio> 
#include<cstring> 
#include<climits> 
#include<algorithm>
using namespace std; 
const int N=100005;
bool flag[40]; 
char s[5]; 
struct data
{
  int l;
  int r;
  int col; 
}tree[N*4]; 
void build_tree(int root,int l,int r)
{
  tree[root].l=l;
  tree[root].r=r;
  tree[root].col=1;
  if(l==r) return; 
  int mid=(l+r)>>1;
  build_tree(root*2,l,mid);
  build_tree(root*2+1,mid+1,r); 
} 
void color(int root,int l,int r,int col)
{
   if(l==tree[root].l && r==tree[root].r)
   {
      tree[root].col=col;
      return; 
   } 
   if(tree[root].col==col) return;
   if(tree[root].col>=1) //�ڵ���ɫ����1��ֱ�Ӹ���-1�������ӽڵ�
   {
     tree[root*2].col=tree[root].col;
     tree[root*2+1].col=tree[root].col;
     tree[root].col=-1; 
   } 
   int mid=(tree[root].l+tree[root].r)>>1; 
   if(r<=mid) color(root*2,l,r,col);
   else if(l>mid) color(root*2+1,l,r,col);
   else 
   {
     color(root*2,l,mid,col);
     color(root*2+1,mid+1,r,col); 
   } 
} 
void ask(int root,int l,int r)
{
    if(tree[root].col>0)//ֻ��һ����ɫ��ֱ�Ӹ���
    {
      flag[tree[root].col]=true;
      return; 
    } 
   int mid=(tree[root].l+tree[root].r)>>1; 
   if(r<=mid) ask(root*2,l,r);
   else if(l>mid) ask(root*2+1,l,r);
   else 
   {
     ask(root*2,l,mid);
     ask(root*2+1,mid+1,r); 
   } 
} 
int main()
{
     int i,j,l,t,o; 
     scanf("%d%d%d",&l,&t,&o); 
     build_tree(1,1,l); 
     int x,y,c; 
     for(i=1;i<=o;++i)
     {
       int sum=0; 
       memset(flag,false,sizeof(flag));
       scanf("%s",s);
       if(s[0]=='C')
       {
        scanf("%d%d%d",&x,&y,&c);
        if(x>y) swap(x,y);
        color(1,x,y,c);        
       } 
       else if(s[0]=='P')
       {
         scanf("%d%d",&x,&y);
         if(x>y) swap(x,y); 
         ask(1,x,y); 
         for(j=1;j<=t;++j)
          if(flag[j])  sum++;
         printf("%d\n",sum);  
       } 
     } 
     //system("pause"); 
     return 0;
}

