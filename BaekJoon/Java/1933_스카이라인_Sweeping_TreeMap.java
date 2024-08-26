import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 스카이라인 1933 Sweeping, Set
// 끝점 처리가 굉장히 까다롭다
// 코너케이스에 유의
// O( N logN )


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());
        List<int[]> buildings = new ArrayList<>();  // { x 좌표, 높이 }

        for (int i = 0; i < n; ++i) {
            st = new StringTokenizer(br.readLine());
            int L = Integer.parseInt(st.nextToken());
            int H = Integer.parseInt(st.nextToken());
            int R = Integer.parseInt(st.nextToken());
            buildings.add(new int[]{L, -H});    // 시작점
            buildings.add(new int[]{R, H});     // 끝점
        }

        buildings.sort((a, b) -> {
            if (a[0] != b[0]) return a[0] - b[0];
            return a[1] - b[1];
        });

        // 높이 개수 기준 내림차순 트리맵, 높이 상태 관리
        TreeMap<Integer, Integer> heights = new TreeMap<>(Collections.reverseOrder());
        heights.put(0, 1);      // 초기 바닥 설정
        int prevHeight = 0;     // 이전 변환점
        List<int[]> skyline = new ArrayList<>();

        for (int[] b : buildings) {
            if (b[1] < 0) {
                // 시작점은 높이 추가 (양수로 변환)
                heights.merge(-b[1], 1, Integer::sum);
            } else {
                // 끝점이면 해당 높이 제거
                heights.compute(b[1], (k, v) -> {
                    if (v == 1) return null;    // 해당 높이가 없으면 제거
                    return v - 1;               // 해당 높이가 있다면 개수 감소
                });
            }

            // 현재 최대 높이
            int curHeight = heights.isEmpty() ? 0 : heights.firstKey();

            // 높이가 달라졌다면 스카이라인에 추가
            // 모든 높이를 저장할 필요 없음
            // 변환점만 표현하면 충분
            if (curHeight != prevHeight) {
                skyline.add(new int[]{b[0], curHeight});
                prevHeight = curHeight;
            }
        }

        for (int[] s : skyline) {
            sb.append(s[0]).append(" ").append(s[1]).append(" ");
        }
        System.out.print(sb.toString());
    }
}
