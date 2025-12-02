import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
    private static int blueCount = 0, n, whiteCount = 0;
    private static int map[][];

    public static void main(String[] args) throws IOException {
        /**
         * 분할 정복: 문제를 분할해서 생각한다.
         *
         *
         */
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        map = new int[n+1][n+1];
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int i1 = 1; i1 <= n; i1++) {
                map[i][i1] = Integer.parseInt(st.nextToken());
            }
        }

        check(1, 1, n);

        System.out.println(whiteCount);
        System.out.println(blueCount);

        br.close();
    }

    private static void check(int y, int x, int size) {

        // 만약 검사중에 다른점이 생겼다.
        // N*M

        int result = condition(y, x, size);
        int half = size / 2;
        if (result == 0) whiteCount++;
        else if (result == 1) blueCount++;
        else {
            check(y, x, half);
            check(y + half, x + half, half);
            check(y, x + half, half);
            check(y + half, x , half);

        }

    }

    private static int condition(int y, int x, int size) {
        int head = map[y][x];

        for (int dy = y; dy < y + size; dy++)
            for (int dx = x; dx < x + size; dx++)
                if (map[dy][dx] != head) return -1;

        return head;
    }
}