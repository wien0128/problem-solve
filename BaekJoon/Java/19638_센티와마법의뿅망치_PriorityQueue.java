import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

// 센티와마법의뿅망치 19638 PriorityQueue
// O( (N + T)logN )


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int h = Integer.parseInt(st.nextToken());
        int t = Integer.parseInt(st.nextToken());

        // 거인들의 키 최대 힙
        PriorityQueue<Integer> giants = new PriorityQueue<>((a, b) -> b - a);
        for (int i = 0; i < n; ++i) {
            giants.add(Integer.parseInt(br.readLine()));
        }

        int hammerCnt = 0;  // 뿅망치 사용한 횟수
        // 뿅망치 사용 가능 횟수 && 가장 큰 거인의 키가 센티의 키보다 크거나 같을 때까지
        while (t-- > 0 && giants.peek() >= h) {
            int tallest = giants.poll();
            // 키가 1인 경우 그대로 삽입
            if (tallest == 1) {
                giants.add(1);
            } else {
                // 가장 큰 거인의 키를 절반 후 삽입
                giants.add(tallest / 2);
            }
            // 뿅망치 사용한 횟수 증가
            ++hammerCnt;
        }

        // 모든 거인의 키가 h 보다 작다면
        if (giants.peek() < h) {
            System.out.println("YES");
            System.out.println(hammerCnt);
        } else {
            System.out.println("NO");
            System.out.println(giants.peek());
        }
    }
}
