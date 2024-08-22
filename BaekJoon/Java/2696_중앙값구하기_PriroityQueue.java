import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 중앙값구하기 2696 PriorityQueue
// 1655번과 같은 아이디어를 공유하는 문제
// 다만, 출력이 조금 까다롭다.
// O( NlogN )


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            int M = Integer.parseInt(br.readLine());

            // 중앙값 저장 리스트
            List<Integer> res = new ArrayList<>((M + 1) / 2);
            // 최대힙, 중앙값 이하 값
            PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);
            // 최소힙, 중앙값 이상 값
            PriorityQueue<Integer> minHeap = new PriorityQueue<>();

            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= M; ++i) {
                if (!st.hasMoreTokens()) {
                    st = new StringTokenizer(br.readLine());
                }
                int num = Integer.parseInt(st.nextToken());

                // 1. maxHeap의 크기는 minHeap의 크기와 같거나 하나 더 크게 유지
                // 2. maxHeap.top()은 minHeap.top()보다 작거나 같게
                // 3. (1), (2)에 위배될 시 max/minHeap.top() 값을 반대로 옮김

                if (maxHeap.isEmpty() || num <= maxHeap.peek()) {
                    maxHeap.add(num);
                } else {
                    minHeap.add(num);
                }

                // 밸런싱
                if (maxHeap.size() > minHeap.size() + 1) {
                    minHeap.add(maxHeap.poll());
                } else if (minHeap.size() > maxHeap.size()) {
                    maxHeap.add(minHeap.poll());
                }

                // 1-based index, 홀수 번째 입력마다 중앙값 저장
                if ((i & 1) == 1) {
                    res.add(maxHeap.peek());
                }
            }

            StringBuilder sb = new StringBuilder();
            sb.append(res.size()).append("\n");
            for (int i = 0; i < res.size(); ++i) {
                if (i > 0 && i % 10 == 0) { // 줄바꿈
                    sb.append("\n");
                }
                sb.append(res.get(i)).append(" ");
            }
            sb.append("\n");
            System.out.print(sb.toString());
        }
    }
}
