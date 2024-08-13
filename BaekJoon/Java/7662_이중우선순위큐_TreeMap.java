import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.TreeMap;

// 이중우선순위큐 7662 TreeMap
// 자바의 TreeMap 은 C++ 의 multiset 과 비슷하다.
// O( T * K logN )


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
        StringBuilder sb = new StringBuilder();

        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            int k = Integer.parseInt(br.readLine());

            // 오름차순
            TreeMap<Integer, Integer> map = new TreeMap<>();

            while (k-- > 0) {
                st = new StringTokenizer(br.readLine());

                char cmd = st.nextToken().charAt(0);        // 명령어
                int num = Integer.parseInt(st.nextToken()); // 숫자

                if (cmd == 'I') {   // 추가
                    //map.put(num, map.getOrDefault(num, 0) + 1);
                    map.merge(num, 1, Integer::sum);
                } else if (cmd == 'D') {    // 삭제
                    if (map.isEmpty()) continue;

                    // 최대값 or 최소값 삭제
                    num = (num == 1) ? map.lastKey() : map.firstKey();
                    if (map.get(num) == 1) {
                        map.remove(num);
                    } else {
                        map.merge(num, -1, Integer::sum);
                    }
                }
            }

            if (map.isEmpty()) {
                sb.append("EMPTY\n");
            } else {
                sb.append(map.lastKey()).append(' ').append(map.firstKey()).append('\n');
            }
        }

        System.out.println(sb);
    }
}
