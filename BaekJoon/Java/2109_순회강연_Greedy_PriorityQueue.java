import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 순회강연 2109 PriorityQueue, Greedy, Align
// 13904번과 매우 유사한 문제
// O( N logN )


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        if (n == 0) {
            System.out.println(0);
            return;
        }

        List<int[]> lectures = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            st = new StringTokenizer(br.readLine());
            int p = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            lectures.add(new int[]{p, d});
        }

        // 강연일 기준 내림차순, 같은 강연일이면 강연료 기준 내림차순 정렬
        lectures.sort((a, b) -> b[1] != a[1] ? b[1] - a[1] : b[0] - a[0]);

        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        int totalPay = 0;
        int idx = 0;

        for (int day = lectures.get(0)[1]; day > 0; --day) {
            while (idx < n && lectures.get(idx)[1] >= day) {
                pq.add(lectures.get(idx++)[0]);
            }
            if (!pq.isEmpty()) {
                totalPay += pq.poll();
            }
        }

        System.out.println(totalPay);
    }
}
