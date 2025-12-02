import java.io.*;
import java.math.BigInteger;
import java.util.*;

import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int  N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        Set hMap = new HashSet();
        for (int i = 0; i < N; i++) {
            hMap.add(Integer.parseInt(st.nextToken()));
        }
        N = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            if(hMap.contains(Integer.parseInt(st.nextToken())))bw.write(String.valueOf(1));
            else bw.write(String.valueOf(0));
            bw.write("\n");
            bw.flush();
        }


    }
}