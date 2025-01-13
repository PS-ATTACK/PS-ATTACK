import java.io.*;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N,M;
    static int[] dp = new int[5001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());

        Arrays.fill(dp, 999999);
        dp[3] = 1;
        dp[5] = 1;
        for(int i = 6; i < N +1 ; i++){
            dp[i] = Math.min(dp[i - 3], dp[i - 5]) +1;
        }
        System.out.println(dp[N] >= 999999 ? -1 : dp[N]);


    }
}