import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 과제 13904 PriorityQueue, Greedy, Align
// O( N logN )


public class Main {
    static class Assignment {
        int deadline;
        int score;

        Assignment(int deadline, int score) {
            this.deadline = deadline;
            this.score = score;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());

        List<Assignment> assignments = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            st = new StringTokenizer(br.readLine());
            int deadline = Integer.parseInt(st.nextToken());
            int score = Integer.parseInt(st.nextToken());
            assignments.add(new Assignment(deadline, score));
        }

        // 마감일 기준 오름차순 정렬
        assignments.sort((a, b) -> a.deadline - b.deadline);

        // 점수 기준 최대 힙
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());
        int totalScore = 0;
        int idx = n - 1;

        for (int day = assignments.get(assignments.size() - 1).deadline; day > 0; --day) {
            while (idx >= 0 && assignments.get(idx).deadline >= day) {
                maxHeap.add(assignments.get(idx).score);
                --idx;
            }
            if (!maxHeap.isEmpty()) {
                totalScore += maxHeap.poll();
            }
        }

        System.out.println(totalScore);
    }
}
