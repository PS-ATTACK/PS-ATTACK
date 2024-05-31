import java.io.*;
import java.util.*;

class Main {

	// R의 최댓값 (x[i]의 최댓값보다 크면 충분)
	private static final int MAX_VALUE = 1_000_001;

	private static int n;
	private static long c; // C의 범위가 10^9이므로 long으로 변경
	private static int[] t;
	private static int[] x;

	public static void main(String[] args) throws IOException {
		input();

		double lo = -1;
		double hi = MAX_VALUE; // R의 최댓값

		// 1. double의 이진 탐색은 100~200회 반복하여 정밀도를 확보합니다.
		for (int i = 0; i < 100; i++) {
			double mid = (lo + hi) / 2;

			// 2. check(mid)는 "R=mid일 때 넘치지 않는가?"
			if (check(mid)) {
				// -> R을 더 줄여본다.
				hi = mid;
			} else {
				// -> R을 더 늘려야 한다.
				lo = mid;
			}
		}

		//    (예제의 0.999... 는 1.0이 경계값일 때의 부동소수점 오차입니다)
		System.out.println(hi < 0 ? 0.0 : hi);
	}

	/**
	 * 배출량 R (exit)로 설정했을 때, 물탱크가 C를 넘지 않는지 검사합니다.
	 * O(n)의 시간 복잡도를 가집니다.
	 *
	 * @param R : 테스트할 배출량 R
	 * @return true (넘치지 않음), false (넘침)
	 */
	private static boolean check(double R) {
		double currentWater = 0.0; // 현재 물의 양

		for (int i = 0; i < n; i++) {
			// 순 변화율 (Net Rate) = 유입량 - 배출량
			double netRate = x[i] - R;

			if (netRate > 0) {
				// 1. 물이 차오르는 경우 (x[i] > R)
				//    최대 수위는 t[i]초 후에 발생합니다.
				//    이때 C를 넘는지 검사합니다.
				if (currentWater + netRate * t[i] > c) {
					return false; // R이 너무 작아서 넘쳤습니다.
				}
			}
			// 2. 물이 빠지는 경우 (x[i] <= R)
			//    최대 수위는 현재(0초)의 currentWater입니다.
			//    이는 이미 이전 단계에서 C를 넘지 않음이 보장되었으므로
			//    이 구간에서 넘칠 일이 없습니다. (검사 불필요)

			// 3. 현재 물의 양을 t[i]초 후로 업데이트합니다.
			currentWater += netRate * t[i];

			// 4. 물탱크가 비었으면 0.0으로 맞춰줍니다.
			currentWater = Math.max(0.0, currentWater);
		}

		// 모든 구간을 통과했으면 이 R값은 성공입니다.
		return true;
	}

	private static void input() throws IOException {
		var br = new BufferedReader(new InputStreamReader(System.in));
		var st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		c = Long.parseLong(st.nextToken()); // C를 long으로 읽음
		t = new int[n];
		x = new int[n];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			t[i] = Integer.parseInt(st.nextToken());
		}

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			x[i] = Integer.parseInt(st.nextToken());
		}
	}
}