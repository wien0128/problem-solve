import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// N과M(10) 15664 BackTracking
// O( M * N^M )


public class Main {
    static int n, m;
    static int[] nums, seq;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        nums = new int[n];
        seq = new int[m];
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; ++i) {
            nums[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(nums);

        DFS(0, 0);

        System.out.println(sb);
    }

    private static void DFS(int depth, int start) {
        if (depth == m) {
            for (int i = 0; i < m; ++i) {
                sb.append(seq[i]).append(" ");
            }
            sb.append("\n");
            return;
        }

        int prev = -1;
        for (int i = start; i < n; ++i) {
            if (prev == nums[i]) continue;

            seq[depth] = nums[i];
            DFS(depth + 1, i + 1);
            prev = nums[i];
        }
    }
}
