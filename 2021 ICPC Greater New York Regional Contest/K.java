import java.math.BigDecimal;
import java.math.*;
import java.util.*;
class Main {
	public static void main(String[] args) {
		Scanner cin=new Scanner(System.in);
		BigDecimal one = new BigDecimal(1.0);
		BigDecimal zero = new BigDecimal(0.0);
		BigDecimal p = cin.nextBigDecimal();
		p = one.subtract(p);
		BigDecimal p1 = p;
		BigDecimal s = new BigDecimal(1000000.0);
		int tt = 0;
		for(int n=2;n<=16;n++){
			p1 = p1.multiply(p);
			//System.out.println(p1);
			BigDecimal nn =  new BigDecimal(n);
			
			BigDecimal ans = (p1.divide(nn, 100, BigDecimal.ROUND_HALF_UP)).add(one).subtract(p1);
			if (tt==0||s.compareTo(ans)==1) {
				s = ans;
				tt=n;
			}
		}
		System.out.println(tt);
		
		
	}
}