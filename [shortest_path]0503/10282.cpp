#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e7; //최대 n-1개의 연결관계 있으므로 -> n * (가중치 최대값)

//다익스트라
ci dijkstra(int start, int v, vector<vector<ci>> &graph) {
    priority_queue<ci, vector<ci>, greater<>> pq;
    vector<int> dist(v + 1, INF);

    //시작 정점(해킹 당한 컴퓨터 번호) 초기화
    dist[start] = 0;
    pq.push({0, start});
    int cnt = 0, t = 0; //총 감염되는 컴퓨터 수, 마지막 컴퓨터가 감염되기까지 걸리는 시간
    while (!pq.empty()) {
        int weight = pq.top().first;    //현재 정점(컴퓨터) 감염되기까지의 시간
        int node = pq.top().second;     //현재 탐색하려는 정점(컴퓨터)
        pq.pop();

        if (weight > dist[node]) {  //이미 더 짧은 시간으로 저장된 정점은 넘어가기
            continue;
        }
        cnt++;  //감염된 컴퓨터 수 증가
        t = weight; //컴퓨터 감염되기까지의 시간 저장
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first;   //연결된 정점(의존하는 컴퓨터)
            //처음 감염된 컴퓨터로부터 현재 컴퓨터를 거쳐 다음 컴퓨터까지 가는 경로값(걸리는 시간)
            int next_weight = weight + graph[node][i].second;
            if (next_weight < dist[next_node]) {    //더 짧은 시간 갱신
                dist[next_node] = next_weight;
                pq.push({next_weight, next_node});
            }
        }
    }
    return {cnt, t};    //출력값 리턴
}

/**
 * [해킹]
 *
 * - 기본적인 다익스트라 문제
 * - 다익스트라 내에서 이미 더 짧은 경로가 존재하는 정점은 탐색에서 배제하면서, 탐색하는 정점의 수와 마지막 시간을 저장
 *
 * !주의! 그래프 생성 시, a가 b를 의존한다는 건 b 감염 후 a가 감염된다는 뜻이므로 b -> a 방향임
 */

int main() {
    //테스트 케이스 개수, 컴퓨터 개수, 의존성 개수, 해킹당한 컴퓨터의 번호
    //의존성을 나타내는 정수
    //컴퓨터 a가 b를 의존. 컴퓨터 b가 감염되면 s초 후 a도 감염
    int t, n, d, c, a, b, s;

    //입력
    cin >> t;
    while (t--) {
        cin >> n >> d >> c;
        vector<vector<ci>> graph(n + 1, vector<ci>(0)); //방향 그래프
        while (d--) {
            cin >> a >> b >> s;
            graph[b].push_back({a, s}); // b->a 방향
        }

        //연산
        ci ans = dijkstra(c, n, graph);

        //출력
        cout << ans.first << ' ' << ans.second << '\n';
    }
    return 0;
}