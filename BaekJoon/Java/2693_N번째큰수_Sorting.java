import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

// N번째큰수 2693 Sorting
// O( N )


public class Main {
    static int T;
    static int[] nums = new int[10];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
        StringBuilder sb = new StringBuilder();

        T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < 10; ++i) {
                nums[i] = Integer.parseInt(st.nextToken());
            }

            Arrays.sort(nums);

            sb.append(nums[7]).append("\n");
        }

        System.out.println(sb);
    }
}
