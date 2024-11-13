import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 파일정리 20291 Sorting. Parsing
// O( n + k log k )

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        // {확장자, 등장 빈도}
        // key 값을 기준으로 자동 정렬되기에 TreeMap 사용
        TreeMap<String, Integer> extCnt = new TreeMap<>();

        for (int i = 0; i < n; ++i) {
            // '.' 이후의 문자열 파싱 (정규표현식이기에 \\. 으로 온점 타겟팅)
            String ext = br.readLine().split("\\.")[1];
            // 현재 확장자와 빈도 삽입, 이미 존재한다면 빈도 +1
            extCnt.put(ext, extCnt.getOrDefault(ext, 0) + 1);
        }

        StringBuilder sb = new StringBuilder();
        // "확장자 빈도" 형태로 만든 후 한 번에 출력
        extCnt.forEach((k, v) -> sb.append(k)
                                .append(' ')
                                .append(v)
                                .append('\n'));

        System.out.println(sb);
    }
}
