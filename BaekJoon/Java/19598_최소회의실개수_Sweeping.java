import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 최소회의실개수 19598 Sweeping
// O( N logN )


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        int n = Integer.parseInt(br.readLine());
        List<int[]> meetings = new ArrayList<>(2 * n);

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            meetings.add(new int[]{s, 1});
            meetings.add(new int[]{e, -1});
        }

        meetings.sort((a, b) -> {
            if (a[0] == b[0]) {
                return a[1] - b[1];
            }
            return a[0] - b[0];
        });

        int minRooms = 0;
        int curRooms = 0;

        for (int[] m : meetings) {
            curRooms += m[1];
            minRooms = Math.max(minRooms, curRooms);
        }

        System.out.println(minRooms);
    }
}
