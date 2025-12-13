/*
 * 문제: 프로그래머스 - 2018 KAKAO BLIND RECRUITMENT > [1차] 셔틀버스 (https://school.programmers.co.kr/learn/courses/30/lessons/17678)
 * 문제 풀이
 *  우선순위 큐를 활용하여 셔틀버스 탑승 과정을 구현.
 *  모든 시간을 분 단위로 변환.
 *  크루들의 도착 시간을 오름차순으로 정렬하되, 마지막 셔틀버스의 출발 시간보다 늦게 도착하는 크루는 큐에 넣지 않음.
 *  첫 차부터 막차까지 순회하며, 각 버스 도착 시점에 대기 중인 크루를 정원만큼 태워 보냄.
 *  마지막 셔틀버스가 만석인 경우: 가장 마지막 도착한 크루보다 1분 먼저 도착해야 탑승 가능.
 *  마지막 셔틀버스에 빈자리가 있는 경우: 버스의 출발 시간에 딱 맞춰 도착하면 탑승 가능.
 *
 * 시간 복잡도: O(k log k)
 *  k: timetable의 길이
 */
package programmers.kakao.blind2018;

import java.util.*;

public class PROG_셔틀버스 {
    // class Solution {
    public String solution(int n, int t, int m, String[] timetable) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int last = 540 + (n - 1) * t;

        for (String time : timetable) {
            StringTokenizer st = new StringTokenizer(time, ":");
            int hh = Integer.parseInt(st.nextToken());
            int mm = Integer.parseInt(st.nextToken());
            int crew = hh * 60 + mm;

            if (crew <= last) {
                pq.offer(crew);
            }
        }

        int time = 540;
        int b = 0;
        int c = 0;
        int arrival = 0;

        while (!pq.isEmpty()) {
            if (pq.peek() <= time) {
                arrival = pq.poll();

                if (++c < m) {
                    continue;
                }
            }

            if (++b == n) {
                break;
            }

            time += t;
            c = 0;
        }

        arrival = c == m ? arrival - 1 : last;

        return String.format("%02d:%02d", arrival / 60, arrival % 60);
    }
}
