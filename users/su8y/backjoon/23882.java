import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

  public static void main(String[] args) throws IOException {
    var br = new BufferedReader(new InputStreamReader(System.in));
    var st = new StringTokenizer(br.readLine());
    int n = Integer.parseInt(st.nextToken());
    int k = Integer.parseInt(st.nextToken());

    int[] arr = new int[n];

    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < n; i++)
      arr[i] = Integer.parseInt(st.nextToken());

    if (k == 0) {
      printArray(arr);
      return;
    }
    int changeCount = 0;
    for (int i = 0; i < n; i++) {
      int maxValue = 0;
      int maxIndex = -1;
      for (int j = 0; j < n - i; j++) {
        if (arr[j] > maxValue) {
          maxValue = arr[j];
          maxIndex = j;
        }
      }

      if (n - i - 1 == maxIndex)
        continue;
      else {
        int tmp = arr[n - i - 1];
        arr[n - i - 1] = maxValue;
        arr[maxIndex] = tmp;
        changeCount++;
      }
      if (changeCount == k) {
        printArray(arr);
        return;
      }
    }

    System.out.println(-1);

    br.close();
  }

  private static void printArray(int[] arr) {
    StringBuilder sb = new StringBuilder();
    for (int e : arr) {
      sb.append(e).append(" ");
    }
    System.out.println(sb);
  }

}