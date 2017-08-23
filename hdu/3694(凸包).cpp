#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const double eps = 1e-8;
double x[10], y[10];
struct Point{
    double x;
    double y;
    Point(double p=0,double q=0):x(p),y(q) {}
}p[10], ch[10];
double D(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y -b.y));
}
double dot(Point p,Point q){
    return p.x*q.x+p.y*q.y;
}
double Cross(Point p,Point q){
    return p.x*q.y-p.y*q.x;
}
Point operator - (Point p,Point q){
    return Point(p.x-q.x,p.y-q.y);
}
Point operator + (Point p,Point q){
    return Point(p.x+q.x,p.y+q.y);
}
Point operator * (Point p,double q){
    return Point(p.x*q,p.y*q);
}
Point operator / (Point p,double q){
    return Point(p.x/q,p.y/q);
}
Point rot(Point p,double rad){
    return Point(p.x*cos(rad)-p.y*sin(rad),p.x*sin(rad)+p.y*cos(rad));
}
int dcmp(double x){
    if(fabs(x)<eps) return 0;
    else return x<0?-1:1;
}
bool operator < (const Point &p,const Point &q){
    return p.x<q.x || (p.x==q.x && p.y<q.y);
}
bool operator == (const Point p,const Point q){
    return (dcmp(p.x-q.x)==0 && dcmp(p.y-q.y)==0);
}
int convexhull(int n,Point p[],Point ch[]){
    sort(&p[1],&p[n+1]);
    int m=0;
    for(int i=1;i<=n;++i)
    {
        while(m>=2 && Cross(ch[m]-ch[m-1],p[i]-ch[m])<=0) m--;
        ch[++m]=p[i];
    }
    int k=m;
    for(int i=n-1;i>=1;--i)
    {
        while(m>k && Cross(ch[m]-ch[m-1],p[i]-ch[m])<=0) m--;
        ch[++m]=p[i];
    }
    return m;
}
int main() {
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &p[1].x, &p[1].y, &p[2].x, &p[2].y, &p[3].x, &p[3].y, &p[4].x, &p[4].y)) {
        bool f = 0;
        for (int i = 1; i <= 4; ++i)    
            if (p[i].x != -1 || p[i].y != -1)    f = 1;
        if (!f)    break;
        int m = convexhull(4,p,ch);
        double dis = 1000000.0;
        for (int i = 1; i <= 4; ++i)
            for (int j = 1; j <= 4; ++j)
                if (i != j && p[i].x == p[j].x && p[i].y == p[j].y)    m = 1;
        if (m == 5) {
            dis = D(ch[1], ch[3]) + D(ch[2], ch[4]);
        }
        else {
            for (int i = 1; i <= 4; ++i) {
                double now = 0.0;
                for (int j = 1; j <= 4; ++j)
                    if (i != j) {
                        now += D(p[i], p[j]);
                    }
                dis = min(now, dis);
            }
        }
        printf("%.4lf\n", dis);
    }
    return 0;
}
