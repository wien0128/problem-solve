import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 수열과쿼리15 14427 PriorityQueue
// O( N logN + M logN )


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n]; // 원본 배열

        st = new StringTokenizer(br.readLine());
        // 최소 힙, { 값, 인덱스 }
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) ->
                (a[0] == b[0]) ? a[1] - b[1] : a[0] - b[0]);
      
        for (int i = 0; i < n; ++i) {
            arr[i] = Integer.parseInt(st.nextToken());
            pq.offer(new int[]{arr[i], i + 1}); // 1-based index
        }

        int m = Integer.parseInt(br.readLine());

        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int cmd = Integer.parseInt(st.nextToken());

            // 현재 최소값의 인덱스 출력
            if (cmd == 2) {
                // 최소힙의 최상단 요소가 현재 배열의 값과
                // 일치하지 않으면 poll
                // 최신 상태의 { 값, 인덱스 }를 보장하기 위함
                while (!pq.isEmpty() && pq.peek()[0] != arr[pq.peek()[1] - 1]) {
                    pq.poll();
                }
                System.out.println(pq.peek()[1]);
            }
            // 배열&힙 값 업데이트
            else {
                int idx = Integer.parseInt(st.nextToken());
                int val = Integer.parseInt(st.nextToken());
                arr[idx - 1] = val;
                pq.offer(new int[]{val, idx});
            }
        }
    }
}
