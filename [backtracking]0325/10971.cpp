#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e8;

vector<bool> visited; //방문 검사 배열
vector<vector<int>> matrix; //비용 행렬
int n, ans = INF; //최소 비용 저장 위해 미리 최댓값으로 초기화

/**
 * !생각해보기! 함수의 각 인자는 각각 어떤 역할을 하고 있나요?
 */
 //방문한 도시 개수, 현재 도시 인덱스, 비용
void backtracking(int cnt, int cur_city, int cost) {
    if (cost >= ans) { //생각해보기 : 이 조건문이 없으면 어떻게 될까요?
        return;
    }   //한 도시에서 다른 도시로 가기 위한 비용이 전체 순회에 필요한 최소 비용보다 크면 리턴
        //시간 절약
        //해당 조건문이 없을 시 16ms
    if (cnt == n) { //종료 조건 : n개의 도시를 순회했음
        //출발 도시(0)로 다시 돌아올 수 있는지 확인
        if (matrix[cur_city][0] != 0) {
            ans = min(ans, cost + matrix[cur_city][0]); //최소 비용 구하기
        }
        return;
    }
    for (int i = 0; i < n; i++) { //cur_city에서 도시 i로 이동
        if (matrix[cur_city][i] && !visited[i]) { //길이 있고, 아직 방문하지 않은 도시
            visited[i] = true;  //도시 i 방문
            backtracking(cnt + 1, i, cost + matrix[cur_city][i]);   //다음 도시 방문
            visited[i] = false; //방문 상태 초기화
        }
    }
}

/**
 * 백트래킹 풀이 (4ms)
 *
 * 한 사이클을 만들면, 어느 도시에서 시작하든 값은 같으므로 0번 도시부터 시작하는 경우만 검사하면 된다.
 */

int main() {
    //입력
    cin >> n;
    visited.assign(n, false);   //방문 상태 초기화
    matrix.assign(n, vector<int>(n, 0));    //비용 초기화
    for (int i = 0; i < n; i++) {   //도시i에서 j로가기 위한 비용 입력
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    //연산
    visited[0] = true;  //0번 도시부터 시작
    backtracking(1, 0, 0);

    //출력
    cout << ans;
    return 0;
}