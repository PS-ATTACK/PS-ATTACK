 
import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

/**
 * 6 4
 * 0 0 0 0 0 0
 * 0 0 0 0 0 0
 * 0 0 0 0 0 0
 * 0 0 0 0 0 1
 */
public class Main {
    private static StringTokenizer st;
    private static int n, m, box[][], unRipesTomatoCount = 0;
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static Queue<Tomato> queue = new LinkedList<>();

    private static final int dirs[][] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        box = new int[n][m];

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                box[j][i] = Integer.parseInt(st.nextToken());
                if (box[j][i] == 0) unRipesTomatoCount++;
                else if (box[j][i] == 1) queue.add(new Tomato(j, i, 0));
            }
        }

        int result = 0;
        while (!queue.isEmpty()) {
            Tomato pollTomato = queue.poll();
            result = Math.max(pollTomato.days, result);
            for (int i = 0; i < 4; i++) {
                int nextY = pollTomato.y + dirs[i][0];
                int nextX = pollTomato.x + dirs[i][1];
                if (isValid(nextY, nextX) && box[nextY][nextX] == 0) {
                    Tomato unRipestomato = new Tomato(nextY, nextX, pollTomato.days + 1);
                    queue.add(unRipestomato);
                    box[nextY][nextX] = 1;
                    unRipesTomatoCount--;
                }
            }
        }
        if (unRipesTomatoCount > 0) {
            System.out.println(-1);
        } else System.out.println(result);


        bw.close();
        br.close();
    }

    private static boolean isValid(int y, int x) {
        return y >= 0 && y < n && x >= 0 && x < m;
    }

}

class Tomato {
    int y;
    int x;
    int days;

    public Tomato(int y, int x, int days) {
        this.y = y;
        this.x = x;
        this.days = days;
    }
}