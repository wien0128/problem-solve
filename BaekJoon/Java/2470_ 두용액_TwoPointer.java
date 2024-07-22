import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

// 두용액 2470 TwoPointer
// 0에 가장 가까운 두 수의 합을 찾는 문제

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] solutions = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; ++i) {
            solutions[i] = Integer.parseInt(st.nextToken());
        }

        // 오름차순
        Arrays.sort(solutions);

        int l = 0, r = n - 1;
        // 두 용액의 합들 중 0에 가장 가까운 값
        int closestSum = Integer.MAX_VALUE;
        // 두 용액의 합이 가장 0에 가까운 용액들
        int sl = 0, sr = 0;

        while (l < r) {
            int curSum = solutions[l] + solutions[r];

            // 현재 합의 절대값이 더 가까운 경우 갱신
            if (Math.abs(curSum) < Math.abs(closestSum)) {
                closestSum = curSum;
                sl = solutions[l];
                sr = solutions[r];
            }
            // 현재 합이 0인 경우 답을 찾았기에 종료
            if (curSum == 0) {
                break;
            }
            // 현재 합이 0보다 작으면 l 포인터를 오른쪽 이동
            if (curSum < 0) {
                ++l;
            // 현재 합이 0보다 크면 r 포인터 왼쪽 이동
            } else {
                --r;
            }
        }

        System.out.println(sl + " " + sr);
    }
}
