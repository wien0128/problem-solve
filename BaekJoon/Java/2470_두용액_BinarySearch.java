import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

// 두용액 2470 BinarySearch
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

        int minSum = Math.abs(solutions[0] + solutions[1]);
        int s1 = solutions[0], s2 = solutions[1];

        for (int i = 0; i < n - 1; ++i) {
            int l = solutions[i];
            int target = -l;    // 두 번째 용액 목표 값

            // target 보다 크거나 같은 첫 번째 용액 찾기
            int idx = Arrays.binarySearch(solutions, i + 1, n, target);

            // 값을 찾지 못한 경우 처리
            if (idx < 0) {
                idx = -idx - 1;
            }

            // 이전 용액과의 합 비교
            if (idx - 1 > i) {
                int prev = solutions[idx - 1];  // 목표 값 바로 이전의 용액
                int sum = l + prev;
                if (Math.abs(sum) < minSum) {
                    minSum = Math.abs(sum);
                    s1 = l;
                    s2 = prev;
                }
            }

            // 현재 용액과의 합 비교
            if (idx < n) {
                int curr = solutions[idx];  // 목표 값에 가장 가까운 용액
                int sum = l + curr;
                if (Math.abs(sum) < minSum) {
                    minSum = Math.abs(sum);
                    s1 = l;
                    s2 = curr;
                }
            }
        }

        System.out.println(s1 + " " + s2);
    }
}
