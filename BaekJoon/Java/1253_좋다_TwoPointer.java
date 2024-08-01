import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

// 좋다 1253 TwoPointer
// 두 수의 합이 특정 수가 되는지 찾는 문제
// O( nlogn ) + O( n^2 ) => O( n^2 )


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        int n = Integer.parseInt(br.readLine());

        int[] nums = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; ++i) {
            nums[i] = Integer.parseInt(st.nextToken());
        }

        // 오름차순
        Arrays.sort(nums);

        int cnt = 0;    // GOOD 카운터

        // 타겟 요소 순회 검사
        for (int target = 0; target < n; ++target) {
            int l = 0, r = n - 1;   // 투 포인터

            while (l < r) {
                // 포인터들이 target 과 겹치면 건너뜀
                // 1. 동일 수 중복 선택 방지
                // 2. 다른 인덱스 선택 보장
                if (l == target) { ++l; continue; }
                if (r == target) { --r; continue; }

                // 두 포인터 값의 합
                int sum = nums[l] + nums[r];

                // target 값과 같다면 카운터 증가 후 break
                if (sum == nums[target]) { ++cnt; break; }

                // 위 조건식에 포함되지 않는다면 포인터 조정
                if (sum < nums[target]) {
                    ++l;
                } else {
                    --r;
                }
            }
        }

        System.out.println(cnt);
    }
}
