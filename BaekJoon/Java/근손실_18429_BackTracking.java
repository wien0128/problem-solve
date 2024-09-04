import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 근손실 18429 BackTracking
// O( N! )


public class Main {
    static final int MIN_POWER = 500;
    static int n, k, res;
    static int[] kits;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        res = 0;

        kits = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; ++i) {
            kits[i] = Integer.parseInt(st.nextToken());
        }

        DFS(0, MIN_POWER);

        System.out.println(res);
    }

    private static void DFS(int day, int power) {
        if (day == n) {
            ++res;
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (kits[i] == 0) continue;

            int curKit = kits[i];
            int newPower = power - k + curKit;

            if (newPower >= MIN_POWER) {
                kits[i] = 0;
                DFS(day + 1, newPower);
                kits[i] = curKit;
            }
        }
    }
}
