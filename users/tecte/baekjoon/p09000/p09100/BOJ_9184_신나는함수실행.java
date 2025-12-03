/*
 * 문제: 백준 9184번 - 신나는 함수 실행 (https://www.acmicpc.net/problem/9184)
 * 문제 풀이
 *  Top-Down 방식의 동적 계획법 활용.
 *  중복 부분 문제를 해결하기 위해 메모이제이션 적용.
 *
 * 시간 복잡도: O(1) - 상태 공간이 20³으로 고정되어 있어 상수 시간에 해결 가능
 */

package baekjoon.p09000.p09100;

import java.io.*;
import java.util.*;

public class BOJ_9184_신나는함수실행 {
    // public class Main {
    private static final int[][][] memo = new int[21][21][21];

    private static int w(int a, int b, int c) {
        if (a <= 0 || b <= 0 || c <= 0) {
            return 1;
        } else if (a > 20 || b > 20 || c > 20) {
            return w(20, 20, 20);
        } else if (memo[a][b][c] != 0) {
            return memo[a][b][c];
        }

        return memo[a][b][c] = (a < b && b < c) ?
                w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c) :
                w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            if (a == -1 && b == -1 && c == -1) {
                break;
            }

            sb.append("w(").append(a).append(", ").append(b).append(", ").append(c).append(") = ").append(w(a, b, c)).append("\n");
        }

        bw.write(sb.toString());
        br.close();
        bw.close();
    }
}
