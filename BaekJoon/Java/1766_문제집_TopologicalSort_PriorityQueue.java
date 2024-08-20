import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 문제집 1766 TopologicalSort, PriorityQueue
// Kahn's Algorithm 이용
// 연결 리스트를 활용하면 TimeComplexity 더 낮출 수도?
// O( (N + M)logN ) = O( (V + E)logV )


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        // 쉬운(번호가 작은) 문제 최소 힙
        // 진입 차수가 0인 문제들만 add
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        // 문제 별 진입 차수 배열
        int[] inDegree = new int[n + 1];
        // 문제 간의 관계 그래프 2D리스트
        List<Integer>[] graph = new ArrayList[n + 1];

        // 그래프 초기화
        for (int i = 0; i <= n; ++i) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; ++i) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            graph[x].add(y);    // x -> y
            ++inDegree[y];      // 문제 y 진입 차수 증가
        }

        // 진입 차수가 0인 모든 문제 pq.add
        for (int i = 1; i <= n; ++i) {
            if (inDegree[i] == 0) {
                pq.add(i);
            }
        }

        // 위상 정렬
        while (!pq.isEmpty()) {
            int cur = pq.poll();
            sb.append(cur).append(' '); // 현재 푼 문제 append

            // 현재 문제 해결 후, 연결된 문제들 진입 차수 감소
            for (int next : graph[cur]) {
                if (--inDegree[next] == 0) {
                    pq.add(next);
                }
            }
        }

        System.out.println(sb.toString().trim());
    }
}
