import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 부등호 2529 BackTracking
// 0~9 순열을 조건에 맞게 탐색하는 문제
// O( 10! )


public class Main {
    static int k;
    static char[] signs;
    static boolean[] isUsed = new boolean[10];
    static String minNum = "9876543210";
    static String maxNum = "0";

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        k = Integer.parseInt(br.readLine());
        signs = br.readLine().replace(" ", "").toCharArray();

        dfs(0, new StringBuilder());

        System.out.println(maxNum + "\n" + minNum);
    }

    static boolean isValid(char a, char b, char sign) {
        return (sign == '<') ? (a < b) : (a > b);
    }

    static void dfs(int depth, StringBuilder num) {
        if (depth == k + 1) {
            String curNum = num.toString();
            if (curNum.compareTo(minNum) < 0) {
                minNum = curNum;
            }
            if (curNum.compareTo(maxNum) > 0) {
                maxNum = curNum;
            }
            return;
        }

        for (int i = 0; i <= 9; ++i) {
            if (!isUsed[i] && (depth == 0 || isValid(num.charAt(depth - 1), (char)(i + '0'), signs[depth - 1]))) {
                isUsed[i] = true;
                num.append(i);

                dfs(depth + 1, num);

                num.deleteCharAt(depth);
                isUsed[i] = false;
            }
        }
    }
}
