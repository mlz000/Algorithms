#include<cstdio>//计算几何 
#include<iostream>
#include<cstring> 
#include<cmath> 
#include<algorithm>
using namespace std;
double x[3],y[3],d[3],ang[3]; 
double Pi=acos(-1); 
double cnt(double a,double b,double c)
{
     double p=(a+b+c)/2;
     double s=sqrt(p*(p-a)*(p-b)*(p-c)); //海伦公式求面积 
     return a*b*c/(4*s); //正弦定理求半径 
} 
double fgcd(double a,double b)
{
    if(fabs(a)<1E-3) return b; 
    if(fabs(b)<1E-3) return a;
    return fgcd(b,fmod(a,b));//最大公约数，fmod返回余数 
} 
int main() 
{
	  int i; 
      for(i=0;i<3;++i)
       scanf("%lf%lf",&x[i],&y[i]);
      for(i=0;i<3;++i)
        d[i]=sqrt((x[i]-x[(i+1)%3])*(x[i]-x[(i+1)%3])+(y[i]-y[(i+1)%3])*(y[i]-y[(i+1)%3])); //计算三角形三边长 
      double r=cnt(d[0],d[1],d[2]);  
      for(i=0;i<=1;++i)
       ang[i]=acos(1-d[i]*d[i]/(2*r*r));
      ang[2]=2*Pi-ang[0]-ang[1];
      double angle=fgcd(ang[0],fgcd(ang[1],ang[2])); 
      printf("%.10lf",r*r* (2*Pi/angle)*sin(angle)/2); 
     // system("pause"); 
      return 0; 
}
 
