/* Calculate and print the factorial of a given integer. 
For example, if n = 30, we calculate 30 x 29 x ... x 2 x 1 and get 265252859812191058636308480000000. */

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the extraLongFactorials function below.
    static void extraLongFactorials(int n) {
        BigInteger result = BigInteger.valueOf(n);
        if (n == 0) {
            System.out.println(1);
        }
        for (int i = n-1; i > 0; --i) {
            result = result.multiply(BigInteger.valueOf(i));
        }
        System.out.println(result);
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        extraLongFactorials(n);

        scanner.close();
    }
}
