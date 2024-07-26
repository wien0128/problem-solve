import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

// 로봇프로젝트 3649 BinarySearch
// 주어진 레고 조각들 중 두 조각의
// 합이 x 와 같은지 판별하는 문제
// O( nlogn )


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str;

        while ((str = br.readLine()) != null) {
            int x = Integer.parseInt(str) * 10_000_000;
            int n = Integer.parseInt(br.readLine());
            int[] legos = new int[n];

            for (int i = 0; i < n; ++i) {
                legos[i] = Integer.parseInt(br.readLine());
            }

            // 오름차순
            Arrays.sort(legos);

            int l = 0, r = n - 1;
            boolean found = false;

            while (l < r) {
                int sum = legos[l] + legos[r];

                if (sum < x) {
                    ++l;
                } else if (sum > x) {
                    --r;
                } else {
                    System.out.println("yes " + legos[l] + " " + legos[r]);
                    found = true;
                    break;
                }
            }

            if (!found) System.out.println("danger");
        }
    }
}
