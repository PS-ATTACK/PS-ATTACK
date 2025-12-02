import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/*
복잡하게 생각하지 말고 완전 탐색을 생각 해보자
3개의 원소가 있는 배열에서 생각을 해보면 각 나눌수 있는 방법은 1 2, 2 1 이런식으로 여러개다.

분할한 문제된 문제인 부분 문제가 가장 작은 값을 가진 문제이면 되는 것이다.
mid => start ... end 이고
dp[start][end] = min(dp[start][end],dp[start][mid]+dp[mid+1][end]) + sum[end] - sum[start-1]이다.
마지막 sum은 부분합을 말하는데 min안에서 구한것은 부분문제들끼리의 합이고 지금 sum은 2가지로 분류된 부분문제를 합쳤을때 부분합과 동일하기 때문에 부분합을 더해준다.
*/
public class Main {
    private static int[] cost;
    private static int[][] dp;
    private static int[] sum;

    public static void main(String[] args) throws IOException {
        StringTokenizer st;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t, k;
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            k = Integer.parseInt(br.readLine());
            cost = new int[k+1];
            sum = new int[k+1];
            dp = new int[k+1][k+1];
            for (int[] d : dp) {
                Arrays.fill(d, Integer.MAX_VALUE);
            }
            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= k; i++) {
                cost[i] = Integer.parseInt(st.nextToken());
                sum[i] = sum[i - 1] + cost[i];
            }
            System.out.println(divide_solve(1, k));

        }


        br.close();
    }

    private static int divide_solve(int tx, int ty) {
        int ret = dp[tx][ty];
        if (ret != Integer.MAX_VALUE) return ret;
        if (tx == ty) return 0;
        if (tx + 1 == ty) return dp[tx][ty] = cost[tx] + cost[ty];


        for (int mid = tx; mid < ty; mid++) {
            int l = divide_solve(tx, mid);
            int r = divide_solve(mid + 1, ty);
            ret = Math.min(l + r, ret);
        }

        ret += sum[ty] - sum[tx - 1];
        return dp[tx][ty] = ret;

    }

}
