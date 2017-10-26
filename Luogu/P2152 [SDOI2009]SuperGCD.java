import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        BigInteger a, b;
        a = cin.nextBigInteger();
        b = cin.nextBigInteger();
        System.out.println(a.gcd(b));
    }
}