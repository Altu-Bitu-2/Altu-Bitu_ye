#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e5 * 8 * 3; //최대 N-1개의 간선을 지나게 됨 * 중복 순회 가능(3)

//다익스트라
vector<int> dijkstra(int start, int v, vector<vector<ci>> &graph) {
    vector<int> dist(v + 1, INF);   //각 정점까지의 최단 경로
    priority_queue<ci, vector<ci>, greater<>> pq;   //현재 탐색하는 중간 정점까지의 최단 경로

    //시작 정점 초기화
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int weight = pq.top().first;    //현재 정점까지의 경로값
        int node = pq.top().second;     //현재 탐색하려는 정점
        pq.pop();

        if (weight > dist[node]) {  //이미 더 작은 값으로 기록된 정점은 넘어감
            continue;
        }
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first;   //연결된 정점
            //시작점으로부터 현재 노드를 거쳐 다음 정점까지 가는 경로값
            int next_weight = weight + graph[node][i].second;
            if (next_weight < dist[next_node]) {    //최단 경로 값이 갱신된다면
                dist[next_node] = next_weight;
                pq.push({next_weight, next_node});
            }
        }
    }
    return dist;    //최단 경로 리턴
}

/**
 * [특정한 최단 경로]
 *
 * 가능한 경로
 * 1. 1 -> v1 -> v2 -> n
 * 2. 1 -> v2 -> v1 -> n
 * -> 1, v1, v2를 시작점으로 하는 다익스트라 함수 실행하기
 *
 * !주의! 한 번 이동했던 정점, 간선을 다시 방문할 수 있음. 즉 1->N의 최댓값이 INF(1e5*8)이 아니라 3*INF!
 */

int main() {
    //정점의 개수, 간선의 개수
    //a번 정점에서 b번 정점까지 양방향 길 존재. 거리는 c
    //반드시 거쳐야 하는 정점 번호 2개
    int n, e, a, b, c, v1, v2;

    //입력
    cin >> n >> e;

    vector<vector<ci>> graph(n + 1, vector<ci>(0));
    vector<vector<int>> dist(3, vector<int>(n + 1, 0));
    while (e--) { //무방향 그래프
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }
    cin >> v1 >> v2;

    //연산
    vector<int> start_nodes = {1, v1, v2};
    for (int i = 0; i < 3; i++) { //1, v1, v2에서 시작한 다익스트라 결과 저장
        dist[i] = dijkstra(start_nodes[i], n, graph);
    }

    //1->v1->v2->n의 경로와 1->v2->v1->n의 경로 중 최솟값
    //무방향 그래프기 때문에 v1->v2와 v2->v1은 사실 같은 값!
    int ans = min(dist[0][v1] + dist[1][v2] + dist[2][n], dist[0][v2] + dist[2][v1] + dist[1][n]);

    //출력
    cout << ((ans >= INF) ? -1 : ans);
    return 0;
}