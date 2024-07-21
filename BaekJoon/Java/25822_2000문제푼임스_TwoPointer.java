import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

// 2000문제푼임스 25822 TwoPointer
// O( N )

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        double c = Double.parseDouble(br.readLine());
        int n = Integer.parseInt(br.readLine());

        int[] solved = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; ++i) {
            solved[i] = Integer.parseInt(st.nextToken());
        }

        int maxFreezes = Math.min(2, (int) (c / 0.99));
        int maxSolved = Arrays.stream(solved).max().orElse(0);

        int l = 0, r = 0;   // 투 포인터
        int freezeUsed = 0; // 사용한 프리즈 개수
        int maxStreak = 0;  // 최대 스트릭 유지 일수
        int curStreak = 0;  // 현재 스트릭 유지 일수

        while (r < n) {
            // i번째 날에 푼 문제가 있다면
            if (solved[r] > 0) {
                ++curStreak;
                ++r;
            } else {
                // 프리즈를 사용할 수 있다면
                if (freezeUsed < maxFreezes) {
                    ++freezeUsed;
                    ++curStreak;
                    ++r;
                } else {    // 프리즈를 사용할 수 없다면
                    if (solved[l] == 0) {
                        --freezeUsed;
                    }
                    --curStreak;
                    ++l;
                }
            }

            maxStreak = Math.max(maxStreak, curStreak);
        }

        System.out.println(maxStreak + "\n" + maxSolved);
    }
}
