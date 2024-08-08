import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 강의실 1374 Greedy
// O( N logN )


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        int n = Integer.parseInt(br.readLine());
        List<int[]> lectures = new ArrayList<>();

        for (int i = 0; i < n; ++i) {
            st = new StringTokenizer(br.readLine());
            st.nextToken();
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            lectures.add(new int[]{start, 1});
            lectures.add(new int[]{end, -1});
        }

        // 시간 기준 오름차순 정렬, 같은 시간일 경우 종료 시각으로 정렬
        lectures.sort((a, b) -> a[0] == b[0] ? Integer.compare(a[1], b[1]) : Integer.compare(a[0], b[0]));

        int curRooms = 0;   // 현재 사용 중인 강의실의 수
        int maxRooms = 0;   // 최대로 사용한 강의실의 수
        for (int[] l : lectures) {
            curRooms += l[1];
            maxRooms = Math.max(maxRooms, curRooms);
        }

        System.out.println(maxRooms);
    }
}
