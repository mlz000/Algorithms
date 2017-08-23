#include<cstdio> 
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=100005*2;
int A[N],ans[N],rank[N],wa[N],wb[N],ww[N],wv[N],sa[N];
bool cmp(int *r,int a,int b,int l)
{
    return(r[a]==r[b] && r[a+l]==r[b+l]);
}
void da(int *r,int *sa,int n,int m)
{
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;++i)    ww[i]=0;
    for(i=0;i<n;++i)    ww[x[i]=r[i]]++;
    for(i=1;i<m;++i)    ww[i]+=ww[i-1];
    for(i=n-1;i>=0;--i) sa[--ww[x[i]]]=i;
    for(j=p=1;p<n;j<<=1,m=p)
    {
        for(p=0,i=n-j;i<n;++i)  y[p++]=i;
        for(i=0;i<n;++i)    if(sa[i]>=j)    y[p++]=sa[i]-j;
        for(i=0;i<n;++i)    wv[i]=x[y[i]];
        for(i=0;i<m;++i)    ww[i]=0;
        for(i=0;i<n;++i)    ww[wv[i]]++;
        for(i=1;i<m;++i)    ww[i]+=ww[i-1];
        for(i=n-1;i>=0;--i) sa[--ww[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;++i)
        x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
    return ;
}
int main()
{
    int i,n,m;
    char ch;
    n=0;
    while(scanf("%c",&ch)!=EOF)if(ch=='\n')break;else A[n++]=ch;
    m=2*n-1;
    for(i=n;i<m;++i)    A[i]=A[i-n];
    da(A,sa,m+1,256);
    for(i=0;i<=m;++i)    rank[sa[i]]=i;
    for(i=0;i<n;++i)    ans[rank[i]]=A[i+n-1];
    for(i=0;i<=m;++i)   if(ans[i]) printf("%c",ans[i]);
    return 0;
}
