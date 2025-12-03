/*
 * 문제: 백준 1904번 - 01타일 (https://www.acmicpc.net/problem/1904)
 * 문제 풀이
 *  Bottom-Up DP 방식의 DP 활용.
 *  타일을 붙이는 방법은 1을 하나 붙이거나(n-1에서 파생), 00을 하나 붙이는(n-2에서 파생) 두 가지 경우.
 *
 * 시간 복잡도: O(n)
 */

package baekjoon.p01000.p01900;

import java.io.*;

public class BOJ_1904_01타일 {
    // public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        int[] memo = new int[n + 1];
        final int MOD = 15746;

        memo[0] = memo[1] = 1;

        for (int i = 2; i <= n; i++) {
            memo[i] = (memo[i - 1] + memo[i - 2]) % MOD;
        }

        bw.write(Integer.toString(memo[n]));
        br.close();
        bw.close();
    }
}
