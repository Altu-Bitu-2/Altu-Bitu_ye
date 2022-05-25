#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;

//주어진 정점을 지웠을 때의 리프 노드의 수
int eraseLeafCnt(int node, int &erase_node) {
    if (node == erase_node) {   //해당 노드가 지워지는 노드
        return 0;
    }
    //해당 노드의 자식이 없음 = 리프 노드임
    //지우는 노드가 해당 부모 노드의 유일한 자식 노드였을 경우(자식 노드 수가 1개 && (자식 노드 == 지우려는 노드))
    //해당 노드를 지우면 부모 노드가 리프 노드가 돼서 개수가 1 증가함
    if (tree[node].empty() || (tree[node].size() == 1 && tree[node][0] == erase_node)) {
        return 1;   //리프 노드 1 증가
    }
    int cnt = 0;    //리프 노드의 개수
    for (int i = 0; i < tree[node].size(); i++) {   //해당 노드의 자식 노드 개수만큼 반복
        cnt += eraseLeafCnt(tree[node][i], erase_node); //리프 노드의 개수 계산
    }
    return cnt; //리프 노드의 개수 반환
}

/**
 * [트리]
 *
 * 기존 리프 노드 개수를 세는 dfs 탐색에서 지우는 정점을 만나면 더 이상 탐색하지 않고 0을 리턴
 *
 * !주의! 지우는 정점이 해당 부모 노드의 유일한 자식 노드였을 경우, 해당 정점을 지우면 부모 노드가 리프 노드가 돼서 개수가 1 증가함을 주의
 * !주의! 루트 노드가 항상 0이 아님을 주의
 */

int main() {
    int n, par, root, erase_node;   //노드의 개수, 노드의 부모, 루트 노드, 지울 노드의 번호

    //입력
    cin >> n;   //노드의 개수 입력
    tree.assign(n, vector<int>(0)); //트리 값 초기화
    for (int i = 0; i < n; i++) {   //노드의 개수만큼 반복
        cin >> par; //노드의 부모 입력
        if (par == -1) {    //부모가 없으면 루트(-1)
            root = i;   //루트 노드 인덱스 저장
            continue;
        }
        tree[par].push_back(i); //노드의 부모 인덱스에 해당 노드 저장
    }
    cin >> erase_node;  //지울 노드의 번호 입력

    //연산 & 출력
    cout << eraseLeafCnt(root, erase_node);
    return 0;
}