import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 크면서작은수 2992 BackTracking
// 다음 순열을 찾으면 된다...
// O( N * N! )


public class Main {
    static char[] num;       // x 의 char[] 형
    static int x, n;            // 입력 받은 수, x 자릿수
    static int result = Integer.MAX_VALUE;  // 결과 순열
    static boolean[] isUsed;      // 각 자릿수 사용 여부

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        x = Integer.parseInt(br.readLine());
        num = String.valueOf(x).toCharArray();
        n = num.length;  // 숫자 자릿수 계산
        isUsed = new boolean[n];

        DFS(0, 0);

        System.out.println(result == Integer.MAX_VALUE ? 0 : result);
    }

    private static void DFS(int depth, int cur) {
        if (depth == n) {  // 모든 자릿수를 사용했다면 (순열을 만들었다면)
            if (cur > x) {  // 현재 순열이 입력값보다 크다면
                result = Math.min(result, cur);
            }
            return;
        }

        // 모든 자릿수에 대해 순열 생성
        for (int i = 0; i < n; i++) {
            if (!isUsed[i]) {
                isUsed[i] = true;
                //   깊이 증가, 자릿수 증가 후 숫자 추가
                DFS(depth + 1, cur * 10 + (num[i] - '0'));
                isUsed[i] = false;  // 백트래킹
            }
        }
    }
}
