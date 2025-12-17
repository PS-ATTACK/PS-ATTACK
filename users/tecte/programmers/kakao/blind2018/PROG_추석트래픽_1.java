/*
 * 문제: 프로그래머스 - 2018 KAKAO BLIND RECRUITMENT > [1차] 추석 트래픽 (https://school.programmers.co.kr/learn/courses/30/lessons/17676)
 * 문제 풀이
 *  스위핑 알고리즘을 사용하여 특정 구간 내의 최대 요청 개수를 구함.
 *  문자열로 주어진 시간 정보를 계산하기 쉽도록 밀리초(ms) 단위의 정수로 변환.
 *  각 로그에 대해 요청의 시작 시간과 (종료 시간 + 1초)를 경계값으로 설정.
 *  시작 시간: 처리량이 증가하는 시점이므로 카운트 +1
 *  종료 시간 + 1초: 해당 요청이 1초 윈도우 범위에서 완전히 벗어나는 시점이므로 카운트 -1
 *  생성된 모든 시작/종료 이벤트를 시간 순으로 오름차순 정렬.
 *  정렬된 이벤트를 순회하며 개수를 누적하고, 최댓값을 갱신.
 *
 * 시간 복잡도: O(n log n)
 *  n: lines 배열의 길이
 */

package programmers.kakao.blind2018;

import java.util.*;

public class PROG_추석트래픽_1 {
    // class Solution {
    public int solution(String[] lines) {
        List<Event> events = new ArrayList<>();

        for (String line : lines) {
            String[] parts = line.split(" ");
            StringTokenizer st = new StringTokenizer(parts[1], ":");
            int h = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int s = (int) (Double.parseDouble(st.nextToken()) * 1000);
            int t = (int) (Double.parseDouble(parts[2].substring(0, parts[2].length() - 1)) * 1000);
            int endTime = (h * 3600 + m * 60) * 1000 + s;

            events.add(new Event(endTime - t + 1, 1));
            events.add(new Event(endTime + 1000, -1));
        }

        events.sort(Comparator.comparingInt(a -> a.time));

        int cnt = 0;
        int answer = 0;

        for (Event e : events) {
            cnt += e.type;
            answer = Math.max(answer, cnt);
        }

        return answer;
    }

    private static class Event {
        int time;
        int type;

        public Event(int time, int type) {
            this.time = time;
            this.type = type;
        }
    }
}
