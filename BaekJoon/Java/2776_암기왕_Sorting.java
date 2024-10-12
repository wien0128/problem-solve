import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

// 암기왕 2776 Sorting
// O( (n + m) log n )


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());

        int t = Integer.parseInt(st.nextToken());

        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int[] note1 = new int[n];

            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; ++i) {
                note1[i] = Integer.parseInt(st.nextToken());
            }

            Arrays.sort(note1);

            int m = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < m; ++i) {
                int q = Integer.parseInt(st.nextToken());
                // note1에 q가 있으면 1, 없으면 0 추가
                sb.append(Arrays.binarySearch(note1, q) >= 0 ? "1\n" : "0\n");
            }
        }

        System.out.println(sb);
    }
}
