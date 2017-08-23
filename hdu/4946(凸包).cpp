#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
const int maxn=505;
int x[maxn],y[maxn],v[maxn];
struct node {
    int x,y,num,v;
} a[maxn],b[maxn];
int q[maxn];
bool f[maxn],ans[maxn],is[maxn];
int pre,ed,zz,i,j,k,m,n,tot;

bool cmp(const node &a,const node &b) {
    return (a.x<b.x || a.x==b.x && a.y<b.y);
}
int cross(int x1,int y1,int x2,int y2) {
    return x1*y2-x2*y1;
}
bool check(int p,int q,int r) {
    int ax=a[q].x-a[p].x,ay=a[q].y-a[p].y;
    int bx=a[r].x-a[p].x,by=a[r].y-a[p].y;
    return (cross(ax,ay,bx,by)<0);
}
void tbao() {
    int i,j,k,h,t;
    q[t=1]=1;
    for (i=2;i<=tot;i++) {
        while (t>1 && check(q[t-1],q[t],i)) t--;
        q[++t]=i;
    }
    for (i=1;i<=t;i++)
        is[q[i]]=true;
    q[t=1]=tot;
    for (i=tot-1;i>=1;i--) {
        while (t>1 && check(q[t-1],q[t],i)) t--;
        q[++t]=i;
    }
    for (i=1;i<=t;i++)
        is[q[i]]=true;
}
int main(){
    scanf("%d",&n);
    while (n) {
        m=0;
        memset(ans,true,sizeof(ans));
        memset(is,0,sizeof(is));
        for(i=1;i<=n;++i) {
            scanf("%d%d%d",&x[i],&y[i],&v[i]);
            m=max(m,v[i]);
        }
        printf("Case #%d: ",++zz);
        if (m==0) {
            for (i=1;i<=n;i++) printf("0");
            puts("");
            scanf("%d",&n);
            continue;
        }
        tot=0;
        for (i=1;i<=n;i++)
            if (v[i]==m) {
                tot++;
                a[tot].x=x[i];a[tot].y=y[i];
                a[tot].v=v[i];
                a[tot].num=i;
            }
        sort(a+1,a+tot+1,cmp);
        a[tot+1].x=100000000;a[tot+1].y=100000000;
        pre=m=0;
        for (i=1;i<=tot;i++)
            if (a[i].x!=a[i+1].x || a[i].y!=a[i+1].y) {
                m++;
                b[m].x=a[i].x;b[m].y=a[i].y;b[m].num=a[i].num;
                if (i-pre>1) for (j=pre+1;j<=i;j++) ans[a[j].num]=false;
                pre=i;
            }
        tot=m;
        for (i=1;i<=tot;i++) a[i]=b[i];
        tbao();
        memset(f,0,sizeof(f));
        for (i=1;i<=tot;i++)
            if (ans[a[i].num] && is[i]) f[a[i].num]=true;
        for (i=1;i<=n;i++)
            if (f[i]) printf("1");else printf("0");
        printf("\n");
        scanf("%d",&n);
    }
    return 0;
}
