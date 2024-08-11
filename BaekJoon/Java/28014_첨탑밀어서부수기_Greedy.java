import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 첨탑밀어서부수기 28014 Greedy
// O( N )


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        int n = Integer.parseInt(br.readLine());

        st = new StringTokenizer(br.readLine());

        int prevHeight = Integer.parseInt(st.nextToken());
        int cnt = 1;
        for (int i = 1; i < n; ++i) {
            int curHeight = Integer.parseInt(st.nextToken());
            if (curHeight >= prevHeight) {
                ++cnt;
            }
            prevHeight = curHeight;
        }

        System.out.println(cnt);
    }
}
