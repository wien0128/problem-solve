import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

// 2000문제푼임스 25822 DP
// O( N )

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        double c = Double.parseDouble(br.readLine().trim());
        int n = Integer.parseInt(br.readLine().trim());

        int[] solved = new int[n];
        st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < n; ++i) {
            solved[i] = Integer.parseInt(st.nextToken());
        }

        // 최대 사용 가능한 프리즈 개수
        int maxFreezes = Math.min(2, (int) (c / 0.99));
        // 가장 많이 푼 문제 수
        int maxSolved = Arrays.stream(solved).max().orElse(0);

        // dp[i][j] = i번째 날까지 j개의 프리즈를 사용했을 때의 최대 스트릭 일수
        int[][] dp = new int[n + 1][maxFreezes + 1];
        int maxStreak = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= maxFreezes; ++j) {
                if (solved[i - 1] > 0) {    // 문제를 푼 날이라면
                    dp[i][j] = dp[i - 1][j] + 1;
                } else if (j > 0) {         // 문제를 풀지 못했고, 프리즈를 사용할 수 있다면
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {                    // 문제를 풀지 못했고, 프리즈를 사용할 수 없다면
                    dp[i][j] = 0;
                }

                maxStreak = Math.max(maxStreak, dp[i][j]);
            }
        }

        System.out.println(maxStreak + "\n" + maxSolved);
    }
}
