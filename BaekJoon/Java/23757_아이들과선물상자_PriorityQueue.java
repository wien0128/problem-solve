import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

// 아이들과선물상자 23757 PriorityQueue
// O( NlogN + MlogN )


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        // 선물 상자들 속 선물의 개수 최대 힙
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; ++i) {
            pq.add(Integer.parseInt(st.nextToken()));
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; ++i) {
            // 원하는 선물 개수
            int needs = Integer.parseInt(st.nextToken());

            // 선물이 없거나, 최대 선물 보유 상자가 니즈 보다 작다면
            if (pq.peek() < needs) {
                System.out.println(0);
                return;
            }

            // 남은 선물 개수 삽입
            pq.add(pq.poll() - needs);
        }

        System.out.println(1);
    }
}
