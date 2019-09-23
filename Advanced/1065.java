import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for(int i = 0; i < n; i++) {
            BigInteger x = new BigInteger(in.next());
            BigInteger y = new BigInteger(in.next());
            BigInteger z = new BigInteger(in.next());
            BigInteger sum  = x.add(y);
            if(sum.compareTo(z) > 0) {
                System.out.println("Case #"+(i+1)+": true");
            } else {
                System.out.println("Case #"+(i+1)+": false");
            }
        }
        in.close();
    }
}