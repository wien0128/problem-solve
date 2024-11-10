import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 빈도정렬 2910 Sorting
// O( n log n )

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());


        Map<Integer, Integer> freq = new HashMap<>();   // {숫자 : 빈도}
        List<int[]> nums = new ArrayList<>();           // {숫자, 등장 인덱스}

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; ++i) {
            int x = Integer.parseInt(st.nextToken());
            // 처음 등장한다면 추가, 아니라면 등장 빈도 증가
            if (freq.put(x, freq.getOrDefault(x, 0) + 1) == null) {
                nums.add(new int[]{x, i});
            }
        }

        // 빈도 기준 내림차순, 빈도가 같다면 등장 인덱스 기준 오름차순
        nums.sort(Comparator.comparingInt((int[] a) -> freq.get(a[0]))
                .reversed()                     // 빈도 기준 내림차순
                .thenComparingInt(a -> a[1]));  // 등장 인덱스 기준 오름차순

        StringBuilder sb = new StringBuilder();
        for (int[] num : nums) {
            // 빈도 수 만큼 정렬된 원소들 출력
            sb.append((num[0] + " ").repeat(freq.get(num[0])));
        }

        System.out.println(sb);
    }
}
