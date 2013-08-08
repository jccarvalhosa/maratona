
import java.math.BigInteger;
import java.util.Scanner;
class A {

	public static BigInteger sqrt(BigInteger n) {
		BigInteger i=BigInteger.ZERO, m, f=n;
		while(true) {
			 m = i.add(f).shiftRight(1);
			 if(m.multiply(m).compareTo(n) <= 0) {
				 BigInteger next = m.add(BigInteger.ONE);
				 if(next.multiply(next).compareTo(n) > 0) return m;
				 i = next;
			 } else {
				 BigInteger next = m.subtract(BigInteger.ONE);
				 if(next.multiply(next).compareTo(n) <= 0) return next;
				 f = next;
			 }
		}
	}
	
	public static void main(String[] args) {
		Scanner input = new Scanner( System.in );
		while(input.hasNextBigInteger()) {
			BigInteger n = input.nextBigInteger();
			BigInteger k = input.nextBigInteger();
			BigInteger doisk = k.shiftLeft(1);
			BigInteger quatrok = k.shiftLeft(2);
			BigInteger v = n.multiply(quatrok);
			BigInteger delta = sqrt(v);
			for(int i=0;;i++) {
				BigInteger novodelta = delta.add(BigInteger.valueOf(i));
				BigInteger x2 = novodelta.multiply(novodelta).subtract(v);
				if(x2.signum() != -1) {
					BigInteger x = sqrt(x2);
					if(x.multiply(x).equals(x2)) {
						BigInteger p = novodelta.subtract(x).divide(doisk);
						if(p.compareTo(BigInteger.ONE) <= 0 || n.remainder(p).signum() != 0) p = novodelta.add(x).divide(doisk);
						if(p.compareTo(BigInteger.ONE) <= 0 || n.remainder(p).signum() != 0) continue;
						BigInteger q = n.divide(p);
						if(p.compareTo(q) >= 0) {
							BigInteger aux = p;
							p = q;
							q = aux;
						}
						System.out.println(p + " * " + q);
						break;
					}
				}
			}
		}
	}
}
