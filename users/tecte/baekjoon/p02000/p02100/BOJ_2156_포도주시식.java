/*
 * 문제: 백준 2156번 - 포도주 시식 (https://www.acmicpc.net/problem/2156)
 * 문제 풀이
 *  현재 연속 몇 번째 잔인지를 상태로 두는 DP 사용.
 *  1. 이번 잔을 안 마심: 이전 단계의 최댓값을 그대로 가져옴.
 *  2. 이번이 연속 1잔째: 직전에 안 마신 상태에서 현재 포도주를 마신 값과 이전의 1잔째 값 중 더 큰 값을 선택.
 *  3. 이번이 연속 2잔째: 직전에 1잔째였던 상태에서 현재 포도주를 마신 값과 이전의 2잔째 값 중 더 큰 값을 선택.
 *  최종적으로 n번째 단계의 세 가지 상태 중 최댓값을 구함.
 *
 * 시간 복잡도: O(n)
 */

package baekjoon.p02000.p02100;

import java.io.*;

public class BOJ_2156_포도주시식 {
    // public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        int[][] memo = new int[n + 1][3];

        for (int i = 1; i <= n; i++) {
            int wine = Integer.parseInt(br.readLine());

            memo[i][0] = Math.max(memo[i - 1][0], Math.max(memo[i - 1][1], memo[i - 1][2]));
            memo[i][1] = Math.max(memo[i - 1][0] + wine, memo[i - 1][1]);
            memo[i][2] = Math.max(memo[i - 1][1] + wine, memo[i - 1][2]);
        }

        bw.write(Integer.toString(Math.max(memo[n][0], Math.max(memo[n][1], memo[n][2]))));
        br.close();
        bw.close();
    }
}
