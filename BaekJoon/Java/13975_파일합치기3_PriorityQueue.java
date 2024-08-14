import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

// 파일합치기3 13975 PriorityQueue
// O( N logN )


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            int k = Integer.parseInt(br.readLine());

            PriorityQueue<Long> pq = new PriorityQueue<>(k);

            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < k; ++i) {
                pq.add(Long.parseLong(st.nextToken()));
            }

            long totalCost = 0;
            while (pq.size() > 1) {
                long first = pq.poll();
                long second = pq.poll();

                long merge = first + second;
                totalCost += merge;
                pq.add(merge);
            }

            System.out.println(totalCost);
        }
    }
}
