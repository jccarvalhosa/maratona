import java.math.BigInteger;
import java.util.Scanner;

public class hankel {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n;
		n = scan.nextInt();
		BigInteger num = BigInteger.ONE;
		System.out.println(num);
		for(int i=1;i<2*n-1;i++) {
			num = num.multiply(new BigInteger(2*(2*i-1) + "")).divide(new BigInteger(i+1 + ""));
			System.out.println(num);
		}
	}
}
