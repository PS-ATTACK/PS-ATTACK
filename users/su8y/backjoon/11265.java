package solved.ac;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ_11265_끝나지_않는_파티 {

	// 8:34 -> 8:47 (13min)
	public static void main(String[] args) throws IOException {
		var inputs = new BufferedReader(new InputStreamReader(System.in));
		var tokens = new StringTokenizer(inputs.readLine());

		int n = Integer.parseInt(tokens.nextToken()), m = Integer.parseInt(tokens.nextToken());

		long[][] graph = new long[n][n];

		for (int i = 0; i < n; i++) {
			tokens = new StringTokenizer(inputs.readLine());
			for (int j = 0; j < n; j++) {
				graph[i][j] = Integer.parseInt(tokens.nextToken());
				if (graph[i][j] == 0) graph[i][j] = 1_000_001L;
			}
		}

		// 생성
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					graph[i][j] = Math.min(graph[i][k] + graph[k][j], graph[i][j]);
				}
			}
		}

		var outputs = new StringBuilder();
		for (int i = 0; i < m; i++) {
			int[] query = Arrays.stream(inputs.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
			if (graph[query[0] - 1][query[1] - 1] <= query[2]) {
				outputs.append("Enjoy other party\n");
			} else {
				outputs.append("Stay here\n");

			}
		}
		System.out.println(outputs);
	}
}
