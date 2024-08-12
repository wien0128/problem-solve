import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 크리스마스선물 14235 PriorityQueue
// O( N logM )


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        int n = Integer.parseInt(br.readLine());

        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);

        for (int i = 0; i < n; ++i) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());

            if (a == 0) {   // 아이들을 만났다면
                if (pq.isEmpty()) { // 줄 선물이 있다면
                    System.out.println("-1");
                } else {
                    System.out.println(pq.poll());
                }
            } else {    // 거점지에서 선물 충전
                for (int j = 0; j < a; ++j) {
                    pq.add(Integer.parseInt(st.nextToken()));
                }
            }
        }
    }
}
