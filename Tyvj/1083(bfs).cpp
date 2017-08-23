#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stdio.h>
#include <cstring>
using namespace std;
int ans,n,l,r,c,m,p;
bool used[100001];
struct lk
{
       int d;
       lk *next;
};
struct queue
{
       int a,deep;
}q[100001];
lk *head[100001];
void insert(int a,int b)
{
     lk *p=new lk;
     p->d=b;
     p->next=head[a];
     head[a]=p;
}
void readdata()
{
     int i,j,a,b;
     scanf("%d %d %d\n%d\n",&n,&p,&c,&m);
     for (i=1;i<=p;i++)
     {
         scanf("%d %d\n",&a,&b);
         insert(a,b);
         insert(b,a);
     }    
     ans=0; 
}
void bfs()
{
     int i,j;
     queue now;
     lk *p;
     memset(q,0,sizeof(q));
     memset(used,0,sizeof(used));
     l=0;
     q[r=1].a=c;
     q[1].deep=1;
     used[c]=1;
     while (l<r)
     {
           now=q[++l];
           p=head[now.a];
           while (p)
           {
               if (!used[p->d])
               {
                   q[++r].a=p->d;
                   q[r].deep=now.deep+1;
                   used[p->d]=1;
                   if (ans<q[r].deep+m)
                   ans=q[r].deep+m;
               }
               p=p->next;
           }
     }
     printf("%d\n",ans);
}
int main(int argc, char *argv[])
{
    readdata();
    bfs();
   // system("pause");
    return 0;
}
