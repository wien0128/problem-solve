import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

// N번째큰수 2075 PriorityQueue
// 메모리 관리가 관건
// O( N^2 logN )


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        int n = Integer.parseInt(br.readLine());

        // 최소힙
        PriorityQueue<Integer> pq = new PriorityQueue<>(n);

        for (int i = 0; i < n; ++i) {
            st = new StringTokenizer(br.readLine());

            // StringTokenizer 에 유의
            while (st.hasMoreTokens()) {
                int x = Integer.parseInt(st.nextToken());
                pq.offer(x);

                if (pq.size() > n) {
                    pq.poll();
                }
            }
        }

        System.out.println(pq.peek());
    }
}
