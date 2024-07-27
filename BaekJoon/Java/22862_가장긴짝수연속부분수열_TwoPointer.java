import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 가장긴짝수연속한부분수열 22862 TwoPointer
// O( n )


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int[] arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int l = 0, r = 0;
        int maxLen = 0;
        int oddCnt = 0;

        while (r < n) {
            if (arr[r] % 2 != 0) {
                ++oddCnt;
            }

            while (oddCnt > k) {
                if (arr[l] % 2 != 0) {
                    --oddCnt;
                }
                ++l;
            }

            maxLen = Math.max(maxLen, r - l + 1 - oddCnt);
            ++r;
        }

        System.out.println(maxLen);
    }
}
