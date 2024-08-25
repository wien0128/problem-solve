import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 소수의곱 2014 PriorityQueue
// 중복 계산과 저장을 방지하는 게 핵심
// O( N * K * logM)


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int k = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());

        // 최소 힙
        PriorityQueue<Long> pq = new PriorityQueue<>();
        long[] primes = new long[k];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < k; i++) {
            primes[i] = Long.parseLong(st.nextToken());
            pq.offer(primes[i]);
        }

        long cur = 0;
        while (n-- > 0) {
            cur = pq.poll();

            for (long p : primes) {
                // 오버플로우 방지
                if (cur > Long.MAX_VALUE / p) break;

                long next = cur * p;
                pq.offer(next);

                // 중복 계산 방지
                // 나누어 떨어진다면 이미 계산한 값
                if (cur % p == 0) break;
            }
        }

        System.out.println(cur);
    }
}
