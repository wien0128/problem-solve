import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 눈덩이굴리기 21735 BackTracking
// O( 2^m )


public class Main {
    static int n, m;
    static int res;
    static int[] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        arr = new int[n + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; ++i) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        DFS(1, 0, 0);

        System.out.println(res);
    }

    private static void DFS(int size, int time, int pos) {
        res = Math.max(res, size);
        if (time == m) return;

        if (pos + 1 <= n) {
            DFS(size + arr[pos + 1], time + 1, pos + 1);
        }
        if (pos + 2 <= n) {
            DFS((size / 2) + arr[pos + 2], time + 1, pos + 2);
        }
    }
}
