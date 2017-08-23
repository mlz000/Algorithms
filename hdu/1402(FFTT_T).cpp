#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<complex>
using namespace std;
const int N=1<<18;
const double Pi=acos(-1.0);
typedef complex<double> CP;
using namespace std;
CP a[N],b[N],c[N],A[N],B[N],C[N];
int out[N];
char s[N];
int n;
void fft(CP *a,CP *A,int n,bool flag)
{
    int lg2n = int(log(double(n))/log(2.0)+0.5);
    for(int i=0;i<n;++i)
    {
        int x=0;
        for(int j=0;j<lg2n;++j) if(i&(1<<j))    x+=(1<<(lg2n-1-j));
        A[x]=a[i];//×ªÖÃ 
    }
    for(int i=1;i<=lg2n;++i)
    {
        int m=1<<i;
        double p=2.0*(flag?1:-1)*Pi/m;
        CP wm(cos(p),sin(p));
        for(int j=0;j<n;j+=m)
        {
            CP w(1);
            for(int k=0;k<m/2;++k)
            {
                CP t=w*A[j+k+m/2];
                A[j+k+m/2]=A[j+k];
                A[j+k]+=t;
                A[j+k+m/2]-=t;
                w*=wm;
            }
        }
    } 
    if(!flag)   for(int i=0;i<n;++i)    A[i]/=(double)n;
}
bool init()
{
    if(scanf("%s",s)!=1)    return false;
    int l1=strlen(s),i;
    reverse(s,s+l1);
    for(i=0;i<l1;++i)   a[i]=CP(s[i]-'0',0.0);
    scanf("%s",s);
    int l2=strlen(s);
    reverse(s,s+l2);
    for(i=0;i<l2;++i)   b[i]=CP(s[i]-'0',0.0);
    n=1;
    while(l1*2>n || l2*2>n) n<<=1;
    for(i=l1;i<n;++i)   a[i]=CP(0.0,0.0);
    for(i=l2;i<n;++i)   b[i]=CP(0.0,0.0);
    for(i=0;i<n;++i)    c[i]=C[i]=A[i]=B[i]=CP(0.0,0.0);
    return true;
}
int main()
{
    while(init())
    {
        int i;
        fft(a,A,n,true);
        fft(b,B,n,true);
        for(i=0;i<n;++i)    c[i]=A[i]*B[i];
        fft(c,C,n,false);   
        memset(out,0,sizeof(out));
        for(i=0;i<n;++i)
        {
            int x=(int)round(real(C[i]));
            out[i]+=x;
            out[i+1]+=out[i]/10;
            out[i]%=10;
        }
        while(n>1 && !out[n-1]) --n;
        for(i=n-1;i>=0;--i) printf("%d",out[i]);
        printf("\n");
    }
    return 0;
}
