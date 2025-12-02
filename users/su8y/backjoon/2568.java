import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

class Main {
    /**
     * 두 전봇대 A와 B 사이에 하나 둘씩 전깃줄을 추가하다 보니 전깃줄이 서로 교차하는 경우가 발생하였다. 합선의 위험이 있어 이들 중 몇
     * 개의 전깃줄을 없애 전깃줄이 교차하지 않도록 만들려고 한다.
     * 
     * 예를 들어, <그림 1>과 같이 전깃줄이 연결되어 있는 경우 A의 1번 위치와 B의 8번 위치를 잇는 전깃줄, A의 3번 위치와 B의 9번
     * 위치를 잇는 전깃줄, A의 4번 위치와 B의 1번 위치를 잇는 전깃줄을 없애면 남아있는 모든 전깃줄이 서로 교차하지 않게 된다.
     * 
     * 
     * 
     * <그림 1>
     * 
     * 전깃줄이 전봇대에 연결되는 위치는 전봇대 위에서부터 차례대로 번호가 매겨진다. 전깃줄의 개수와 전깃줄들이 두 전봇대에 연결되는 위치의
     * 번호가 주어질 때, 남아있는 모든 전깃줄이 서로 교차하지 않게 하기 위해 없애야 하는 최소 개수의 전깃줄을 구하는 프로그램을 작성하시오.
     * 
     * 입력
     * 첫째 줄에는 두 전봇대 사이의 전깃줄의 개수가 주어진다. 전깃줄의 개수는 100,000 이하의 자연수이다. 둘째 줄부터 한 줄에 하나씩
     * 전깃줄이 A전봇대와 연결되는 위치의 번호와 B전봇대와 연결되는 위치의 번호가 차례로 주어진다. 위치의 번호는 500,000 이하의
     * 자연수이고, 같은 위치에 두 개 이상의 전깃줄이 연결될 수 없다.
     * 
     * 출력
     * 첫째 줄에 남아있는 모든 전깃줄이 서로 교차하지 않게 하기 위해 없애야 하는 전깃줄의 최소 개수를 출력한다. 둘째 줄부터 한 줄에 하나씩
     * 없애야 하는 전깃줄의 A전봇대에 연결되는 위치의 번호를 오름차순으로 출력한다. 만약 답이 두 가지 이상이라면 그 중 하나를 출력한다.
     * 
     * 예제 입력 1
     * 8
     * 1 8
     * 3 9
     * 2 2
     * 4 1
     * 6 4
     * 10 10
     * 9 7
     * 7 6
     * 예제 출력 1
     * 3
     * 1
     * 
     * 4
     * 
     * @param args
     *             우선 N^2 DP알고리즘으로는 10만개의 입력을 처리하기 어렵다. NlogN이나 N의 시간복잡도를 생각한다.
     *             (binary search)이용해서
     *             그리고 실제 없애야 하는 데이터를 알아야 한다.
     *             6 8 3 10
     *             이런 식으로 있을때
     *             Binary Search를 통하면 6 >> 3 7 10 이런식으로 DP테이블이 만들어 질것인데 경로 역추적을
     *             해야한다.
     *             실제 LIS 배열을 구하기 위해서는 실제 배열이 들어갔던 위치를 기억하는 record 테이블을 이용한다. (뒤에서
     *             부터 읽는다.)
     * 
     * 
     */
    private static int n, record[], lis[];
    private static StringTokenizer st;
    private static List<Pair> inputList;

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        inputList = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            inputList.add(new Pair(a, b));

        }
        Collections.sort(inputList);

        lis = new int[n];
        record = new int[n];
        int inputZero = inputList.get(0).x;
        record[0] = 0;
        lis[0] = inputZero;

        int start = 0;
        int end = 1;

        while (end < n) {
            int end_number = inputList.get(end).x;
            if (lis[start] < end_number) {
                lis[start + 1] = end_number;
                record[end] = start + 1;
                start++;
            } else {
                int pos = Math.abs(Arrays.binarySearch(Arrays.copyOfRange(lis, 0, start), end_number) + 1);
                lis[pos] = end_number;
                record[end] = pos;
            }
            end++;
        }
        int res = n - (start + 1);
        System.out.println(res); // index는 0부터 시작하기 때문에 개수를 새려면 이렇게 해야된다 . start - 1
        // 하지만 결과는 몇개를 없애야 하는가? 이기 때문에 n - (start + 1)
        int prev = start + 1;
        int[] isContinue = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            // -1 초기값 , record[i]+1 현재 레코드 +1 의 Index일때
            if (record[i] + 1 == prev) {
                prev = record[i];
                isContinue[i] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            // System.out.println(isContinue[i]);
            if (isContinue[i] == 1)
                continue;
            System.out.println(inputList.get(i).y);
        }
    }
}

class Pair implements Comparable<Pair> {
    int x;
    int y;

    Pair(int y, int x) {
        this.y = y;
        this.x = x;
    }

    @Override
    public int compareTo(Pair o) {
        return this.y - o.y;
    }

}