import java.io.*;
import java.util.StringTokenizer;
import static java.lang.Math.*;

public class Main {
    static int A,B,C,D,E,F,G,H,I,J,K,L,N,M,O,P,Q,R,S,T,U,V,W,X,Y,Z;
    static int cache[][];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        String input = br.readLine();
        if(input.equals("N") || input.equals("n"))
            bw.write("Naver D2");
        else
            bw.write("Naver Whale");

        bw.flush();
        bw.close();
        br.close();
    }
}