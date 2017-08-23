#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXN=1000;
const int PER=200;
int general[MAXN+2], king[MAXN+2];
bool gused[MAXN+2], kused[MAXN+2];
int main()
{
    int n;
    int i,j;
    scanf("%d", &n);
    for (i=1; i<=n; ++i)
    {
        scanf("%d", &general[i]);
    }
    for (i=1; i<=n; ++i)
    {
        scanf("%d", &king[i]);
    }
    sort( &general[1], &general[n+1], less<int>() );
    sort (&king[1], &king[n+1], greater<int>() );
    int remain=n, win=0;
    for (i=1; i<=n; ++i)
    {
        for (j=1; j<=n; ++j)
        {
            if (kused[j])
                continue;
            if ( general[i] > king[j] )
            {
                gused[i]=true;
                kused[j]=true;
                --remain;
                ++win;
                break;
            }
        }
    }
    for (i=1; i<=n && remain>0 ; ++i)
    {
        if (gused[i]) 
            continue;
        for (j=1; j<=n; ++j)
        {
            if (kused[j])
                continue;
            if (general[i] > king[j])
                break;
            if (general[i]==king[j])
            {
                gused[i]=true;
                kused[j]=true;
                --remain;
                break;
            }
         }
    }
    win-=remain;
    printf("%d\n", win*PER);
    system("pause");
    return 0;
}
