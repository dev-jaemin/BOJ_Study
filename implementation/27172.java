import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.HashSet;
import java.util.StringTokenizer;
import java.util.Collections;

public class Main {

    public void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        ArrayList<Integer> participants = new ArrayList<>();
        HashSet<Integer> participantsSet = new HashSet<>();
        int[] answers = new int[1000001];

        for(int i = 0; i < N; i++){
            int s = Integer.parseInt(st.nextToken());
            participants.add(s);
            participantsSet.add(s);
        }

        // 참가자들 SET 하나 만들고
        int maxValue = participants.get(participants.size() - 1);


        // 제일 작은놈부터 배수 단위로 순회하면서 쳌
        for(int p: participants){
             for(int multiple = 2 * p; multiple <= 1000000; multiple += p){
                if(participantsSet.contains(multiple)){
                    answers[p]++;
                    answers[multiple]--;
                }
            }
        }


        // 정답 출력
        for(int p: participants){
            System.out.print(answers[p] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}

