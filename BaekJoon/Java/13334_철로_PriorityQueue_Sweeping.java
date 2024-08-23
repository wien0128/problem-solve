import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 철로 13334 PriorityQueue, Sweeping
// 전형적인 라인 스위핑 문제
// O( NlogN )


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        int n = Integer.parseInt(br.readLine());
        int[][] lines = new int[n][2];  // { 시점, 종점 }

        for (int i = 0; i < n; ++i) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            // 시점이 항상 종점보다 작게
            lines[i][0] = Math.min(s, e);
            lines[i][1] = Math.max(s, e);
        }

        int d = Integer.parseInt(br.readLine());

        // 종점 기준 오름차순 정렬
        // 종점이 같다면 시점 기준 오름차순 정렬
        Arrays.sort(lines, (a, b) -> a[1] != b[1] ? a[1] - b[1] : a[0] - b[0]);

        // 최소힙, 현재 철로에 포함되는 시점 관리
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int maxCnt = 0; // 철로에 포함된 라인의 개수

        // 스위핑
        for (int[] line : lines) {
            pq.add(line[0]);    // 현재 구간 시점을 add
            // 철로 길이에 포함되지 않는 시점 제거
            while (!pq.isEmpty() && pq.peek() < line[1] - d) {
                pq.poll();
            }
            maxCnt = Math.max(maxCnt, pq.size());
        }

        System.out.println(maxCnt);
    }
}
