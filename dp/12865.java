import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    // W, V input
    ArrayList<Integer> weights;
    ArrayList<Integer> values;
    int N, K;

    void solution() throws Exception {
        // N, K input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        weights = new ArrayList<>();
        values = new ArrayList<>();

        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());

            weights.add(Integer.parseInt(st.nextToken()));
            values.add(Integer.parseInt(st.nextToken()));
        }

        int[][] dp = new int[N + 1][K + 1];

        // dp[n][w] : n개의 아이템을 사용(하거나 말거나), 고려하는 무게는 w일 때(꼭 정확히 w 아니어도 됌)의 최대 값
        dp[0][0] = 0;
        dp[1][0] = 0;
        dp[1][weights.get(0)] = weights.get(0) <= K ? values.get(0) : 0;

        for(int i = 2; i <= N; i++){
            for(int w = 0; w <= K; w++){
                dp[i][w] = dp[i - 1][w];

                if(w >= weights.get(i - 1)){
                    dp[i][w] = Math.max(dp[i][w], dp[i - 1][w - weights.get(i - 1)] + values.get(i - 1));
                }                
            }
        }

        System.out.println(dp[N][K]);
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}