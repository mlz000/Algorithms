#include <cstdio>
#include <cstdlib>
#define oo 2147483647
int n,kk,m;
struct node
{
    int x,len,w,next;
}e[10010];
int k[110];
int tot;
int d[110][10000];
int f[1000000];
bool v[110];
void add(int a,int b,int c,int d){
     e[++tot].x=b;
     e[tot].len=c;
     e[tot].w=d;
     e[tot].next=k[a];
     k[a]=tot;
}
void spfa(){
     int head=0,tail=1;
     for (int i=2;i<=n;i++)
     for (int j=0;j<=kk;j++)
         d[i][j]=2147483;     
     v[1]=true;
     f[tail]=1;
     while (head<tail){
           int x=f[++head];
           v[x]=false;
           for (int t=k[x];t;t=e[t].next){
               int to=e[t].x;
               for (int i=e[t].w;i<=kk;i++){
                   if (d[to][i]>d[x][i-e[t].w]+e[t].len){
                       d[to][i]=d[x][i-e[t].w]+e[t].len;
                       if (!v[to]){
                                   v[to]=true;
                                   f[++tail]=to;
                       }
                   }
               }
           }
     }
}
int main(){
    scanf("%d%d%d",&kk,&n,&m);
    for (int i=1;i<=m;i++){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        add(a,b,c,d);
    }
    spfa();
    int max=oo;
    for (int i=0;i<=kk;i++)
        if (d[n][i]<max) max=d[n][i];
    if (max==oo) printf("-1\n");else printf("%d\n",max);
    //system("pause");
    return 0;
}
