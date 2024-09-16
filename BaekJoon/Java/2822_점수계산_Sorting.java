import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

// 점수계산 2822 Sorting
// O( 5 log5 + 3 ) = O(1)


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[][] scores = new int[8][2];
        for (int i = 0; i < 8; ++i) {
            scores[i][0] = Integer.parseInt(br.readLine());
            scores[i][1] = i + 1;
        }

        // 점수 기준 내림차순
        Arrays.sort(scores, (a, b) -> Integer.compare(b[0], a[0]));

        int sum = 0;
        int[] idx = new int[5];

        for (int i = 0; i < 5; ++i) {
            sum += scores[i][0];
            idx[i] = scores[i][1];
        }

        Arrays.sort(idx);

        System.out.println(sum);
        for (int i : idx) {
            System.out.print(i + " ");
        }
    }
}
