import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 회문 17609 TwoPointer
// 회문과 유사회문을 판별해야 하는 문제


public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        StringBuilder sb = new StringBuilder();
        while (t-- > 0) {
            String s = br.readLine();
            sb.append(isPalindrome(s)).append("\n");
        }

        System.out.println(sb);
    }

    /**
     * 주어진 {@code string}이 회문 또는 유사회문, 둘 다 아닌지 판별 메소드.
     *
     * @param s 판별해야 하는 문자열.
     * @return int 0 회문, 1 유사회문, 2 둘 다 아님.
     */
    public static int isPalindrome(String s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) {
                return (checkSubPalindrome(s, left + 1, right) || checkSubPalindrome(s, left, right - 1)) ? 1 : 2;
            }
            ++left;
            --right;
        }
        return 0;
    }

    /**
     * 부분 {@code string}의 회문 판독 헬퍼 메소드.
     *
     * @param s 부분 문자열.
     * @param l left 포인터.
     * @param r right 포인터.
     * @return boolean 부분 문자열이 회문일 경우 True, 아닐 경우 False.
     */
    private static boolean checkSubPalindrome(String s, int l, int r) {
        while (l < r) {
            if (s.charAt(l) != s.charAt(r)) {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }
}
