/*
 * 문제: 프로그래머스 - 2018 KAKAO BLIND RECRUITMENT > [1차] 비밀지도  (https://school.programmers.co.kr/learn/courses/30/lessons/17681)
 * 문제 풀이
 *  비트 마스킹과 시프트 연산을 사용하여 각 자릿수의 비트 상태를 개별적으로 확인.
 *  두 지도 중 하나라도 벽이면 벽이 되는 OR 연산 논리를 적용.
 *  하위 비트부터 문자를 생성했으므로, 최종적으로 문자열을 뒤집어 원래 순서로 복원.
 *
 * 시간 복잡도: O(n²)
 */
package programmers.kakao.blind2018;

public class PROG_비밀지도 {
    // class Solution {
    public String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = new String[n];

        for (int i = 0; i < n; i++) {
            StringBuilder sb = new StringBuilder();

            for (int j = 0; j < n; j++) {
                int mask = 1 << j;

                sb.append(((arr1[i] & mask) | (arr2[i] & mask)) == 0 ? " " : "#");
            }

            answer[i] = sb.reverse().toString();
        }

        return answer;
    }
}
