/*
 * 문제: 백준 24416번 - 알고리즘 수업 - 피보나치 수 1 (https://www.acmicpc.net/problem/24416)
 * 문제 풀이
 *  재귀 함수의 호출 횟수는 수학적으로 n번째 피보나치 수의 값과 동일.
 *  DP의 연산 횟수는 반복문의 실행 횟수인 (n - 2)와 동일.
 *
 * 시간 복잡도: O(n)
 */

package baekjoon.p24000.p24400;

import java.io.*;

public class BOJ_24416_알고리즘수업피보나치수1 {
    // public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        int[] memo = new int[n + 1];

        memo[1] = memo[2] = 1;

        for (int i = 3; i <= n; i++) {
            memo[i] = memo[i - 1] + memo[i - 2];
        }

        bw.write(memo[n] + " " + (n - 2));
        br.close();
        bw.close();
    }
}
