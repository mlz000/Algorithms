const double eps = 1e-12;
const double Pi = acos(-1.0);
struct Point{
	double x;
	double y;
	Point(double p = 0, double q = 0) : x(p), y(q) {}
};
typedef Point Vector;
double dot(Point p, Point q){
	return p.x * q.x + p.y * q.y;
}
double Cross(Point p, Point q){
    return p.x * q.y - p.y * q.x;
}
Point operator - (Point p, Point q){
	return Point(p.x - q.x, p.y - q.y);
}
Point operator + (Point p, Point q){
	return Point(p.x + q.x, p.y + q.y);
}
Point operator * (Point p, double q){
	return Point(p.x * q, p.y * q);
}
Point operator / (Point p, double q){
	return Point(p.x / q, p.y / q);
}
Point rot(Point p, double rad){
	return Point(p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad));
}
int sgn(double x){
    if(fabs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}
bool operator < (const Point &p, const Point &q){
    return p.x < q.x || (p.x == q.x && p.y < q.y);
}
bool operator == (const Point p, const Point q){
	return (dcmp(p.x - q.x) == 0 && dcmp(p.y - q.y) == 0);
}
inline bool is_on(const Point &a,const Point &b,const Point &c) {
	return !sgn((b - a) % (c - a)) && sgn((a.x - b.x) * (a.x - c.x)) <= 0 && sgn((a.y - b.y) * (a.y - c.y)) <= 0;
}
double torad(double rad) {return rad * Pi / 180;}
double len(Point x) {return sqrt(dot(x,x));}
double ang(Point p, Point q) {return acos(dot(p, q) / len(p) / len(q));}
double S(Point x, Point y, Point z) {return Cross(z - x, y - x);}
Point intersection (const Point &a, const Vector &b, const Point &c, const Vector &d) {
	Vector u = a - c;
	double t = (d % u) / (b % d);
	return a + b * t;
}
Point inter(Point a, Point b, Point c) {//三角形外接圆
	Line u, v;
	u.a.x = (a.x + b.x) * 0.5;
	u.a.y = (a.y + b.y) * 0.5;
	u.b.x = u.a.x - (u.a.y - a.y);
	u.b.y = u.a.y + (u.a.x - a.x);
	v.a.x = (a.x + c.x) * 0.5;
	v.a.y = (a.y + c.y) * 0.5;
	v.b.x = v.a.x - (v.a.y - a.y);
	v.b.y = v.a.y + (v.a.x - a.x);
	return intersection(u.a, u.b - u.a, v.a, v.b - v.a);
}
int convexhull(int n,Point p[],Point ch[])//凸包 {
    sort(&p[1],&p[n+1]);
    int m=0;
    for(int i=1;i<=n;++i){
        while(m>=2 && Cross(ch[m]-ch[m-1],p[i]-ch[m])<=0) m--;
        ch[++m]=p[i];
    }
    int k=m;
    for(int i=n-1;i>=1;--i){
        while(m>k && Cross(ch[m]-ch[m-1],p[i]-ch[m])<=0) m--;
        ch[++m]=p[i];
    }
    return m;
}
vector<Point> convexhull(vector<Point>& p){
    sort(p.begin(),p.end());
    p.erase(unique(p.begin(),p.end()),p.end());
    int n=p.size();
    vector<Point> ch(n+1);
    int m=0;
    for(int i=0;i<n;++i){
        while(m>1 && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
        ch[m++]=p[i];
    }
    int k=m;
    for(int i=n-2;i>=0;--i){
        while(m>k && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
        ch[m++]=p[i];
    }
    if(n>1) m--;
    ch.resize(m);
    return ch;
}
int cnt(vector<Point>& point){//卡壳 
    vector<Point> p=convexhull(point);
    int ans=0;
    int n=p.size();
    if(n==1) return 0;
    if(n==2) return dis(p[0],p[1]);
    p.pb(p[0]);
    for(int u=0,v=1;u<n;++u){
        for(;;){
            //S(p[u],p[u+1],p[v+1])<=S(p[u],p[u+1],p[v]) stop
            //Cross(p[u+1]-p[u],p[v+1]-p[u])<=Cross(p[u+1]-p[u],p[v]-p[u])  
            //Cross(p[u+1]-p[u],p[v+1]-p[v])<=0;
            int tmp=Cross(p[u+1]-p[u],p[v+1]-p[v]);
            if(tmp<=0){  //stop
                ans=max(ans,dis(p[u],p[v]));
                if(tmp==0)  ans=max(ans,dis(p[u],p[v+1]));
                break; 
            }
            v=(v+1)%n;
        }
    } 
    return ans;
}
struct Sipmson////自适应simpson
{
	double f(double x)
	{
		int j,tot=0;  
   	    double ret=0,dis,l,r; 
		for(int i=st;i<=ed;++i)
		{
			if(x<=xl[i] || x>=xr[i])	continue;
			dis=sqrt(list[i].r-sqr(list[i].x-x));
			seg[++tot]=make_pair(list[i].y-dis,list[i].y+dis);
		}
		sort(seg+1,seg+1+tot);
		for(int i=1;i<=tot;++i)
		{
			l=seg[i].first,r=seg[i].second;
			for(j=i+1;j<=tot;++j)
			{
				if(seg[j].first>r)	break;
				else r=max(r,seg[j].second);
			}
			ret+=r-l;i=j-1;
		}
		return ret;
	}
	double calc(double s,double fl,double fr,double fmid){
		return (fl+fr+4*fmid)*s/6;
	}
	double simpson(double l,double mid,double r,double fl,double fmid,double fr,double tot)
	{
		double m1=(l+mid)*0.5,m2=(mid+r)*0.5;
		double fm1=f(m1),fm2=f(m2);
		double tmp1=calc(mid-l,fl,fmid,fm1),tmp2=calc(r-mid,fmid,fr,fm2);
		if(fabs(tmp1+tmp2-tot)<=eps)	return tmp1+tmp2;
		else return simpson(l,m1,mid,fl,fm1,fmid,tmp1)+simpson(mid,m2,r,fmid,fm2,fr,tmp2);
	}
	void solve()
	{
		int j;
		sort(list+1,list+1+n,cmp2);
		for(int i=1;i<=n;++i)	xl[i]=list[i].x-list[i].r,xr[i]=list[i].x+list[i].r,list[i].r*=list[i].r;
		double l,r,mid,fl,fr,fmid;
		double ans=0;
		for(int i=1;i<=n;++i)
		{
			l=xl[i],r=xr[i];
			for(j=i+1;j<=n;++j)
			{
				if(xl[j]>r)	break;
				else r=max(xr[j],r);
			}
			mid=(l+r)*0.5;
			st=i,ed=j-1,i=j-1;
			fl=f(l),fmid=f(mid),fr=f(r);
			ans+=simpson(l,mid,r,fl,fmid,fr,calc(r-l,fl,fr,fmid));
		}
	}
}

