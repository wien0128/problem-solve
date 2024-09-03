import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 도영이가만든맛있는음식 2961 BackTracking
// O( 2^n )


public class Main {
    static int n;
    static int[][] arr;
    static int minDiff;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        n = Integer.parseInt(br.readLine());
        arr = new int[n][2];

        for (int i = 0; i < n; ++i) {
            st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
        }

        minDiff = Integer.MAX_VALUE;

        DFS(0, 1, 0);

        System.out.println(minDiff);
    }

    private static void DFS(int idx, int S, int B) {
        if (idx == n) {
            if (S != 1 || B != 0) {
                minDiff = Math.min(minDiff, Math.abs(S - B));
            }
            return;
        }

        DFS(idx + 1, S * arr[idx][0], B + arr[idx][1]);
        DFS(idx + 1, S, B);
    }
}
