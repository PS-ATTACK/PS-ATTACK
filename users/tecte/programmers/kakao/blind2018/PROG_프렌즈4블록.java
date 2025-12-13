/*
 * 문제: 프로그래머스 - 2018 KAKAO BLIND RECRUITMENT > [1차] 프렌즈4블록 (https://school.programmers.co.kr/learn/courses/30/lessons/17679)
 * 문제 풀이
 *  2차원 배열을 이용한 시뮬레이션 문제로, 더 이상 지워질 블록이 없을 때까지 다음 3단계를 반복.
 *  1. 탐색: (1, 1)부터 전체를 순회하며 2x2 영역이 같은 블록인지 검사. 겹치는 블록도 함께 지워져야 하므로 바로 삭제하지 않고 boolean 배열에 삭제 대상을 마킹.
 *  2. 제거: 마킹된 좌표를 순회하며 지워진 블록의 개수를 증가시키고, 블록을 지움.
 *  3. 이동: 투 포인터를 사용해서 각 열마다 아래에서부터 위로 탐색하며, 빈 공간이 있을 경우 가장 가까운 위쪽 블록을 찾아 아래로 내림.
 *
 * 시간 복잡도: O(t * n * m)
 *  t: 라운드 횟수
 *  n: 폭
 *  m: 높이
 */
package programmers.kakao.blind2018;

public class PROG_프렌즈4블록 {
    // class Solution {
    public int solution(int m, int n, String[] board) {
        char[][] arr = new char[m][n];
        int answer = 0;

        for (int i = 0; i < m; i++) {
            arr[i] = board[i].toCharArray();
        }

        while (true) {
            boolean[][] checked = new boolean[m][n];
            boolean flag = true;

            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    if (arr[i][j] != 0 && arr[i][j] == arr[i - 1][j] && arr[i][j] == arr[i][j - 1] && arr[i][j] == arr[i - 1][j - 1]) {
                        checked[i][j] = checked[i - 1][j] = checked[i][j - 1] = checked[i - 1][j - 1] = true;
                        flag = false;
                    }
                }
            }

            if (flag) {
                break;
            }

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (checked[i][j]) {
                        arr[i][j] = 0;
                        answer++;
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                int h = m;

                while (--h >= 0) {
                    if (arr[h][i] == 0) {
                        break;
                    }
                }

                for (int j = h - 1; j >= 0; j--) {
                    if (arr[j][i] == 0) {
                        continue;
                    }

                    arr[h--][i] = arr[j][i];
                    arr[j][i] = 0;
                }
            }
        }

        return answer;
    }
}
