#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath> 
#include<cstring>
using namespace std;
const int N=10005;
const double eps=1e-14;
double n,e,s[N],k[N],v_[N],v[N],maxv[N];
double calc(double lamda)
{
      double sum=0;
      for(int i=1;i<=n;++i)
      {
            double L=v_[i]>0?v_[i]:0;
            double R=1e10;
            double MID;
            while(L+eps<R)
            {
                  MID=(L+R)/2;
                  if(2*lamda*k[i]*(MID-v_[i])*MID*MID<=1)     L=MID;
                  else R=MID;
            }
            v[i]=MID;
            sum+=k[i]*s[i]*(v[i]-v_[i])*(v[i]-v_[i]);
      }
      return sum;
}
int main()
{
      scanf("%lf%lf",&n,&e);
      double l=0,r=100000,mid;
      int i;
      for(i=1;i<=n;++i) scanf("%lf%lf%lf",&s[i],&k[i],&v_[i]);
      while(l+eps<r)
      {
            mid=(l+r)/2;
            if(calc(mid)<=e)  r=mid;
            else l=mid;
      }
      double ans=0;
      for(i=1;i<=n;++i) ans+=s[i]/v[i];
      printf("%.8lf",ans);
      return 0; 
} 
