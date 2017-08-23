# include <cstdio>
# include <cstring>
# include <iostream>
using namespace std;
const int P = 10000007;

long long n,k;

struct Mat {
       int n,m;
       long long v[2][2];       
       Mat ( int _n=0, int _m=0 ) : n(_n),m(_m) { memset ( v,0,sizeof(v) ); }
};

Mat operator *( Mat a, Mat b ) {
    Mat c( a.n,b.m );
    for ( int i = 0; i < a.n; ++i )
        for ( int j = 0; j < b.m; ++j )
            for ( int k = 0; k < a.m; ++k )
                c.v[i][j] += (a.v[i][k]*b.v[k][j])%P, c.v[i][j] %= P;
    return c;
}

Mat operator ^( Mat a, int k ) {
    Mat c ( a.n,a.m );
    for ( int i = 0; i < a.n; ++i ) c.v[i][i] = 1;
    while ( k ) {
          if ( k & 1 ) c = c*a;
          k >>= 1;
          a = a*a;    
    }  
    return c; 
}

int main () {
    cin >> n >> k;
    k %= P;
    if ( n == 1 || !k ) {
       cout << k << endl;
	   return 0;
    }
    Mat a ( 2,2 );
    Mat b ( 2,1 );
    if ( k-2<0 ) k+=P;
    a.v[0][0] = 0;
    a.v[0][1] = 1;
    a.v[1][0] = k-1;
    a.v[1][1] = k-2;
    b.v[0][0] = k;
    b.v[1][0] = 0;
    a = a^(n-1);
    b = a*b;
    cout << b.v[1][0] << endl;
    return 0;
}
