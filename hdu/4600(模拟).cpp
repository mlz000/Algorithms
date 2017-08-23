#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1005;
int T,w,h,a,d,y,q[N],p[N],n[N],m[N],num[10],numx[10];
long long ans,val[N];
inline long long min(long long x,long long y)	{return x<=y?x:y;}
void init(){
	scanf("%d%d%d%d%d",&w,&h,&a,&d,&y);
	for(int i=1;i<=a;++i)	scanf("%d%d%d%d",&q[i],&p[i],&n[i],&m[i]);
	ans=y;
	memset(num,0,sizeof(num));
	num[9]=(w/3)*(h/3);//×óÉÏ½Ç¸²¸Ç3*3
	int ww=w%3,hh=h%3;
	num[9-(3-ww)*(3-hh)]++;//ÓÒÏÂ½Ç
	num[3*hh]+=w/3-1;//×óÏÂ½Ç
	num[3*ww]+=h/3-1;//ÓÒÉÏ½Ç
	num[ww*hh]+=2;//Ê£Óà²¿·Ö
}
long long solve1(int x){
	if(n[x]>d)	return y;
	int tottime=d;
    int tot=0;
	long long sum=y;
	while(n[x]<=tottime){
		for(int i=9;i>=1;--i){
			if(i*p[x]>q[x]){
				int tmp=min(num[i],sum/q[x]);
				tot+=i*tmp;
				sum-=q[x]*tmp;
			}
			else break;
		}
		sum+=tot*p[x];
		tot=0;
		tottime-=n[x];
	}
	return sum;
}
long long solve2(int x) {  
    memset(val, 0, sizeof(val));
	memset(numx,0,sizeof(numx));
    long long sum=y;  
	for(int i=1;i<=9;++i)	numx[i]=num[i];
    for(int i=0;i<=d;++i){  
        sum+=val[i];  
		long long tot=sum/q[x];
        for(int j=9;j>=1;--j) if(numx[j]){  
            int to=i+n[x];  
            if(to>d)    break;  
            long long now=(long long)(1+(d-to)/m[x])*j*p[x];  
            if(now>q[x]){  
                long long get=min(tot,numx[j]);
                numx[j]-=(int)get;  
				tot-=get;
                sum-=get*q[x];  
                val[to]+=get*j*p[x];  
                for(int k=to+m[x];k<=d;k+=m[x])    val[k]+=get*j*p[x];  
            }  
            else	break;  
        }  
    }  
    return sum;
}   
void solve(){
	for(int i=1;i<=a;++i){
		if(m[i]==0)	ans=max(ans,solve1(i));
		else ans=max(ans,solve2(i));
	}
	printf("%I64d\n",ans);
}
int main(){
	scanf("%d",&T);
	while(T--){
		init();
		solve();
	}
	return 0;
}
		  
