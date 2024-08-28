import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 부분수열의합 1182 BackTracking
// O( 2^N )


public class Main {
    static int n;
    static int s;
    static int cnt = 0;
    static int[] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        s = Integer.parseInt(st.nextToken());

        arr = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; ++i) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        BackTracking(0, 0);

        if (s == 0) --cnt;

        System.out.println(cnt);
    }

    public static void BackTracking(int idx, int curSum) {
        if (idx == n) {
            if (curSum == s) ++cnt;
            return;
        }

        BackTracking(idx + 1, curSum);
        BackTracking(idx + 1, curSum + arr[idx]);
    }
}
