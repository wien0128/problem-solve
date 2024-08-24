import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 연료채우기 1826 PriorityQueue, Greedy
// O( NlogN )


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        int n = Integer.parseInt(br.readLine());

        // 주유소 위치와 연료량 2D배열
        // { 위치, 연료량 }
        int[][] stations = new int[n][2];
        for (int i = 0; i < n; ++i) {
            st = new StringTokenizer(br.readLine());
            stations[i][0] = Integer.parseInt(st.nextToken());
            stations[i][1] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        int L = Integer.parseInt(st.nextToken());   // 마을까지 필요한 연료량
        int P = Integer.parseInt(st.nextToken());   // 현재 연료량

        // 주유소 위치 기준 오름차순 정렬
        Arrays.sort(stations, (a, b) -> Integer.compare(a[0], b[0]));

        // 최대 힙
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());

        int cnt = 0;    // 연료 채운 횟수
        int idx = 0;

        while (P < L) {
            // 현재 연료로 도달 가능한 모든 주유소 add
            while (idx < n && stations[idx][0] <= P) {
                maxHeap.add(stations[idx++][1]);
            }

            // 현재 연료로 갈 수 잇는
            // 주유소가 없으면 마을 도착 불가능
            if (maxHeap.isEmpty()) {
                System.out.println(-1);
                return;
            }

            // 가장 많은 연료를 가진 주유소 방문
            P += maxHeap.poll();
            ++cnt;
        }

        System.out.println(cnt);
    }
}
