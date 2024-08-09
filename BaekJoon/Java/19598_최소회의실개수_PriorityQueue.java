import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 최소회의실개수 19598 PriorityQueue
// O( N logN )


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        int n = Integer.parseInt(br.readLine());
        int[][] meetings = new int[n][2];

        for (int i = 0; i < n; ++i) {
            st = new StringTokenizer(br.readLine());
            meetings[i][0] = Integer.parseInt(st.nextToken());  // 시작 시간
            meetings[i][1] = Integer.parseInt(st.nextToken());  // 종료 시간
        }

        // 시작 시간 기준 오름차순 정렬
        Arrays.sort(meetings, Comparator.comparingInt(a -> a[0]));

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        pq.add(meetings[0][1]); // 첫 번째 회의 종료 시간 삽입

        int minRooms = 1;
        for (int i = 1; i < n; ++i) {
            if (pq.peek() <= meetings[i][0]) {
                pq.poll();
            }
            pq.add(meetings[i][1]);
            minRooms = Math.max(minRooms, pq.size());
        }

        System.out.println(minRooms);
    }
}
