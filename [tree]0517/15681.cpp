#include <iostream>
#include <vector>

using namespace std;

vector<int> subtree_cnt;

int treeDp(int cur, vector<vector<int>> &graph) {
    if (subtree_cnt[cur] != -1) { //이미 탐색했던 상태
        return subtree_cnt[cur];    //탐색 안 함
    }

    //서브트리에 속한 정점의 수를 세고, 저장
    subtree_cnt[cur] = 0;   //현재 탐색하는 정점 값 0으로 설정
    int node = 1;   //서브트리에 속한 정점의 개수
    for (int i = 0; i < graph[cur].size(); i++) {
        node += treeDp(graph[cur][i], graph);   //갈 수 있는 다음 정점 탐색
    }
    return subtree_cnt[cur] = node; //서브트리에 속한 정점의 개수 반환
}

/**
 * PPT 트리의 정점의 수 구하기 응용
 *
 * [트리와 쿼리]
 *
 * 1. 루트에서부터 dfs 탐색
 * 2. 각 노드를 루트로 하는 서브트리의 정점 수를 재귀적으로 메모리제이션하며 계산
 * - 서브트리에 속한 정점의 개수를 저장하는 dp 배열의 초기화를 -1로 해주고,
 *   dfs 탐색 시 현재 정점의 dp 값을 0으로 설정함으로써 자식 노드만 탐색할 수 있도록 함 (부모 노드에 0이 저장되어 있으므로 바로 리턴)
 *
 */

int main() {
    //입력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //정점의 수, 루트의 번호, 쿼리의 수, 간선의 정보(u와 v를 양 끝점으로 하는 간선), 입력으로 주어지는 U
    int n, r, q, u, v, input;

    //입력
    cin >> n >> r >> q; //정점의 수, 루트의 번호, 쿼리의 수 입력
    vector<vector<int>> graph(n + 1, vector<int>(0));   //그래프 초기화
    subtree_cnt.assign(n + 1, -1);  //서브트리에 속한 정점의 개수 저장하는 배열. -1로 초기화

    while (--n) { //무방향 그래프
        cin >> u >> v;  //간선 정보 입력
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    //연산
    treeDp(r, graph);

    //출력
    while (q--) {   //쿼리의 수만큼 반복
        cin >> input;   //U가 주어짐
        cout << subtree_cnt[input] << '\n'; //input 정점을 루트로 하는 서브트리에 속한 정점의 수 출력
    }
    return 0;
}