import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Main {
    private static int n;
    private static int m;
    private static BigInteger dp[];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());

            System.out.println(palin(n, m));
        }
        br.close();
    }

    private static BigInteger palin (int n, int k) {
        dp = new BigInteger[Math.max(n, k) + 1];
        Arrays.fill(dp, BigInteger.valueOf(-1));
        if (k > n) {
            int tmp;
            tmp = n;
            n = k;
            k = tmp;
        }

        return factorial(n).divide(factorial(k).multiply(factorial(n - k)));
    }

    private static BigInteger factorial(int n) {
        if (n == 1 || n == 0) return BigInteger.ONE;
        if (!dp[n].equals(BigInteger.valueOf(-1))) return dp[n];
        return dp[n] = factorial(n - 1).multiply(BigInteger.valueOf(n));
    }

}
