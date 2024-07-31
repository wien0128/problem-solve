import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 두개의탑 2118 TwoPointer
// O( n + 2n ) = O( n )


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        int n = Integer.parseInt(br.readLine());

        int[] dist = new int[2 * n];    // 원형 배열 거리값
        int totalSum = 0;               // 총 거리 합
        for (int i = 0; i < n; ++i) {
            st = new StringTokenizer(br.readLine());
            dist[i] = Integer.parseInt(st.nextToken());
            totalSum += dist[i];
            dist[i + n] = dist[i];
        }

        int sum = 0;        // 포인터 사이 거리 합
        int maxDist = 0;    // 최대 거리

        // 투 포인터
        for (int l = 0, r = 0; l < n; ++l) {
            // 포인터 사이의 거리가 반원(전체 거리의 절반)일 때까지
            while (sum * 2 < totalSum) {
                sum += dist[r++];
            }
            // 최대 거리 갱신: max(현재 최대 거리, 포인터 사이 거리)
            maxDist = Math.max(maxDist, Math.min(sum, totalSum - sum));
            sum -= dist[l];
        }

        System.out.println(maxDist);
    }
}
