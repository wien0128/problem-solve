import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

// 수고르기 2230 TwoPointer
// 수열에서 차이가 M 이상이면서 제일
// 작은 경우의 두 수를 구하는 문제


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[] arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        // 오름차순
        Arrays.sort(arr);

        int l = 0, r = 0;
        int minDiff = Integer.MAX_VALUE;

        while (r < n) {
            int tmp = arr[r] - arr[l];

            if (tmp >= m) {
                minDiff = Math.min(minDiff, tmp);
                if (minDiff == m) break;
                ++l;
            } else {
                ++r;
            }
        }

        System.out.println(minDiff);
    }
}
