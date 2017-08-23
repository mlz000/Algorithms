import java.io.*;
import java.math.*;
import java.util.*;
public class Main{
		static int N = 705;
		static int sum[] = new int[N];
		static int sz[][] = new int[N][N];
		static BigInteger dp[][] = new BigInteger[N][N];
		static int n;
		static void dfs(int u, int fa) {
			sum[u] = 1;
			for (int i = 1; i <= n; ++i)	dp[u][i] = BigInteger.valueOf(1); 
			for (int i = 1, v; i <= sz[u][0]; ++i){
				v = sz[u][i];
				if (v == fa)	continue;
				dfs(v, u);
				sum[u] += sum[v];
				for (int j = sum[u] - sum[v]; j >= 0; --j)
					for (int k = sum[v]; k >= 0; --k)
						dp[u][j + k] = dp[u][j + k].max(dp[u][j].multiply(dp[v][k]));
			}
			for (int i = 1; i <= sum[u]; ++i)	dp[u][0] = dp[u][0].max(dp[u][i].multiply(BigInteger.valueOf(i)));
		}
		public static void main(String[] args){
			Scanner cin = new Scanner(System.in);
			n = cin.nextInt();
			for (int i = 0; i <= n; ++i) {
				sz[i][0] = 0;
				for (int j = 0; j <= n; ++j)	dp[i][j] = BigInteger.ZERO;
			}
			for (int i = 1, a, b; i < n; ++i){
				a = cin.nextInt();b = cin.nextInt();
				sz[a][++sz[a][0]] = b;
				sz[b][++sz[b][0]] = a;
			}
			dfs(1, -1);
			System.out.print(dp[1][0]);
		}
}

