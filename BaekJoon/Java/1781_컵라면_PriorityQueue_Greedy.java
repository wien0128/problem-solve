import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 컵라면 1781 PriorityQueue, Greedy
// O( NlogN )


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        int n = Integer.parseInt(br.readLine());

        // { 데드라인, 보상 }
        List<int[]> problems = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            st = new StringTokenizer(br.readLine());
            int deadline = Integer.parseInt(st.nextToken());
            int reward = Integer.parseInt(st.nextToken());
            problems.add(new int[]{deadline, reward});
        }

        // 데드라인 기준 오름차순 정렬
        problems.sort(Comparator.comparingInt(a -> a[0]));
        
        // 최소힙
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        long res = 0;

        // 그리디
        for (int[] p : problems) {
            // 현재 문제를 해결할 수 있다면
            // pq.size() == 현재 데드라인
            if (pq.size() < p[0]) {
                pq.add(p[1]);
                res += p[1];
            }
            // 현재 문제의 보상이 기존 최소 보상보다 크다면
            // 보상이 큰 문제로 대체
            else if (pq.peek() < p[1]) {
                res += p[1] - pq.poll();
                pq.add(p[1]);
            }
        }

        System.out.println(res);
    }
}
