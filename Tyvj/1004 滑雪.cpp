#include <stdio.h>
#include<stdlib.h>
int map[100][100];
int dis[100][100];
int n, m;
int check(int a, int b)
{
        if(a < 0 || a >= n || b < 0 || b >= m){
                return 0;
        }
        return 1;
}

int max(int a, int b)
{
        return a > b ? a : b;
}

#define deal(i, j) do{\
        if(check(i, j) && map[i][j] > map[a][b]){\
                t = max(srch(i, j), t);\
        }\
}while(0)

int srch(int a, int b)
{
        int t = 0;
        if(dis[a][b] = 0){
        deal(a + 1, b);
        deal(a - 1, b);
        deal(a, b + 1);
        deal(a, b - 1);
        dis[a][b] = t + 1;
        return dis[a][b];
      }
}

int main()
{
        int ans = 1;
        int i, j, t;
        scanf("%d%d", &n, &m);
        for(i = 0; i < n; i++){
                for(j = 0; j < m; j++)
                {
                        scanf("%d", &map[i][j]);
                }
        }
        for(i = 0; i < n; i++){
                for(j = 0; j < m; j++){
                        t = srch(i, j);
                        if(ans < t){
                                ans = t;
                        }
                }
        }
        printf("%d\n", ans);
        system("pause");
        return 0;
}
