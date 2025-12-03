/*
 * 문제: 백준 9461번 - 파도반 수열 (https://www.acmicpc.net/problem/9461)
 * 문제 풀이
 *  Bottom-Up DP 활용.
 *  점화식: P(n) = P(n-2) + P(n-3)
 *  N=100일 때 int 범위를 초과하므로 long 사용.
 *
 * 시간 복잡도: O(t)
 */

package baekjoon.p09000.p09400;

import java.io.*;

public class BOJ_9461_파도반수열 {
    // public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int t = Integer.parseInt(br.readLine());
        long[] memo = new long[101];
        StringBuilder sb = new StringBuilder();

        memo[1] = memo[2] = memo[3] = 1;

        for (int i = 4; i < memo.length; i++) {
            memo[i] = memo[i - 2] + memo[i - 3];
        }

        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());

            sb.append(memo[n]).append("\n");
        }

        bw.write(sb.toString());
        br.close();
        bw.close();
    }
}
