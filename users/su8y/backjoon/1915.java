import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static int N,M;
    static int[][] arr = new int[1001][1001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        int dp[][] = new int[1001][1001];
        int max = 0;

        for (int i = 0; i < N; i++) {
            char[] chars = br.readLine().toCharArray();
            for (int j = 0; j < M; j++) {
                arr[i][j] = Character.getNumericValue(chars[j]);
                dp[i][j] = arr[i][j];
                if( i >= 1 && j >= 1){
                    if(dp[i-1][j] >0 && dp[i][j-1] >0 && dp[i-1][j-1] >0&&dp[i][j] !=0){
                        int min = Math.min(dp[i-1][j],Math.min(dp[i][j-1],dp[i-1][j-1]));
                        dp[i][j] = min +1;
                    }
                }
                max = Math.max(max,dp[i][j]);
            }
        }
        System.out.println(max*max);



    }
}