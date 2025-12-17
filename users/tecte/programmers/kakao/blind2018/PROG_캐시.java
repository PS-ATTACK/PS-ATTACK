/*
 * 문제: 프로그래머스 - 2018 KAKAO BLIND RECRUITMENT > [1차] 캐시  (https://school.programmers.co.kr/learn/courses/30/lessons/17680)
 * 문제 풀이
 *  LRU 알고리즘을 LinkedHashMap 기능을 활용하여 구현.
 *  LinkedHashMap 생성자의 3번째 인자를 true로 설정하여, 단순 삽입 순서가 아닌 접근 순서로 정렬되도록 함.
 *  removeEldestEntry 메서드를 오버라이딩하여 맵의 크기가 cacheSize를 초과할 경우 가장 오래된(가장 앞쪽) 요소를 자동으로 삭제하도록 설정.
 *  Collections.newSetFromMap으로 Map을 Set처럼 래핑하여 사용.
 *  각 도시마다 캐시에 존재하는지 확인하여 실행 시간을 더하고, 해당 도시를 캐시의 가장 최신 위치(뒤쪽)로 갱신하거나 새로 추가함.
 *
 * 시간 복잡도: O(n)
 *  n: 도시 이름 배열의 길이
 */
package programmers.kakao.blind2018;

import java.util.*;

public class PROG_캐시 {
    // class Solution {
    public int solution(int cacheSize, String[] cities) {
        Map<String, Boolean> map = new LinkedHashMap<String, Boolean>(cacheSize + 1, 1f, true) {
            @Override
            protected boolean removeEldestEntry(Map.Entry eldest) {
                return size() > cacheSize;
            }
        };
        Set<String> set = Collections.newSetFromMap(map);
        int answer = 0;

        for (String city : cities) {
            city = city.toLowerCase();
            answer += set.contains(city) ? 1 : 5;
            set.add(city);
        }

        return answer;
    }
}
