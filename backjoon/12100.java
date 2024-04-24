import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;
import java.util.stream.Stream;

public class Main {
    private static StringTokenizer st;
    private static int n, arr[][];
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    /**
     * < 왼쪽으로 합쳐진다면
     * i번째와 i+1번째를 본다.
     * if : 합칠수 있다면
     * 합친다
     * i += 2
     * else
     * 못합친다.
     * i++
     * 이것을 n 번 반복한다.
     * <p>
     * 모든 경우의 수를 확인해야 한다. 5번을 움직였을때 회전을 구현한다 .
     */

    public static void main(String[] args) throws IOException {

        n = Integer.parseInt(br.readLine());
        arr = new int[n][n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        solve2048(5, arr);
        System.out.println(result);
        bw.close();
        br.close();
    }

    static int result = 0;

    // deps 가 0이 될때까지 회전과 밀어넣기를 한다.
    private static void solve2048(int deps, final int[][] arr) {
        if (deps <= 0) {
            for (int[] ints : arr) {
                for (int anInt : ints) {
                    result = Math.max(result, anInt);
                }
            }
            return;
        }
        for (int i = 0; i < 4; i++) {
            int solvingArr[][] = rotate2048AndCombine(arr, i);
            solve2048(deps - 1, solvingArr);
        }
    }

    private static int[][] rotate2048AndCombine(int[][] arr, int k) {
        // 배열 회전
        int[][] cloneArr = rotate(k, arr);
        for (int i = 0; i < n; i++)
            pullingArr(cloneArr[i]);

        // 회전한 곳을 기반으로 밀어넣고 계산
        for (int i = 0; i < n; i++) {
            int j = 0;
            int pulling_C = 0;
            while (j < n) {
                int current_row[] = cloneArr[i];
                if (j + 1 < n && current_row[j] == current_row[j + 1]) {
                    current_row[j] *= 2;
                    current_row[j + 1] = 0;
                    pullingArr(current_row);
                }
                j++;
            }
        }
        return cloneArr;
    }

    private static int[][] rotate(int k, int[][] arr) {
        int cloneArr[][] = cloneArr(arr);

        while (k-- > 0) {
            int resultArr[][] = new int[cloneArr.length][cloneArr.length];
            for (int y = 0; y < n; y++) {
                for (int x = 0; x < n; x++) {
                    int next_y = x;
                    int next_x = n - (y + 1);
                    resultArr[next_y][next_x] = cloneArr[y][x];
                }
            }
            cloneArr = resultArr;
        }
        return cloneArr;
    }

    private static int[][] cloneArr(int[][] targetArr) {
        int clone_arr[][] = new int[targetArr.length][];
        for (int i = 0; i < clone_arr.length; i++) {
            clone_arr[i] = targetArr[i].clone();
        }
        return clone_arr;
    }


    private static void pullingRow(int[][] cloneArr, int r, int index) {
        int current_row[] = cloneArr[r];
        for (int k = index; k + 1 < n; k++) {
            current_row[k] = current_row[k + 1];
            current_row[k + 1] = 0;
        }


    }


    private static void pullingArr(int[] cloneArr) {
        int l = 0;
        while (l < n) {
            if (cloneArr[l] == 0) {
                int r = l + 1;
                while (r < n && cloneArr[r] == 0) r++;
                if (r < n && cloneArr[r] != 0) {
                    cloneArr[l] = cloneArr[r];
                    cloneArr[r] = 0;
                }
            }
            l++;
        }
    }


}