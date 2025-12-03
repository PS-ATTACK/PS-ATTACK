/*
 * 문제: 백준 1912번 - 연속합 (https://www.acmicpc.net/problem/1912)
 * 문제 풀이
 *  DP의 일종인 카데인 알고리즘(Kadane's Algorithm)을 사용.
 *  이전까지의 연속합이 양수면 가져가고, 음수면 버림.
 *  한 번의 순회로 각 위치에서의 최대 연속합을 구하고, 그 중 전체 최댓값 구함.
 *
 * 시간 복잡도: O(n)
 */

package baekjoon.p01000.p01900;

import java.io.*;
import java.util.*;

public class BOJ_1912_연속합 {
    // public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int[] memo = new int[n];
        int max = memo[0] = arr[0];

        for (int i = 1; i < n; i++) {
            memo[i] = Math.max(memo[i - 1], 0) + arr[i];
            max = Math.max(max, memo[i]);
        }

        bw.write(Integer.toString(max));
        br.close();
        bw.close();
    }
}
