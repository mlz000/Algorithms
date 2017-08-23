import java.io.*;
import java.util.*;
import java.math.BigInteger;
public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n;
		BigInteger mod = BigInteger.TEN.pow(100);
		BigInteger ans = BigInteger.ZERO, t;
		while(in.hasNext()) {
			n = in.nextInt();
			ans = BigInteger.ONE;
			t = BigInteger.ONE;
			for (int i = 1; i + i <= n; ++i) {
				t = t.multiply(BigInteger.valueOf(n - 2 * i + 2));
				t = t.multiply(BigInteger.valueOf(n - 2 * i + 1));
				t = t.divide(BigInteger.valueOf(i));
				t = t.divide(BigInteger.valueOf(i + 1));
				ans = ans.add(t);
			}
			System.out.println(ans.remainder(mod));
		}
	}
}
