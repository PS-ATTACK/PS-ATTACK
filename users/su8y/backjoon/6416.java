import java.io.*;
import java.util.*;

class Main {
	// 하나의 루트노드
	// 모든 노드는 간선이 존재
	private static int[] arr;
	private static int max = 0;

	public static void main(String[] args) throws IOException {
		var br = new BufferedReader(new InputStreamReader(System.in));
		var sb = new StringBuilder();
		int T = 1;
		while (true) {
			var st = new StringTOkenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			if (u == -1 && v == -1) {
				break;
			}
			if (u == 0 && v == 0) {
				T++;
				arr = new int[max];
				max = 0;
				// algorithm
				continue;
			}

			max = Math.max(max, Math.max(u, v));

		}

	}
}