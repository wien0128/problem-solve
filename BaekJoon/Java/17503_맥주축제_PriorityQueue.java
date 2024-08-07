import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

// 맥주축제 17503 PriorityQueue
// 지문 잘 읽자...
// O( K logK + K logN )


class Bear implements Comparable<Bear> {
    int preference;     // 선호도
    int proof;          // 도수

    Bear(int preference, int proof) {
        this.preference = preference;
        this.proof = proof;
    }

    // 도수 기준 오름차순 비교자
    @Override
    public int compareTo(Bear o) {
        return Integer.compare(this.proof, o.proof);
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        Bear[] bears = new Bear[k]; // 맥주 종류
        for (int i = 0; i < k; ++i) {
            st = new StringTokenizer(br.readLine());
            bears[i] = new Bear(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }

        // 도수 기준 맥주 오름차순
        Arrays.sort(bears);
        
        // 최소 힙
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        // 마신 맥주 선호도의 총 합
        long totalPreference = 0;

        for (Bear bear : bears) {
            pq.offer(bear.preference);  // 현재 맥주 삽입
            totalPreference += bear.preference;

            // n + 1 개의 맥주를 마셨다면
            if (pq.size() > n) {
                // 가장 낮은 선호도의 맥주를 뺌
                totalPreference -= pq.poll();
            }

            // n 개의 맥주를 마시고, 마신 맥주들의 선호도 총 합이 m 이상이라면
            if (pq.size() == n && totalPreference >= m) {
                // 마지막에 마신 맥주의 도수가 정답
                System.out.println(bear.proof);
                return;
            }
        }

        System.out.println(-1);
    }
}
