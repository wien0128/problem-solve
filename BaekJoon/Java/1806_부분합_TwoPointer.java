import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 부분합 1806 TwoPointer
// S 이상인 부분합 중 가장 짧은 것 구하기
// O( n )


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(st.nextToken());

        int[] nums = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; ++i) {
            nums[i] = Integer.parseInt(st.nextToken());
        }

        int l = 0, r = 0;
        int sum = 0;
        int minLen = Integer.MAX_VALUE;

        while (r <= n) {
            if (sum >= s) {
                minLen = Math.min(minLen, r - l);
                sum -= nums[l++];
            } else {
                if (r < n) {
                    sum += nums[r];
                }
                ++r;
            }
        }

        System.out.println(minLen == Integer.MAX_VALUE ? 0 : minLen);
    }
}
