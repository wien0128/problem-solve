import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

// 강의실 1374 PriorityQueue
// O( N logN )


public class Main {
    static class Lecture implements Comparable<Lecture> {
        int start;
        int end;

        Lecture(int start, int end) {
            this.start = start;
            this.end = end;
        }

        @Override
        public int compareTo(Lecture o) {
            // 시작 시간이 같다면
            if (this.start == o.start) {
                // 종료 시간 기준 올므차순
                return this.end - o.end;
            }
            return this.start - o.start;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;

        int n = Integer.parseInt(br.readLine());
        Lecture[] lectures = new Lecture[n];

        for (int i = 0; i < n; ++i) {
            st = new StringTokenizer(br.readLine());
            st.nextToken();
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            lectures[i] = new Lecture(start, end);
        }

        // 강의 시작 시간 기준 오름차순
        Arrays.sort(lectures);

        // 강의 종료 시간 기준 최소 힙
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        pq.add(lectures[0].end);    // 첫 번째 강의 종료 시간 삽입

        for (int i = 1; i < n; ++i) {
            // 기존 강의실을 사용할 수 있는가?
            if (pq.peek() <= lectures[i].start) {
                // 강의실을 비움
                pq.poll();
            }
            pq.add(lectures[i].end);
        }

        // pq 의 크기가 필요한 강의실의 수
        System.out.println(pq.size());
    }
}
