import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.OptionalInt;
import java.util.StringTokenizer;

/*
 */
public class Main {
    private static StringTokenizer st;
    private static int lastIndex;
    private static final int INT_MAX = 987654321;
    private static int n;
    private static int[][] map, dp;


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        map = new int[n + 1][3];
        dp = new int[n + 1][3];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int j = 0;
            while (st.hasMoreTokens()) {
                map[i][j++] = Integer.parseInt(st.nextToken());
            }
        }
        int min = INT_MAX;

        for (int i = 0; i < 3; i++) {
            for (int[] ints : dp) {
                Arrays.fill(ints, INT_MAX);
            }
            lastIndex = i;
            dp[n - 1][i] = solve(n - 1, i);
            min = Math.min(min, dp[n - 1][i]);
        }
        System.out.println(min);

        br.close();
    }

    private static int solve(int n, int rgb) {

        if (n == 0) return map[n][rgb];
        if(dp[n][rgb] != INT_MAX) return dp[n][rgb];

        for (int i = 0; i < 3; i++) {
            if (i == rgb) continue; // n번과 n-1의 색깔이 같은 경우
            if (n - 1 == 0 && i == lastIndex) continue; // 0 == n 인 경우
            dp[n][rgb] = Math.min(solve(n - 1, i), dp[n][rgb]);
        }
        dp[n][rgb] += map[n][rgb];

        return dp[n][rgb];
    }

}
