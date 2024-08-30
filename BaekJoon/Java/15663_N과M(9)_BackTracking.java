import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// N과M(9) 15663 BackTracking
// 중복 방지가 핵심인 문제
// O( M * N^M )


public class Main {
    static int n, m;
    static int[] nums, seq;
    static boolean[] used;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        nums = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; ++i) {
            nums[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(nums);
        used = new boolean[n];
        seq = new int[m];

        DFS(0);

        System.out.println(sb);
    }

    private static void DFS(int depth) {
        if (depth == m) {
            for (int i = 0; i < m; ++i) {
                sb.append(seq[i]).append(' ');
            }
            sb.append('\n');
            return;
        }

        int prev = -1;
        for (int i = 0; i < n; ++i) {
            if (used[i] || nums[i] == prev)
                continue;

            used[i] = true;
            seq[depth] = nums[i];
            DFS(depth + 1);
            used[i] = false;
            prev = nums[i];
        }
    }
}
