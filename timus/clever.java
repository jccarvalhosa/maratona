import java.math.BigInteger;
import java.util.Scanner;

public class clever {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n, m, k;
		n = scan.nextInt();
		m = scan.nextInt();
		k = scan.nextInt();
		BigInteger num = new BigInteger(m + ""), den = new BigInteger(1 + ""), gcd;
		for(int i=0;i<k;i++) {
			den = den.multiply(new BigInteger(n + ""));
			num = num.multiply(new BigInteger(n - 2 + ""));
			num = num.add(den);
		}
		gcd = den.gcd(num);
		System.out.println(num.divide(gcd) + "/" + den.divide(gcd));
	}
}
