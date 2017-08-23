#include<iostream>//Ä£ÄâÍË»ð
#include<cstring>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
const int N=1005;
const double Pi=acos(-1.0),inf=1e12;
double X,Y,M,x[N],y[N],px[15],py[15],dis[15];
inline double D(double x1,double y1,double x2,double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main(){
	int T;
	scanf("%d",&T);
	srand(time(0));
	while(T--){
		scanf("%lf%lf%lf",&X,&Y,&M);
		for(int i=1;i<=M;++i)	scanf("%lf%lf",&x[i],&y[i]);
		for(int i=1;i<=10;++i){
			px[i]=(double)(rand()%1000+1)/1000.0*X;
			py[i]=(double)(rand()%1000+1)/1000.0*Y;
			dis[i]=inf;
			for(int j=1;j<=M;++j)	dis[i]=min(dis[i],D(px[i],py[i],x[j],y[j]));
		}
		double delta=(X>=Y?X:Y)/sqrt(M);
		while(delta>1e-2){
			for(int i=1;i<=10;++i)
				for(int j=1;j<=30;++j){
					double ang=(rand()%1000+1)/1000.0*2.0*Pi;
					double tx=px[i]+cos(ang)*delta;
					double ty=py[i]+sin(ang)*delta;
					if(tx<0 || tx>X || ty<0 || ty>Y)	continue;
					double now=inf;
					for(int k=1;k<=M;++k)	now=min(now,D(tx,ty,x[k],y[k]));
					if(now>dis[i]){
						px[i]=tx;
						py[i]=ty;
						dis[i]=now;
					}
				}
			delta*=0.9;
		}
		int ans=1;	
		for(int i=2;i<=10;++i)	if(dis[i]>dis[ans])	ans=i;
		printf("The safest point is (%.1lf, %.1lf).\n",px[ans],py[ans]);
	}
	return 0;
}
