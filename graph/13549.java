import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;
import java.util.PriorityQueue;

// public class 로 선언하려면, 파일명과 이름이 같아야 함
class Node {
    public int id;
    public int distance;

    public Node(int id, int distance){
        this.id = id;
        this.distance = distance;
    }
}

// 다익스트라 알고리즘 사용
// 한 지점에서 다른 지점까지의 최단 거리를 찾아야 할 때 사용. (간선이 모두 양수이어야 함)
// 시작 지점에서 순회 시작. 이때 사용하는 큐는 priority queue(가중치가 작은 노드부터 보아야 하므로)
// 기존 최단거리 vs 새로 계산한 최단거리 비교해보고, 만약 업데이트가 필요하다면 필요한 노드를 pq에 넣음(그래야 그 뒤 노드들에 대해서 다시 계산 가능하므로)
// 목표 지점 도달 시 종료
public class Main {
    final int INF = 9999999;
    
    void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int subinIndex = Integer.parseInt(st.nextToken());
        int brotherIndex = Integer.parseInt(st.nextToken());
        PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> a.distance - b.distance);
        int[] distances = new int[100001];
        int answer = INF;

        for(int i = 0; i < 100001; i++){
            distances[i] = INF;
        }
        distances[subinIndex] = 0;
        pq.offer(new Node(subinIndex, 0));

        // 종료 도달 반복문 추가
        while(!pq.isEmpty()){
            Node current = pq.poll();

            if(current.id == brotherIndex){
                answer = current.distance;
                break;
            }

            int left = current.id - 1;
            int right = current.id + 1;
            int teleport = current.id * 2;

            if(left >= 0 && distances[current.id] + 1 < distances[left] ){
                distances[left] = distances[current.id] + 1;
                pq.offer(new Node(left, distances[left]));
            }

            if(right <= 100000 && distances[current.id] + 1 < distances[right] ){
                distances[right] = distances[current.id] + 1;
                pq.offer(new Node(right, distances[right]));
            }

            if(teleport <= 100000 && distances[current.id] < distances[teleport] ){
                distances[teleport] = distances[current.id];
                pq.offer(new Node(teleport, distances[teleport]));
            }
        }

        System.out.println(answer);
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}