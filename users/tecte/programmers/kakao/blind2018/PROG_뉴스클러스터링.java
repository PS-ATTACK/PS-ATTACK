/*
 * 문제: 프로그래머스 - 2018 KAKAO BLIND RECRUITMENT > [1차] 뉴스 클러스터링 (https://school.programmers.co.kr/learn/courses/30/lessons/17677)
 * 문제 풀이
 *  자카드 유사도를 구하기 위해 문자열을 2글자씩 끊어 다중 집합으로 변환.
 *  대소문자 구분을 무시하기 위해 소문자로 통일하고, 영문자 쌍인 경우에만 유효한 토큰으로 인정하여 추출.
 *  중복 원소를 허용해야 하므로 Map을 사용하여 <토큰, 등장 횟수> 형태로 저장.
 *  교집합의 크기는 두 집합에서 공통된 토큰의 등장 횟수 중 최솟값들의 합으로 계산.
 *  합집합의 크기는 포함-배제의 원리를 적용하여, 두 집합의 전체 원소 개수의 합에서 미리 구한 교집합 크기를 빼서 계산.
 *
 * 시간 복잡도: O(n + m)
 *  n: 입력 문자열 str1의 길이
 *  m: 입력 문자열 str2의 길이
 */

package programmers.kakao.blind2018;

import java.util.*;

public class PROG_뉴스클러스터링 {
    // class Solution {
    private static final int CONST = 65536;

    public int solution(String str1, String str2) {
        Map<String, Integer> map1 = new HashMap<>();
        Map<String, Integer> map2 = new HashMap<>();
        int union = tokenize(str1.toLowerCase(), map1) + tokenize(str2.toLowerCase(), map2);
        int intersection = 0;

        for (String k : map1.keySet()) {
            int i = Math.min(map1.get(k), map2.getOrDefault(k, 0));

            union -= i;
            intersection += i;
        }

        if (map1.size() + map2.size() == 0) {
            return CONST;
        }

        return CONST * intersection / union;
    }

    private static int tokenize(String str, Map<String, Integer> map) {
        int cnt = 0;
        char prev = 0;

        for (char c : str.toCharArray()) {
            if (Character.isLetter(prev) && Character.isLetter(c)) {
                String k = new String(new char[]{prev, c});

                cnt++;
                map.put(k, map.getOrDefault(k, 0) + 1);
            }

            prev = c;
        }

        return cnt;
    }
}
