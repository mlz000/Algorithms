#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;
struct Point
{
	int x;
	int y;
	Point(int p=0,int q=0):x(p),y(q) {}
};
typedef Point Vector;
int Cross(Point p,Point q)
{
    return (p.x*q.y-p.y*q.x);
}
Point operator - (Point p,Point q)
{
	return Point(p.x-q.x,p.y-q.y);
}
Point operator + (Point p,Point q)
{
	return Point(p.x+q.x,p.y+q.y);
}
bool operator < (const Point &p,const Point &q)
{
    return p.x<q.x || (p.x==q.x && p.y<q.y);
}
bool operator == (const Point p,const Point q)
{
	return (p.x==q.x && p.y==q.y);
}
int dis(const Point p,const Point q)
{
    return ((p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y));
}
vector<Point> convexhull(vector<Point>& p)
{
    sort(p.begin(),p.end());
    p.erase(unique(p.begin(),p.end()),p.end());
    int n=p.size();
    vector<Point> ch(n+1);
    int m=0;
    for(int i=0;i<n;++i)
    {
        while(m>1 && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
        ch[m++]=p[i];
    }
    int k=m;
    for(int i=n-2;i>=0;--i)
    {
        while(m>k && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
        ch[m++]=p[i];
    }
    if(n>1) m--;
    ch.resize(m);
    return ch;
}
int cnt(vector<Point>& point)
{ 
    vector<Point> p=convexhull(point);
    int ans=0;
    int n=p.size();
    if(n==1) return 0;
    if(n==2) return dis(p[0],p[1]);
    p.pb(p[0]);
    for(int u=0,v=1;u<n;++u)
    {
        for(;;)
        {
            //S(p[u],p[u+1],p[v+1])<=S(p[u],p[u+1],p[v]) stop
            //Cross(p[u+1]-p[u],p[v+1]-p[u])<=Cross(p[u+1]-p[u],p[v]-p[u])    
            //Cross(p[u+1]-p[u],p[v+1]-p[v])<=0;
            int tmp=Cross(p[u+1]-p[u],p[v+1]-p[v]);
            if(tmp<=0)  //stop
            {
                ans=max(ans,dis(p[u],p[v]));
                if(tmp==0)  ans=max(ans,dis(p[u],p[v+1]));
                break; 
            }
            v=(v+1)%n;
        }
    } 
    return ans;
}
int main()
{
	int n,T;
    scanf("%d",&T);
	while(T--)
	{
        vector<Point> point;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            int x,y,w;
            scanf("%d%d%d",&x,&y,&w);
            point.pb(Point(x,y));
            point.pb(Point(x,y+w));
            point.pb(Point(x+w,y));
            point.pb(Point(x+w,y+w));
        }
        printf("%d\n",cnt(point));
    }
    //system("pause");
    return 0;
}
