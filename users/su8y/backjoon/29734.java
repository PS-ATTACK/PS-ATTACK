import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		var br = new BufferedReader(new InputStreamReader(System.in));
		var token = new StringTokenizer(br.readLine());
		var output = new StringBuilder();

		long n = Long.parseLong(token.nextToken()); // 집 과제 시간
		long m = Long.parseLong(token.nextToken()); // 독서실 과제 시간

		token = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(token.nextToken()); // 이동 시간
		int s = Integer.parseInt(token.nextToken()); // 수면 시간

		long homeMin = studyOnHome(n, s);

		long studyRoomTime = studyOnDok(m, t, s);

		if (homeMin < studyRoomTime) {
			output.append("Zip\n")
					.append(homeMin)
					.append("\n");
		} else {
			output.append("Dok\n")
					.append(studyRoomTime)
					.append("\n");
		}
		System.out.println(output);
		return;
	}

	private static long studyOnHome(long n, int s) {
		long time = n;
		long count = time / 8;
		long mod = time % 8;
		if (count != 0 && mod == 0) {
			count--;
		}
		time += count * s;

		return time;
	}

	private static long studyOnDok(long m, int t, int s) {
		long time = m;

		long count = time / 8;
		long mod = time % 8;

		if (time > 0) {
			time += t; // 이동 시간
		}

		if (count != 0 && mod == 0) {
			count--;
		}
		time += count * s;
		time += count * t * 2;


		return time;
	}
}