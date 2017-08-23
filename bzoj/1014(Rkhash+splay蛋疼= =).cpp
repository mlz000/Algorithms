#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath> 
#include<cstring>
using namespace std;
typedef unsigned long long ull;
#define keytree (ch[ch[root][1]][0])
const int N=101000;
ull p[N]={1};
int num[N],n;
char s[N];
struct splay_tree
{
      int ch[N][2],pre[N],sz[N],val[N],root,tot;
      ull hash[N];
      inline void update(int x)
      {
            if(x==0)    return; 
            sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
            hash[x]=hash[ch[x][0]]*p[sz[ch[x][1]]+1]+val[x]*p[sz[ch[x][1]]]+hash[ch[x][1]]; //Rkhash
      }
      inline void insert(int &x,int c)
      {
            x=++tot;
            ch[x][0]=ch[x][1]=pre[x]=0;
            val[x]=c;
            sz[x]=1;
      }
      inline void init()
      {
            root=tot=ch[0][0]=ch[0][1]=pre[0]=0;
            insert(root,-1);
            insert(ch[root][1],-1);
            pre[tot]=root;
            sz[root]=2;
            for(int i=1;i<N;++i)     p[i]=p[i-1]*27;//27½øÖÆ
            scanf("%s",s);
            n=strlen(s);
            for(int i=1;i<=n;++i)     num[i]=s[i-1]-'a'+1;  
            build_tree(keytree,1,n,ch[root][1]); 
            update(ch[root][1]),update(root); 
      }
      inline void build_tree(int &x,int l,int r,int f)
      {
            if(l>r)     return;
            int mid=(l+r)>>1;
            insert(x,num[mid]);
            build_tree(ch[x][0],l,mid-1,x);
            build_tree(ch[x][1],mid+1,r,x);
            pre[x]=f;
            update(x);
      }
      inline void rotate(int x,int c)//c=0 ×óÐý,c=1 ÓÒÐý
      {
            int y=pre[x];
            ch[y][!c]=ch[x][c];
            if(ch[x][c])      pre[ch[x][c]]=y;
            pre[x]=pre[y]; 
            if(pre[y])  ch[pre[y]][ch[pre[y]][1]==y]=x;
            ch[x][c]=y;
            pre[y]=x;
            update(y); 
            if(y==root) root=x;
      } 
      inline void splay(int x,int f)
      {
            while(pre[x]!=f)
            {
                  if(pre[pre[x]]==f)      rotate(x,ch[pre[x]][0]==x);//µ¥Ðý 
                  else 
                  {
                        int y=pre[x];int z=pre[y];
                        int c=(ch[z][0]==y);
                        if(ch[y][c]==x)   rotate(x,!c),rotate(x,c);
                        else rotate(y,c),rotate(x,c);
                  }
            }
            update(x);
            if(f==0)    root=x;
      }
      inline void select(int k,int f)
      {
            int x=root;k++;
            while(1)
            {
                  if(k==sz[ch[x][0]]+1)   break;
                  if(k<=sz[ch[x][0]])     x=ch[x][0];
                  else k-=sz[ch[x][0]]+1,x=ch[x][1];
            }
            splay(x,f);
      }
      bool check(int p,int q,int l)
      {
        ull hash1,hash2;
        if(q+l-1>n)     return false;
        select(p-1,0);select(p+l,root);    
        hash1=hash[keytree];
        select(q-1,0);select(q+l,root);
        hash2=hash[keytree];
        return (hash1==hash2);
      }
      int find(int p,int q,int l,int r)
      {
          while(l<r)
          {
             int mid=(l+r)>>1;
             if(check(p,q,mid)) l=mid+1;
             else r=mid;
          }
          return l-1;
      }
      inline void change(int pos,int c)   {select(pos-1,0);select(pos+1,root);val[keytree]=c;splay(keytree,0);}
      inline void add(int pos,int c)
      {
            select(pos,0);
            select(pos+1,root);
            num[1]=c; 
		build_tree(keytree,1,1,ch[root][1]);
            update(ch[root][1]);
            update(root);
      }
}spt;
void work()
{
      char s1[10],s2[10];
      int m;
      scanf("%d",&m);
      while(m--)
      {
            scanf("%s",s1);
            if(s1[0]=='Q')
            {
                int a,b;
                scanf("%d%d",&a,&b);
                if(a>b) swap(a,b);
                printf("%d\n",spt.find(a,b,0,n));
            }
            else if(s1[0]=='R')
            {
                int a;  
                scanf("%d %s",&a,s2);
                spt.change(a,s2[0]-'a'+1);
            }
            else 
            {
                int a;
                scanf("%d %s",&a,s2);
                spt.add(a,s2[0]-'a'+1); 
                ++n; 
            }
      }
}
int main()
{
      spt.init();
      work();
      return 0; 
} 
