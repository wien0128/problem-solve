import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 연산자끼워넣기 14888 BackTracking
// O( (N - 1)! )


public class Main {
        static int n;
        static int[] nums, ops;
        static int maxValue = Integer.MIN_VALUE;
        static int minValue = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        n = Integer.parseInt(br.readLine());

        st = new StringTokenizer(br.readLine());
        nums = new int[n];
        for (int i = 0; i < n; ++i) {
            nums[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        ops = new int[4];
        for (int i = 0; i < 4; ++i) {
            ops[i] = Integer.parseInt(st.nextToken());
        }

        dfs(1, nums[0]);

        System.out.println(maxValue + "\n" + minValue);
    }

    private static void dfs(int idx, int curRes) {
        if (idx == n) {
            minValue = Math.min(minValue, curRes);
            maxValue = Math.max(maxValue, curRes);
            return;
        }

        for (int i = 0; i < 4; ++i) {
            if (ops[i] > 0) {
                --ops[i];
                int nextRes = switch (i) {
                    case 0 -> curRes + nums[idx];
                    case 1 -> curRes - nums[idx];
                    case 2 -> curRes * nums[idx];
                    case 3 -> curRes / nums[idx];
                    default -> throw new IllegalStateException("");
                };
                dfs(idx + 1, nextRes);
                ++ops[i];
            }
        }
    }
}
