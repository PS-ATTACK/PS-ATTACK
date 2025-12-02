import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    /**
     * N = 1_000_000
     * Nlog(N) 시간복잡도 아래로 풀어야 한다.
     * <p>
     * 1. 정렬을 한다 .
     * 2. front 포인터와 back 포인터와 비교를 한다.
     * 3. 비교를 할때 front와 back에 대해서 교차intersection하는지 확인한다.
     * 4. intersection 을 한다면 front와 back의 최소 최대 값을 갱신 해준다.
     * 4-1. 갱신을 할 때 이미 정렬이 되어 있기 때문에 x1 < x2 || y1 < y2 이 식을 만족하기 때문에 별다른 연산없이 front[0]과 back[1]로 갱신을 해준다.
     * 5. 갱신을 해주는 것에 대해서 공간을 만들어야 하는데 그 공간은 tmpArr를 사용한다. 이곳에서 front를 검사
     * 5-1. back은 원본 배열에서 검사한다.
     * 5-2. tmpArr에는 기본값으로 원본배열의 첫번째 배열이 들어가 있어야 한다.
     * 6. front와 back이 intersection 하지 않는다면 그것은 배열을 다시 만들어야 한다는 뜻이므로 front를 +1 해준다.
     * 6-1. 그리고 tmpArr[front+1]에 교차하지 않는것에 대한 원본배열[back]을 넣어준다.
     * 7. for문에 대해서 i가 N-1 이라면 종료 한다.
     * <p>
     * <p>
     * 8. 결과 집계 배열의 값이 들어가게 되는데 1에서 3이라면 1,2,3 총 2의 길이를 가지게 된다. 식은 | x2 -x1 | 이다.
     */
    static int totalLength = 0, N;
    static List<Line> research = new ArrayList<>();

    static Line[] originalLines;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());

        originalLines = new Line[N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            originalLines[i] = new Line(x1, x2);
        }

        
        Arrays.sort(originalLines, Line::compareTo);
        int front = 0, back = 1;
        research.add(originalLines[0]);


        while (back < N) {
            Line target = originalLines[back];
            Line source = research.get(front);

            if (source.isIntersection(target)) {
                source.update(source.x1, target.x2);
            } else {
                research.add(target);
                front++;
            }
            back++;
        }


        for (Line line : research) {
            totalLength += line.getLength();
        }
        System.out.println(totalLength);

    }

}

class Line implements Comparable<Line> {
    public int x1;
    public int x2;

    public Line(int x1, int x2) {
        this.x1 = x1;
        this.x2 = x2;
    }

    public boolean isIntersection(Line target) {
        return this.x2 >= target.x1;
    }

    public int getLength() {
        return Math.abs(x1 - x2);
    }

    public void update(int x1, int x2) {
        this.x1 = x1;
        this.x2 = Math.max(this.x2,x2);
    }


    @Override
    public int compareTo(Line o) {
        if (this.x1 < o.x1) {
            return -1;
        } else if (this.x1 == o.x1) {
            return this.x2 < o.x2 ? -1 : 1;
        } else {
            return 1;
        }
    }


}
