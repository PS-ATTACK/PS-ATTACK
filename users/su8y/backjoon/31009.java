import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    // format : [도착지, 요금]
    // 입력 값에는 진주가 반드시 존재
    // 1. 진주로 가는 교통편의 요금을 알아보고
    // 2. 진부보다 높은 가격의 교통편의 개수도 알아본다.

    private final static String JINJU = "jinju";
    private static List<Integer> toolFeeList;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());

        int count = 0;
        int feeOfJinju = 0;
        toolFeeList = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            String destination = st.nextToken();
            int tollFee = Integer.parseInt(st.nextToken());

            if (JINJU.equals(destination)) feeOfJinju = tollFee;
            else toolFeeList.add(tollFee);
        }


        for (Integer toolFee : toolFeeList) {
            if (feeOfJinju < toolFee) count++;
        }
        bw.write(String.format("%d\n", feeOfJinju));
        bw.write(String.format("%d", count));

        bw.flush();
        bw.close();
        br.close();
    }
}