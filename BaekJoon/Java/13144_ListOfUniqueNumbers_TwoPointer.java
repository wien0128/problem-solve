import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// ListOfUniqueNumbers 13144 TwoPointer
// 연속한 n 개 이상의 수를 뽑는 경우의 수 = n(n + 1) / 2
// O( n )


public class Main {
    public static final int MAX = 100_001;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < n; ++i) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int[] freq = new int[MAX];
        int l = 0;
        long res = 0;

        for (int r = 0; r < n; ++r) {
            ++freq[arr[r]];

            while (freq[arr[r]] > 1) {
                --freq[arr[l]];
                ++l;
            }

            res += (r - l + 1); // 윈도우 사이의 모든 연속 부분 배열의 길이 추가
        }

        System.out.println(res);
    }
}
