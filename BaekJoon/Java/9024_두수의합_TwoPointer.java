import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

// 두수의합 9024 TwoPointer
// k 에 가장 가까운 두 수의 합의 개수
// O( T * nlogn )


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());

            int[] arr = new int[n];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; ++i) {
                arr[i] = Integer.parseInt(st.nextToken());
            }

            // 오름차순
            Arrays.sort(arr);

            int l = 0, r = n - 1;
            int closestDiff = Integer.MAX_VALUE;
            int cnt = 0;

            while (l < r) {
                int curSum = arr[l] + arr[r];
                int curDiff = Math.abs(curSum - k);

                if (curDiff < closestDiff) {
                    closestDiff = curDiff;
                    cnt = 1;
                } else if (curDiff == closestDiff) {
                    ++cnt;
                }

                if (curSum < k) {
                    ++l;
                } else {
                    --r;
                }
            }

            System.out.println(cnt);
        }
    }
}
