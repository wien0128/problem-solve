import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

// 문제추천시스템 21939 PriorityQueue
// O( NlogN + MlogN )


public class Main {
    static class Problem implements Comparable<Problem> {
        int diff;
        int id;

        public Problem(int diff, int id) {
            this.diff = diff;
            this.id = id;
        }

        @Override
        public int compareTo(Problem o) {
            if (this.diff == o.diff) {
                return this.id - o.id; // 난이도가 같으면 id 기준 오름차순
            }
            return this.diff - o.diff; // 난이도 기준 오름차순
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());

        // 최소 힙, 난이도 기준
        PriorityQueue<Problem> minHeap = new PriorityQueue<>();
        // 최대 힙, 난이도 기준
        PriorityQueue<Problem> maxHeap = new PriorityQueue<>((a, b) -> {
            if (a.diff == b.diff) {
                return b.id - a.id;
            }
            return b.diff - a.diff;
        });

        Map<Integer, Integer> problems = new HashMap<>();

        for (int i = 0; i < n; ++i) {
            st = new StringTokenizer(br.readLine());
            int id = Integer.parseInt(st.nextToken());
            int diff = Integer.parseInt(st.nextToken());
            addProblem(id, diff, minHeap, maxHeap, problems);
        }

        int m = Integer.parseInt(br.readLine());

        for (int i = 0; i < m; ++i) {
            st = new StringTokenizer(br.readLine());
            String cmd = st.nextToken();

            switch (cmd) {
                case "add":
                    int id = Integer.parseInt(st.nextToken());
                    int diff = Integer.parseInt(st.nextToken());
                    addProblem(id, diff, minHeap, maxHeap, problems);
                    break;
                case "recommend":
                    int x = Integer.parseInt(st.nextToken());
                    sb.append(recommendProblem(x, minHeap, maxHeap, problems)).append("\n");
                    break;
                case "solved":
                    int solvedId = Integer.parseInt(st.nextToken());
                    problems.remove(solvedId);
                    break;
            }
        }

        System.out.println(sb.toString());
    }

    private static void addProblem(int id, int diff, PriorityQueue<Problem> minHeap, PriorityQueue<Problem> maxHeap, Map<Integer, Integer> problems) {
        Problem problem = new Problem(diff, id);
        minHeap.offer(problem);
        maxHeap.offer(problem);
        problems.put(id, diff);
    }

    private static int recommendProblem(int x, PriorityQueue<Problem> minHeap, PriorityQueue<Problem> maxHeap, Map<Integer, Integer> problems) {
        PriorityQueue<Problem> q = (x == 1) ? maxHeap : minHeap;

        while (!q.isEmpty()) {
            Problem top = q.peek();
            Integer diff = problems.get(top.id);
            if (diff != null && diff == top.diff) {
                return top.id;
            }
            q.poll();  // 유효하지 않은 항목은 제거
        }
        return -1; // 모든 항목이 유효하지 않을 때 반환할 값
    }
}
