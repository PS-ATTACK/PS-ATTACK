/*
 * 문제: 프로그래머스 - 2018 KAKAO BLIND RECRUITMENT > [1차] 추석 트래픽 (https://school.programmers.co.kr/learn/courses/30/lessons/17676)
 * 문제 풀이
 *  이분 탐색과 누적 합의 원리를 활용하여 구간 내 요청 개수를 계산.
 *  각 로그의 종료 시점을 1초 윈도우의 시작점으로 잡고, 윈도우의 끝점(시작점 + 999ms)을 설정.
 *  윈도우에 포함된 트래픽의 개수를 구하는 공식: 윈도우 끝보다 이전에 시작된 전체 요청 수 - 윈도우 시작보다 이전에 종료된 전체 요청 수
 *  시작 시간 배열은 별도로 오름차순 정렬하여 upperBound로 탐색.
 *  종료 시간 배열은 이미 정렬되어 있으므로 lowerBound로 탐색.
 *
 * 시간 복잡도: O(n log n)
 *  n: lines 배열의 길이
 */

package programmers.kakao.blind2018;

import java.util.*;

public class PROG_추석트래픽_2 {
    // class Solution {
    public int solution(String[] lines) {
        int[] start = new int[lines.length];
        int[] end = new int[lines.length];
        int answer = 0;

        for (int i = 0; i < lines.length; i++) {
            String[] parts = lines[i].split(" ");
            StringTokenizer st = new StringTokenizer(parts[1], ":");
            int h = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int s = (int) (Double.parseDouble(st.nextToken()) * 1000);
            int t = (int) (Double.parseDouble(parts[2].substring(0, parts[2].length() - 1)) * 1000);
            int endTime = (h * 3600 + m * 60) * 1000 + s;

            start[i] = endTime - t + 1;
            end[i] = endTime;
        }

        Arrays.sort(start);

        for (int i = 0; i < end.length; i++) {
            int cnt = upperBound(start, end[i] + 999) - lowerBound(end, end[i]);

            answer = Math.max(answer, cnt);
        }

        return answer;
    }

    private int upperBound(int[] arr, int target) {
        int l = 0;
        int r = arr.length;

        while (l < r) {
            int m = (l + r) / 2;

            if (arr[m] <= target) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        return l;
    }

    private int lowerBound(int[] arr, int target) {
        int l = 0;
        int r = arr.length;

        while (l < r) {
            int m = (l + r) / 2;

            if (arr[m] < target) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        return l;
    }
}
