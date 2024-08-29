import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 로마숫자만들기 16922 BackTracking
// 순서 상관없이 모든 경우의 수 탐색
// O( 4^N )


public class Main {
    static int n;
    static Set<Integer> sums = new HashSet<>();
    static int[] roman = { 1, 5, 10, 50 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(br.readLine());

        DFS(0, 0, 0);

        System.out.println(sums.size());
    }

    private static void DFS(int depth, int start, int curSum) {
        if (depth == n) {
            sums.add(curSum);
            return;
        }

        for (int i = start; i < 4; ++i) {
            if (depth + 1 > n) break;

            DFS(depth + 1, i, curSum + roman[i]);
        }
    }
}
