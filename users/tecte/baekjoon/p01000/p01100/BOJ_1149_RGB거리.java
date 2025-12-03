/*
 * 문제: 백준 1149번 - RGB거리 (https://www.acmicpc.net/problem/1149)
 * 문제 풀이
 *  Bottom-Up DP 활용.
 *  i번째 집을 특정 색으로 칠할 때의 최소 비용은
 *  i-1번째 집을 그 색이 아닌 다른 두 색 중 하나로 칠했을 때의 최소 비용 + 현재 색 비용.
 *
 * 시간 복잡도: O(n)
 */

package baekjoon.p01000.p01100;

import java.io.*;
import java.util.*;

public class BOJ_1149_RGB거리 {
    // public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        int[][] memo = new int[3][n + 1];

        for (int i = 1; i <= n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            memo[0][i] = Math.min(memo[1][i - 1], memo[2][i - 1]) + Integer.parseInt(st.nextToken());
            memo[1][i] = Math.min(memo[0][i - 1], memo[2][i - 1]) + Integer.parseInt(st.nextToken());
            memo[2][i] = Math.min(memo[0][i - 1], memo[1][i - 1]) + Integer.parseInt(st.nextToken());
        }

        bw.write(Integer.toString(Math.min(memo[0][n], Math.min(memo[1][n], memo[2][n]))));
        br.close();
        bw.close();
    }
}
