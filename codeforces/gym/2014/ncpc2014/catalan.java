import java.util.Scanner;
import java.math.BigInteger;
public class Main {
	public static void main(String[] args) {
		Scanner input = new Scanner( System.in );
		BigInteger[] f = new BigInteger[11111];
		f[0]=BigInteger.valueOf(1);
		f[1]=BigInteger.valueOf(1);
		int n;
		n=input.nextInt();
		for(int i=2; i<=2*n+2; i++) f[i]=f[i-1].multiply(BigInteger.valueOf(i));
		BigInteger c=((f[2*n+2].divide(f[n+1])).divide(f[n+1])).divide(BigInteger.valueOf(n+2));
		System.out.print(c + "\n");
	}
}
