#include<iostream>//Ä£ÄâÍË»ð
#include<cstring>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
#define sqr(x)	((x)*(x))
const int N=305;
const double Pi=acos(-1.0),eps=1e-9,inf=1e10;
int n;
double r;
struct Point{
	double x,y,d;
}a[N],b[25],tmp,tmp1,tmp2;
double dis(double x1,double y1,double x2,double y2){
	return sqr(x1-x2)+sqr(y1-y2);
}
int dcmp(double x){
	if(x<eps)	return -1;
	return x>eps;
}
void calc(Point &p){
	p.d=inf;
	if(dcmp(sqr(p.x)+sqr(p.y)-r*r)>0){
		p.d=0;
		return;
	}
	for(int i=1;i<=n;++i)	p.d=min(p.d,dis(p.x,p.y,a[i].x,a[i].y));
}
int main(){
	while(~scanf("%d%lf",&n,&r)){
		for(int i=1;i<=n;++i)	scanf("%lf%lf",&a[i].x,&a[i].y);
		for(int i=1;i<=20;++i){
			double len=(rand()%100)/100.0*r;
			double ang=(rand()%100)/100.0*2.0*Pi;
			b[i].x=len*cos(ang);
			b[i].y=len*sin(ang);
			calc(b[i]);
		}
		double delta=r*2/sqrt(20.0);
		for(;delta>1e-7;delta*=0.6)
			for(int i=1;i<=20;++i)
				for(int j=1;j<=30;++j){
					double ang=(rand()%100)/100.0*2.0*Pi;
					tmp.x=b[i].x+delta*cos(ang);
					tmp.y=b[i].y+delta*sin(ang);
					calc(tmp);
					if(tmp.d>b[i].d)	b[i]=tmp;
				}
		double ans=0.0;
		for(int i=1;i<=20;++i)	ans=max(ans,b[i].d);
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j){
				double A,B,C,d,s,xx,yy;
				A=2*(a[i].x-a[j].x),B=2*(a[i].y-a[j].y),C=sqr(a[j].x)+sqr(a[j].y)-sqr(a[i].x)-sqr(a[i].y);
				s=A*A+B*B;
				d=r*r*s-sqr(C);//d=d*(A^2+B^2)
				if(d+eps<0)	continue;
				if(d<eps)	d=0;
				else d=sqrt(d);
				if(s==0)	continue;
				xx=-A*C;
				yy=-B*C;
				tmp1.x=(xx+B*d)/s,tmp1.y=(yy-A*d)/s;
				tmp2.x=(xx-B*d)/s,tmp2.y=(yy+A*d)/s;
				calc(tmp1);
				ans=max(ans,tmp1.d);
				calc(tmp2);
				ans=max(ans,tmp2.d);
			}
		for(int i=1;i<=n;++i){
			double d=sqrt(sqr(a[i].x)+sqr(a[i].y));
			if(dcmp(d)<=0)	continue;
			tmp.x=a[i].x*r/d;
			tmp.y=a[i].y*r/d;
			calc(tmp);
			ans=max(ans,tmp.d);
			tmp.x=-tmp.x;
			tmp.y=-tmp.y;
			calc(tmp);
			ans=max(ans,tmp.d);
		}
		printf("%.8lf\n",sqrt(ans));
	}
	return 0;
}
