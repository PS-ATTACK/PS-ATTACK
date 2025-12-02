import java.io.*;
import java.util.Arrays;
import java.util.Stack;
import java.util.StringTokenizer;


public class Main {


    static int[] arr, lis;

    public static void main(String[] args) throws IOException {
        StringTokenizer st;
        int n, record[];
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        n = Integer.parseInt(br.readLine());
        arr = new int[n];
        lis = new int[n];
        record = new int[n];


        arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        int l = 0;
//        arr[0] = Integer.parseInt(st.nextToken());
        lis[0] = arr[0];
        record[0] = 0;

        for (int r = 1; r < n; r++) {
            int num = arr[r];
            if (lis[l] < num) {
                lis[l + 1] = num;
                record[r] = l + 1;
                l++;
            } else {
                int lowIndex = binarysearch(-1, l, num);
//                int lowIndex = Arrays.binarySearch(Arrays.copyOfRange(lis, 0, l + 1), num);
//                lowIndex = lowIndex >= 0 ? lowIndex : (-lowIndex) - 1;
                lis[lowIndex] = num;
                record[r] = lowIndex;
            }
        }


//        sb.append(l + 1).append("\n");
        bw.write(String.valueOf(l + 1));
        bw.write("\n");

        Stack<Integer> list = new Stack<>();

        for (int i = record.length - 1, degree = l;
             i >= 0;
             i--) {
            if (degree == record[i]) {
                list.push(arr[i]);
                degree = degree - 1;
            }
        }

        while (!list.isEmpty()) {
            bw.write(list.pop().toString());
            bw.write(" ");
        }


        bw.flush();
        bw.close();
        br.close();
    }

    public static int binarysearch(int l, int r, int now) {
        int mid;
        while (l + 1 < r) {
            mid = (l + r) / 2;
            if (lis[mid] < now) l = mid;
            else r = mid;
        }
        return r;
    }

    public static int upper_bound(int l, int r, int now) {
        int mid;
        while (l + 1 < r) {
            mid = (l + r) / 2;
            if (lis[mid] <= now) l = mid + 1;
            else r = mid;
        }
        return r;
    }
}