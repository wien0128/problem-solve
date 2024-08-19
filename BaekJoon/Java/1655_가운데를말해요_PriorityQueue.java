import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 가운데를말해요 1655 PriorityQueue
// 아이디어가 좀 어려운 문제
// O( NlogN )


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 최대 힙, 중간값 이하의 값들
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);
        // 최소 힙, 중간값 이상의 값들
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        int n = Integer.parseInt(br.readLine());

        while (n-- > 0) {
            int x = Integer.parseInt(br.readLine());

            // 1. maxHeap의 크기는 minHeap의 크기와 같거나 하나 더 크게 유지
            // 2. maxHeap.peek()은 minHeap.peek()보다 작거나 같게 유지
            // 3. (1), (2)에 위배될 시 maxHeap/minHeap의 루트 값을 반대로 옮김

            if (maxHeap.isEmpty() || x <= maxHeap.peek()) {
                maxHeap.offer(x);
            } else {
                minHeap.offer(x);
            }

            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.offer(maxHeap.poll());
            } else if (minHeap.size() > maxHeap.size()) {
                maxHeap.offer(minHeap.poll());
            }

            System.out.println(maxHeap.peek());
        }
    }
}
