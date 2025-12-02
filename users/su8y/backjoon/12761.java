import java.io.*;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {


    private static StringTokenizer st;
    private static int A, B, N, M;
    private static int checked[];
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        long l = System.currentTimeMillis();
        st = new StringTokenizer(br.readLine());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        Queue<Integer> q = new LinkedList<>();
        checked = new int[100001];

        q.add(N);
        checked[N] = 1;

        while (!q.isEmpty()) {
            int currentLocation = q.poll();

            if (currentLocation == M) {
                bw.write(String.valueOf(checked[currentLocation]-1));
                break;
            }
            for(int i = 1 ; i <= 8 ; i++){
                int next = d(i, currentLocation);
                if(isValid(next)){
                    q.offer(next);
                    checked[next] = checked[currentLocation] +1;
                }

            }
        }


        bw.flush();
        bw.close();
        br.close();
    }

    static int d(int i,int currentLocation) {
        switch (i) {
            case 1:
                return currentLocation * A;
            case 2:
                return currentLocation * B;
            case 3:
                return currentLocation + A;
            case 4:
                return currentLocation + B;
            case 5:
                return currentLocation - A;
            case 6:
                return currentLocation - B;
            case 7:
                return currentLocation - 1;
            case 8:
                return currentLocation + 1;
        }
        return 0;
    }

    private static boolean isValid(int location) {
        return location >= 0 && location < 100001 && checked[location] == 0;
    }

}