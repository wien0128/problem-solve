import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

// 현대모비스 26091 TwoPointer

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        long m = Long.parseLong(st.nextToken());

        long[] members = new long[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; ++i) {
            members[i] = Long.parseLong(st.nextToken());
        }

        // 오름차순
        Arrays.sort(members);

        int l = 0, r = n - 1;   // 투 포인터
        int teamCnt = 0;        // 차출 가능한 팀 개수

        while (l < r) {
            if (members[l] + members[r] >= m) {
                ++l;
                --r;
                ++teamCnt;
            } else {
                ++l;
            }
        }

        System.out.println(teamCnt);
    }
}
