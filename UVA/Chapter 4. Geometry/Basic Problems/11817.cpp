#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const double R = 6371009.0;
const double PI = acos(-1);
struct Point
{
	double x, y, z;
	Point(double x = 0, double y = 0, double z = 0): x(x), y(y), z(z) {};
};
double torad(double rad)
{
	return rad/180 * PI;
}
Point A, B;
void get_coord(double R, double lat, double lng, Point &P) //lat Î³¶È, lng ¾­¶È 
{
	lat = torad(lat);
	lng = torad(lng);
	P.x = R*cos(lat)*cos(lng);
	P.y = R*cos(lat)*sin(lng);
	P.z = R*sin(lat);
}
double lat, lng;
double Dist3D(Point A, Point B)
{
	return sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y) + (A.z-B.z) * (A.z-B.z));
}
double GetDistance(double d)
{
	return 2*asin(d/(2*R))*R;
}
void read_case()
{
	scanf("%lf %lf", &lat, &lng);
	get_coord(R, lat, lng, A);
	scanf("%lf %lf", &lat, &lng);
	get_coord(R, lat, lng, B);
}
void solve()
{
	read_case();
	double d = Dist3D(A, B);
	double ans = GetDistance(d) - d;
	printf("%.0lf\n", ans);
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		solve();
	}
	return 0;
}
