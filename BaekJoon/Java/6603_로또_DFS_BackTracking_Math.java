import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 로또 6603 DFS, BackTracking, Math
// O( kC6 )


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
        StringBuilder sb = new StringBuilder();

        while (true) {
            st = new StringTokenizer(br.readLine());

            int k = Integer.parseInt(st.nextToken());

            if (k == 0) break;

            int[] s = new int[k];
            for (int i = 0; i < k; ++i) {
                s[i] = Integer.parseInt(st.nextToken());
            }

            DFS(s, new int[6], 0, 0, sb);
            sb.append("\n");
        }

        System.out.println(sb.toString());
    }

    private static void DFS(int[] s, int[] cur, int start, int depth, StringBuilder sb) {
        if (depth == 6) {
            for (int n : cur) {
                sb.append(n).append(" ");
            }
            sb.append("\n");
            return;
        }

        for (int i = start; i < s.length; ++i) {
            cur[depth] = s[i];
            DFS(s, cur, i + 1, depth + 1, sb);
        }
    }
}
