/*
 * 문제: 백준 2565번 - 전깃줄 (https://www.acmicpc.net/problem/2565)
 * 문제 풀이
 *  전깃줄이 교차하지 않으려면 A 전봇대를 기준으로 정렬했을 때, 연결된 B 전봇대 위치가 증가 수열을 이뤄야 함.
 *  따라서 이분 탐색을 활용해 LIS의 길이를 구하면 설치 가능한 최대 개수가 되며,
 *  전체 개수에서 이를 빼면 제거해야 할 최소 개수를 구할 수 있음.
 *
 * 시간 복잡도: O(n log n)
 *  n: 전깃줄의 개수
 */

package baekjoon.p02000.p02500;

import java.io.*;
import java.util.*;

public class BOJ_2565_전깃줄 {
    // public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        int[] pole = new int[501];
        List<Integer> list = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            pole[a] = b;
        }

        for (int i = 1; i < pole.length; i++) {
            if (pole[i] == 0) {
                continue;
            }

            int pos = Collections.binarySearch(list, pole[i]);

            pos = pos < 0 ? -pos - 1 : pos;

            if (pos < list.size()) {
                list.set(pos, pole[i]);
            } else {
                list.add(pole[i]);
            }
        }

        bw.write(Integer.toString(n - list.size()));
        br.close();
        bw.close();
    }
}
