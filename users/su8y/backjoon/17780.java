import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

@SuppressWarnings("unchecked")
public class Main {

    private static int[][] dirs = {{0, 0}, {0, 1}, {0,-1}, {-1, 0}, {1, 0}};


    private static int[][] color = new int[13][13];
    private static Horse[] horses = new Horse[11];

    // index순으로 찾는데. 업힌것도 찾아야 한다. // 말의 index를 저장하는 state 맵
    private static List<Integer>[][] state = new ArrayList[13][13];


    private static int n, k;

    // 1. 이동한다.
    // 2. 합친다.
    // - 말은 방향과 Index를 가지고 있다.
    // - 맵은 색을 가지고 있다.
    // - 맵은 말을 가지고 있다. -> 말은 어느 위치(y,x)의 맵에 있는지 알수 있다.
    // - 말은 여려 겹 쌓일수 있다. 그리고 반대로 하는 연산도 필요하다.
    static class Horse {
        int index;
        int direction;
    }

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        // 입력
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                state[i][j] = new ArrayList<>();
                color[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        for (int i = 1; i <= k; i++) {
            st = new StringTokenizer(br.readLine());
            int y = Integer.parseInt(st.nextToken()) - 1;
            int x = Integer.parseInt(st.nextToken()) - 1;
            int dir = Integer.parseInt(st.nextToken());
            horses[i] = new Horse();
            Horse hors = horses[i];
            hors.direction = dir;
            hors.index = i;
            state[y ][x ].add(i);
        }


        // 처리
        int point = 0;
        boolean gameState = true;
        while (gameState) {
            point++;
            if (point > 1000) {
                break;
            }
            // 해당 말
            for (int horseIndex = 1; horseIndex <= k; horseIndex++) {
                // 말의 이동
                boolean flag = false;

                for (int i = 0; i < n; i++) {
                    if(flag) break;
                    for (int j = 0; j < n; j++) {
                        if(flag) break;
                        //   - 해당 index의 말을 찾는다 .
                        List<Integer> finds = state[i][j];
                        if(finds.isEmpty()) continue;
                        int findIndex = finds.get(0);
                        if (findIndex != horseIndex) continue;

                        Horse findHorse = horses[findIndex];
                        List<Integer> pigBackHorses = state[i][j];

                        int[] dir = dirs[findHorse.direction]; // 0: y 1: x
                        int nextY = i + dir[0], nextX = j + dir[1];

                        //   - 이동 한다.
                        // 파란색이거나 범위 밖이라면
                        if (!isValid(nextY, nextX) || color[nextY][nextX] == 2) {
                            // 방향을 바꾼다.
                            findHorse.direction = rdir(findHorse.direction);
                            dir = dirs[findHorse.direction];
                            nextY = i + dir[0];
                            nextX = j + dir[1];
                        }

                        if (!isValid(nextY, nextX) || color[nextY][nextX] == 2 ){
                            continue;
                        }else {
                            move(nextY, nextX, pigBackHorses);
                            state[i][j].clear();
                        }

                        flag = true;
                        // 이동한 후 상태 체크
                        if (isEnd(state[nextY][nextX].size())) {
                            gameState = false;
                        }
                        break;


                    }
                }

            }

        }

        bw.write(String.format("%d",point > 1000 ? -1 : point));

        bw.flush();
        bw.close();
        br.close();
    }

    private static void move(int y, int x, final List<Integer> pigbackHorse) {
        int c = color[y][x];
        // 블루 인 경우는 없다.
        if(c == 1){
            Collections.reverse(pigbackHorse);
        }

        state[y][x].addAll(pigbackHorse);

    }

    public static boolean isValid(int y, int x) {
        return y >= 0 && y < n && x >= 0 && x < n;
    }

    public static boolean isEnd(int length) {
        return length >= 4;
    }

    private static int rdir(int index) {
        switch (index) {
            case 1:
                return 2;
            case 2:
                return 1;
            case 3:
                return 4;
            default:
                return 3;
        }
    }

}