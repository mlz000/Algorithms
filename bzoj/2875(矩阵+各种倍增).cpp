#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
typedef unsigned long long Ull; 
using namespace std;
Ull m,a,c,x0,n,g;
Ull calc(Ull x,Ull y)//³Ë·¨±¶Ôö 
{
    Ull tmp=0;
    for(;y;y>>=1)
    {
        if(y&1) tmp=(tmp+x)%m;
        x=(x<<1)%m;
    }
    return tmp;
}
struct Matrix  //¾ØÕó±¶Ôö 
{
    Ull num[2][2];
    Matrix operator *(const Matrix &b)
    {
        Matrix tmp;
        for(int i=0;i<=1;++i)
         for(int j=0;j<=1;++j)
         {
            tmp.num[i][j]=0;
            for(int k=0;k<=1;++k)
             tmp.num[i][j]=(tmp.num[i][j]+calc(num[i][k],b.num[k][j]))%m;
         }
         return tmp;
    }
    Matrix Pow(Matrix &b,Ull n)
    {
        Matrix tmp;
        tmp.num[0][0]=tmp.num[1][1]=1,tmp.num[0][1]=tmp.num[1][0]=0;
        while(n)
        {
            if(n&1) tmp=tmp*b;
            b=b*b;
            n=(n>>1ll);
        } 
        return tmp;
    }
};
int main()
{
    cin>>m>>a>>c>>x0>>n>>g;
    Matrix mat;
    mat.num[0][0]=a,mat.num[0][1]=0,mat.num[1][0]=c,mat.num[1][1]=1;
    mat=mat.Pow(mat,n);
    Matrix ans;
    ans.num[0][0]=x0,ans.num[0][1]=1,ans.num[1][0]=ans.num[1][1]=0;
    ans=ans*mat;
    cout<<(ans.num[0][0]%g);
    return 0;
}
