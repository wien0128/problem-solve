import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 도영이가만든맛있는음식 2961 BitMasking, BruteForce
// O( N * 2^N )


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

        for (int i = 1; i < (1 << n); ++i) {
            int S = 1, B = 0;
            for (int j = 0; j < n; ++j) {
                if ((i & (1 << j)) != 0) {
                    S *= arr[j][0];
                    B += arr[j][1];
                }
            }

            minDiff = Math.min(minDiff, Math.abs(S - B));
        }

        System.out.println(minDiff);
    }
}
