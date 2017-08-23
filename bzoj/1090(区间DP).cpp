#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=105;
int f[N][N];
char s[N]; 
inline int calc(int x)
{
    int tmp=0;
    while(x)
    {
        tmp++;
        x/=10;
    }
    return tmp;
}
int main()
{
    int i,j,k,l,m;
    gets(s);
    int len=strlen(s);
    for(l=1;l<=len;++l)
     for(i=0;i+l<=len;++i)
     {
        j=i+l-1;
        f[i][j]=l;
        for(k=i;k<j;++k)    f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
        for(k=1;k<l;++k)
        {
            if(l%k==0)
            {
                bool flag=true;
                for(m=i+k;flag && m+k-1<=j;m+=k)
                if(strncmp(&s[i],&s[m],k))    flag=false;
                if(flag)    f[i][j]=min(f[i][j],f[i][i+k-1]+calc(l/k)+2);
            } 
        } 
     }
    printf("%d\n",f[0][len-1]);
    return 0;
} 
