import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

// 카드합체놀이 15903 PriorityQueue
// 그리디하게 생각하면 쉽다, 자료형 주의
// O( (n + m)logn )


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        // 최소 힙
        PriorityQueue<Long> cards = new PriorityQueue<>();
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; ++i) {
            cards.add(Long.parseLong(st.nextToken()));
        }

        // m 번 x + y 수행
        for (int i = 0; i < m; ++i) {
            long x = cards.poll();
            long y = cards.poll();

            long newCard = x + y;
            cards.add(newCard);
            cards.add(newCard);
        }
        
        long sum = 0;   // 최종 카드들의 합
        while (!cards.isEmpty()) {
            sum += cards.poll();
        }

        System.out.println(sum);
    }
}
