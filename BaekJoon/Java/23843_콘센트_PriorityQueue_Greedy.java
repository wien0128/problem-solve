import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 콘센트 23843 PriorityQueue + Greedy
// O( N logN )


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        Integer[] times = new Integer[n];
        for (int i = 0; i < n; ++i) {
            times[i] = Integer.parseInt(st.nextToken());
        }

        // 긴 순서대로 내림차순 정렬
        Arrays.sort(times, Collections.reverseOrder());
        
        // 최소 힙
        PriorityQueue<Integer> pq = new PriorityQueue<>(m);
        for (int i = 0; i < m; ++i) {
            pq.add(0);
        }

        int minTime = 0;
        for (int i = 0; i < n; ++i) {
            int cur = pq.poll() + times[i];
            pq.add(cur);

            minTime = Math.max(minTime, cur);
        }

        System.out.println(minTime);
    }
}
