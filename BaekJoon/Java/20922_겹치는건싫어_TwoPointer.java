import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        BufferedReader br = new BufferReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int[] arr = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int[] cnt = new int[100_001];
        int l = 0, r = 0;
        int maxLen = 0;

        for (r = 0; r < n; r++) {
            cnt[arr[r]]++;

            while (cnt[arr[r]] > k) {
                cnt[arr[r]]--;
                l++;
            }

            maxLen = Math.max(maxLen, r - l + 1);
        }

        System.out.println(maxLen);
    }
}