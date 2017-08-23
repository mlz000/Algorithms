#include<stdio.h>
int main()
{
    int n,m,i,j,a,b,c,max;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
                    scanf("%d",&m);
                    max=0;
                    for(j=0;j<m;j++)
                    {
                                    scanf("%d%d%d",&a,&b,&c);
                                    int d;
                                    d=a*c;
                                    max+=d;
                    }
                    printf("%d\n",max);
    }
    return 0;
}
