import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 귀여운라이언 15565 TwoPointer
// 라이언 인형(1)이 K개 이상 있는 가장 작은
// 연속된 인형(1, 2)들의 집합의 크기 구하기

public class Solve {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tk = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(tk.nextToken());
        int k = Integer.parseInt(tk.nextToken());
        int[] dolls = new int[n];

        tk = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            dolls[i] = Integer.parseInt(tk.nextToken());
        }

        int l = 0, r = 0;   // 투 포인터
        int lionCnt = 0;    // 라이언 인형의 개수
        // 라이언 인형을 K개 이상 가진 가장 작은 연속 집합의 크기
        int minLen = Integer.MAX_VALUE;

        // 슬라이딩 윈도우
        while (r < n) {
            // 현재 포인터 r이 라이언 인형이라면
            if (dolls[r++] == 1) {
                // 개수 증가 후 포인터 r 오른쪽 이동
                ++lionCnt;
            }

            // 라이언 인형의 개수가 K개 이상이라면
            while (lionCnt >= k) {
                // 최소 집합의 크기 갱신
                minLen = Math.min(minLen, r - l);
                // 현재 포인터 l이 라이언 인형이라면
                if (dolls[l++] == 1) {
                    // 개수 감소 후 포인터 l 오른쪽 이동
                    --lionCnt;
                }
            }
        }

        System.out.println(minLen == Integer.MAX_VALUE ? -1 : minLen);
    }
}
