import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

// 다이어트 1484 TwoPointer
// x^2 - y^2 = G 를 만족하는 모든 x 를 찾는 문제
// 전체 탐색 상한은 √G + 1 따라서 O(√G)


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int G = Integer.parseInt(br.readLine());
        List<Integer> res = new ArrayList<>();
        int low = 1;
        int high = 1;

        while (low < high || high == 1) {
            long lowSquare = (long) low * low;
            long highSquare = (long) high * high;
            long diff = highSquare - lowSquare;

            if (diff == G) {
                res.add(high);
            }

            if (diff > G) {
                ++low;
            } else {
                ++high;
            }
        }

        if (res.isEmpty()) {
            System.out.println("-1");
        } else {
            for (final int r : res) {
                System.out.println(r);
            }
        }
    }
}
