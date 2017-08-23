#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<time.h>
int f[7][7][7][7][7][7],total,p[2001][2001],n,a1,a2,a3,a4,a5,a6;
int main(){
	scanf("%d",&n);
	memset(f,0,sizeof(f)); total=0; memset(p,0,sizeof(p));
	for (int i=1; i<=n; i++){
		scanf("%d%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5,&a6);
		if (f[a1][a2][a3][a4][a5][a6]==0){
			total++;
			f[a1][a2][a3][a4][a5][a6]=total;
            f[a1][a2][a4][a5][a6][a3]=total;
            f[a1][a2][a5][a6][a3][a4]=total;
            f[a1][a2][a6][a3][a4][a5]=total;
            f[a2][a1][a3][a6][a5][a4]=total;
            f[a2][a1][a4][a3][a6][a5]=total;
            f[a2][a1][a5][a4][a3][a6]=total;
            f[a2][a1][a6][a5][a4][a3]=total;
            f[a3][a5][a2][a4][a1][a6]=total;
            f[a3][a5][a6][a2][a4][a1]=total;
            f[a3][a5][a1][a6][a2][a4]=total;
            f[a3][a5][a4][a1][a6][a2]=total;
            f[a5][a3][a1][a4][a2][a6]=total;
            f[a5][a3][a6][a1][a4][a2]=total;
            f[a5][a3][a2][a6][a1][a4]=total;
            f[a5][a3][a4][a2][a6][a1]=total;
            f[a4][a6][a3][a2][a5][a1]=total;
            f[a4][a6][a1][a3][a2][a5]=total;
            f[a4][a6][a5][a1][a3][a2]=total;
            f[a4][a6][a2][a5][a1][a3]=total;
            f[a6][a4][a5][a2][a3][a1]=total;
            f[a6][a4][a1][a5][a2][a3]=total;
            f[a6][a4][a3][a1][a5][a2]=total;
            f[a6][a4][a2][a3][a1][a5]=total;
            p[f[a1][a2][a3][a4][a5][a6]][0]++;
            p[f[a1][a2][a3][a4][a5][a6]][1]=i;
		}else{
			p[f[a1][a2][a3][a4][a5][a6]][0]++;
			p[f[a1][a2][a3][a4][a5][a6]][p[f[a1][a2][a3][a4][a5][a6]][0]]=i;
		}
	}
	printf("%d\n",total);
	for (int i=1; i<=total; i++){
		for (int j=1; j<p[i][0]; j++)
	        printf("%d ",p[i][j]);
        printf("%d\n",p[i][p[i][0]]);
	}
	return 0;
}
