/*
 * 문제: 프로그래머스 - 2018 KAKAO BLIND RECRUITMENT > [1차] 다트 게임 (https://school.programmers.co.kr/learn/courses/30/lessons/17682)
 *
 * 시간 복잡도: O(n)
 *  n: 문자열의 길이
 */
package programmers.kakao.blind2018;

public class PROG_다트게임 {
    // class Solution {
    public int solution(String dartResult) {
        int score = dartResult.charAt(0) - '0';
        int prev = 0;
        int answer = 0;

        for (int i = 1; i < dartResult.length(); i++) {
            switch (dartResult.charAt(i)) {
                case 'S':
                    break;
                case 'D':
                    score *= score;
                    break;
                case 'T':
                    score *= score * score;
                    break;
                case '*':
                    score *= 2;
                    prev *= 2;
                    break;
                case '#':
                    score = -score;
                    break;
                default:
                    if (dartResult.charAt(i - 1) == '1') {
                        score = 10;
                    } else {
                        answer += prev;
                        prev = score;
                        score = dartResult.charAt(i) - '0';
                    }
            }
        }

        answer += prev + score;

        return answer;
    }
}
