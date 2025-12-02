import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer buffer = new StringBuffer();
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(br.readLine());
            int arr[] = new int[n + 1];
            int total = 0;
            int maxValue = 0;
            for (int j = 1; j <= n; j++) {
                arr[j] = Integer.parseInt(br.readLine());
                total += arr[j];
                maxValue = Math.max(maxValue, arr[j]);
            }
            int result = 0;
            // 23 // 11.5
            for (int j = 1; j <= n; j++) {
                if (maxValue > arr[j]) continue;
                if (result != 0) {
                    result = 0;
                    break;
                }
                result = j;
            }
            if (result != 0) {
                if (maxValue > (double) total / 2) {
                    System.out.println("majority winner " + result);
                } else System.out.println("minority winner " + result);
            } else {
                System.out.println("no winner");
            }

        }

    }
}