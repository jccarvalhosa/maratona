import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	static BigInteger x, y;
	final static BigInteger ZERO = BigInteger.ZERO;
	final static BigInteger ONE = BigInteger.ONE;

	static BigInteger exgcd(BigInteger a, BigInteger b) {
		if (b.equals(ZERO)) {
			x = ONE;
			y = ZERO;
			return a;
		}
		BigInteger g = exgcd(b, a.mod(b)), t = x;
		x = y;
		y = t.subtract(a.divide(b).multiply(y));
		return g;
	}

	static BigInteger gcd(BigInteger a, BigInteger b) {
		if (b.equals(ZERO)) return a;
		else return gcd(b, a.mod(b));
	}

	public static void main(String[] args) throws IOException{
		Scanner cin = new Scanner(System.in);
		while(cin.hasNextBigInteger()) {
			BigInteger a = cin.nextBigInteger();
			BigInteger b = cin.nextBigInteger();
			BigInteger s = cin.nextBigInteger();        
			if (s.equals(a) || s.equals(b)) {
				System.out.println("YES");
				continue;
			}
			if(a.equals(ZERO) && b.equals(ZERO)) {
				System.out.println("NO");
				continue;
			}
			if (a.equals(ZERO) && s.mod(b).equals(ZERO)) {
				System.out.println("YES");
				continue;
			}
			if (b.equals(ZERO) && s.mod(a).equals(ZERO)) {
				System.out.println("YES");
				continue;
			}
			if (a.equals(ZERO) || b.equals(ZERO) || s.equals(ZERO)) {
				System.out.println("NO");
				continue;
			}
			BigInteger g = exgcd(a, b);
			if (!s.mod(g).equals(ZERO)) {
				System.out.println("NO");
				continue;
			}

			b = b.divide(g); a = a.divide(g); s = s.divide(g);                
			x = x.mod(b).multiply(s.mod(b)).mod(b);
			x = x.add(b).mod(b);
			y = s.subtract(a.multiply(x)).divide(b);
			boolean ok = false;
			while (y.compareTo(ONE) >= 0) {
				if (!x.equals(ZERO) && gcd(x, y).equals(ONE)) {
					ok = true;
					break;
				}
				x = x.add(b);
				y = y.subtract(a);
			}
			System.out.println(ok ? "YES" : "NO");
		}
	}
}
