/*
 * 문제: 백준 10844번 - 쉬운 계단 수 (https://www.acmicpc.net/problem/10844)
 * 문제 풀이
 *  n번째 자리에 올 수 있는 숫자는 n-1번째 숫자에 의해 결정되므로,
 *  길이(i)와 마지막 자릿수(j)를 상태로 갖는 2차원 배열을 사용.
 *  점화식: 현재 숫자가 j라면, 이전 숫자는 j-1 또는 j+1이어야 함.
 *  단, 0은 1에서만, 9는 8에서만 파생되는 예외 조건 처리.
 *
 * 시간 복잡도: O(n)
 */

package baekjoon.p10000.p10800;

import java.io.*;

public class BOJ_10844_쉬운계단수 {
    // public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        int[][] memo = new int[n + 1][10];
        final int MOD = 1_000_000_000;
        int cnt = 0;

        for (int i = 1; i < 10; i++) {
            memo[1][i] = 1;
        }

        for (int i = 2; i <= n; i++) {
            memo[i][0] = memo[i - 1][1];
            memo[i][9] = memo[i - 1][8];

            for (int j = 1; j < 9; j++) {
                memo[i][j] = (memo[i - 1][j - 1] + memo[i - 1][j + 1]) % MOD;
            }
        }

        for (int i = 0; i < 10; i++) {
            cnt = (cnt + memo[n][i]) % MOD;
        }

        bw.write(Integer.toString(cnt));
        br.close();
        bw.close();
    }
}
