import java.util.*;
import java.math.*;
public class Main {
	final static int N = 1005;
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		BigInteger fib[] = new BigInteger[N];
		fib[0] = BigInteger.ZERO;
		fib[1] = BigInteger.ONE;
		for (int i = 2; i < N; i++)
			fib[i] = fib[i-1].add(fib[i-2]);
		for (int C = 0; C < T; C++) {
			int n = in.nextInt();
			BigInteger m = in.nextBigInteger();
			int i = 0;
			BigInteger x = BigInteger.ZERO;
			while (m.compareTo(fib[i+2]) > 0) {
				m = m.subtract(fib[i+2]);
				x = x.add(fib[i]);
				i++;
			}
			System.out.println(x.add(m).subtract(BigInteger.ONE).mod(BigInteger.valueOf(258280327)));
		}
	}
}
