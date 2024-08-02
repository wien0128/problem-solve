import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;

// 국회의원선거 1417 PriorityQueue
// O( NlogN )


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int dasom = Integer.parseInt(br.readLine());

        //PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        for (int i = 1; i < n; ++i) {
            pq.offer(Integer.parseInt(br.readLine()));
        }

        int res = 0;

        while (!pq.isEmpty() && pq.peek() >= dasom) {
            pq.offer(pq.poll() - 1);
            ++dasom;
            ++res;
        }

        System.out.println(res);
    }
}
